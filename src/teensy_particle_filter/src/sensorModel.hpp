
#ifndef SENSORMODEL_H
#define SENSORMODEL_H

#include <Arduino.h>

#include <tuple>
#include <geometry_msgs/msg/pose.h>
#include <nav_msgs/msg/odometry.h>
#include <sensor_msgs/msg/laser_scan.h>

#include <math.h>
#include <random>
#include <stdio.h>

#include "quat.hpp"

#include "../config/sensor_model.h"
#include "../config/map_conf.h"
#include "../include/map_array.h"

// Struct called "SimplePose" that contains the x, y, and theta of a particle
struct SimplePose
{
    double x;
    double y;
    double theta;
};

class SensorModel
{
private:
    std::vector<std::tuple<double, double>> map_obstacles;
public:
    SensorModel();
    SensorModel(std::vector<std::tuple<double, double>> map_obstacles);

    // Sample motion model to predict particle movement
    double sampleSensorModel(
        geometry_msgs__msg__Pose particlePose,
        sensor_msgs__msg__LaserScan laserScan,
        void (*callback)(const char*)
    );

    static SimplePose calculateMapPose(geometry_msgs__msg__Pose particlePose);

    double closestObstacle(
        double x,
        double y,
        void (*callback)(const char*)
    );

    static double calculateProbability(double range,void (*printDebug)(const char*));

};

#endif
