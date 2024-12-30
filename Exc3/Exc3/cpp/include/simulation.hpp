#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <axis.hpp>


struct single_simulation_results
{
    int Tn;                 //round
    std::vector<int> Tni;   //min round for each receiver
};

struct full_simulation_results
{
    axis<int> Tn;
    axis<double> avg_Tn;

    axis<int> Tn1;           //min round for receiver 1
    axis<double> avg_Tn1;

    void add(int n, const single_simulation_results& result);
    
    void calculate_avg(int tries);
};

class Broadcaster;
void single_simulate_broadcast(Broadcaster& broadcaster);

full_simulation_results full_simulate_broadcast(int tries, double p);

#endif