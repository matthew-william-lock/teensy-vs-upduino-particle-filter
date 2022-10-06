
#ifndef MOTIONMODEL_H
#define MOTIONMODEL_H

#include <geometry_msgs/msg/pose.h>
#include <nav_msgs/msg/odometry.h>

#include <math.h>
#include <random>
#include <tuple>

#include "quat.hpp"
#include "FastRNG.hpp"

#include "../config/motion_model.h"

#define MOVED_TOO_CLOSE 0.01

class MotionModel
{
private:

public:

    MotionModel();

    // Sample motion model to predict particle movement
    static geometry_msgs__msg__Pose sampleMotionModel(
        geometry_msgs__msg__Pose previous_xt,
        geometry_msgs__msg__Pose latestOdom,
        geometry_msgs__msg__Pose prevOdom
    );

    static std::tuple<double, double, double> getPoseDelta(
        geometry_msgs__msg__Pose xt,
        geometry_msgs__msg__Pose previous_xt
    );

};

#endif