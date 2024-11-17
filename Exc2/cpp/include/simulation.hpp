#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <axis.hpp>

struct single_simulation_results
{
    int B;  // first collision
    int U;  // empty bins after n balls
    int C;  // all bins have one ball
    int D;  // all bins have two balls
};

struct full_simulation_results
{
    axis<int> B;
    axis<double> avg_B;

    axis<int> U;
    axis<double> avg_U;

    axis<int> C;
    axis<double> avg_C;

    axis<int> D;
    axis<double> avg_D;

    void add(int n, const single_simulation_results& result);
    
    void calculate_avg(int tries);
};

single_simulation_results single_simulate(int n);

full_simulation_results full_simulate(int tries);

#endif