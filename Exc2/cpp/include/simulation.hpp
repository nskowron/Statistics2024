#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <axis.hpp>

struct simulation_results
{
    axis<int> B;
    axis<int> avg_B;

    axis<int> U;
    axis<int> avg_U;

    axis<int> C;
    axis<int> avg_C;

    axis<int> D;
    axis<int> avg_D;
};

simulation_results simulate_balls_and_bins(int tries);

#endif