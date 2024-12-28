#include <simulation.hpp>
#include <stations.hpp>

#include <vector>
#include <random>
#include <set>
#include <algorithm>

#include <iostream>


void single_simulate_broadcast(Broadcaster& broadcaster)
{
    while(!broadcaster.broadcast())
    {}
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
        std::cout << n << std::endl;
    }
    results.calculate_avg(tries);

    return results;
}

void full_simulation_results::add(int n, const single_simulation_results& result)
{
    T.x.push_back(n);
    T.y.push_back(result.T);

    // for(int i = 0; i < Tn.size(); ++i)
    // {
    //     Tn.at(i).x.push_back(n);
    //     Tn.at(i).y.push_back(result.Tn.at(i));
    // }
}

void full_simulation_results::calculate_avg(int tries)
{
    for(int i = 0; i < T.x.size(); i += tries)
    {
        int sum = std::accumulate(T.y.begin() + i, T.y.begin() + i + tries, 0);

        avg_T.x.push_back(T.x.at(i));
        avg_T.y.push_back(sum / (double)tries);

        // for(int j = 0; j < Tn.size(); ++j)
        // {
        //     int sum = std::accumulate(Tn.at(j).y.begin() + i, Tn.at(j).y.begin() + i + tries, 0);

        //     avg_Tn.at(j).x.push_back(Tn.at(j).x.at(i));
        //     avg_Tn.at(j).y.push_back(sum / (double)tries);
        // }
    }
}
