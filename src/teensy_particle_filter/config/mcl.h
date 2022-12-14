// Monte Carlo Particle Filter Config

#ifndef MCL_H
#define MCL_H

#define USE_HARDWARE_ACCELERATION 1
#define experiment 2
#define debug 0

// Set number of particles depending on the experiment
#if debug ==1
#define NUM_OF_PARTICLES 1
#elif experiment == 1
#define NUM_OF_PARTICLES 128
#elif experiment == 2
#define NUM_OF_PARTICLES 256
#elif experiment == 3
#define NUM_OF_PARTICLES 512
#endif

// If experiment -1 is chosen, the number of particles is set to 0
#if experiment == -1
#define NUM_OF_PARTICLES 0
#endif

#define adaptive false
#define likelihood_model true
// #define epsilon 0.1
#define upper_quantile 3
#define min_number_of_particles 50
#define max_number_of_particles 1000

#endif