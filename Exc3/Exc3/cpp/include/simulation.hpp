#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <axis.hpp>
#include <stations.hpp>

struct single_simulation_results
{
    int T;                  //round
    std::vector<int> Tn;    //min round for each receiver
};

struct full_simulation_results
{
    axis<int> T;
    axis<double> avg_T;

    void add(int n, const single_simulation_results& result);
    
    void calculate_avg(int tries);
};

void single_simulate_broadcast(simulation_broadcaster& broadcaster);

full_simulation_results full_simulate_sort(int tries);

#endif