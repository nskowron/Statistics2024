#include <simulation.hpp>
#include <stations.hpp>

#include <vector>
#include <random>
#include <set>
#include <algorithm>

#include <iostream>


void single_simulate_broadcast(Broadcaster& broadcaster)
{
    while(!broadcaster.broadcast()) {}
}

full_simulation_results full_simulate_broadcast(int tries, double p)
{
    full_simulation_results results;

    for(int n = 100; n <= 10000; n += 100)
    {
        for(int k = 1; k <= tries; ++k)
        {
            Broadcaster broadcaster(n, p);

            single_simulate_broadcast(broadcaster);

            results.add(n, broadcaster.results);
        }
        std::cout << n << "\n";
    }
    results.calculate_avg(tries);

    return results;
}

void full_simulation_results::add(int n, const single_simulation_results& result)
{
    Tn.x.push_back(n);
    Tn1.x.push_back(n);

    Tn.y.push_back(result.Tn);
    Tn1.y.push_back(result.Tni.at(0));
}

void full_simulation_results::calculate_avg(int tries)
{
    for(int i = 0; i < Tn.x.size(); i += tries)
    {
        int sum = std::accumulate(Tn.y.begin() + i, Tn.y.begin() + i + tries, 0);

        avg_Tn.x.push_back(Tn.x.at(i));
        avg_Tn.y.push_back(sum / (double)tries);


        sum = std::accumulate(Tn1.y.begin() + i, Tn1.y.begin() + i + tries, 0);

        avg_Tn1.x.push_back(Tn1.x.at(i));
        avg_Tn1.y.push_back(sum / (double)tries);
    }
}
