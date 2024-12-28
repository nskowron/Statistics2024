#include <stations.hpp>

#include <iostream>


std::uniform_real_distribution<double> simulation_receiver::dist(0, 1);

simulation_receiver::simulation_receiver(double p) :
    p(p),
    rng(std::random_device()())
{}

bool simulation_receiver::receive()
{
    return dist(rng) <= p;
}

simulation_broadcaster::simulation_broadcaster(int n, double p) :
    non_received(n),
    receivers(n, simulation_receiver(p)),
    results{0, {n, 0}}
{
    std::cout << results.Tn.size();
}

bool simulation_broadcaster::broadcast()
{
    ++results.T;

    for(int i = 0; i < receivers.size(); ++i)
    {
        if(results.Tn.at(i) == 0 && receivers.at(i).receive())
        {
            --non_received;
            results.Tn.at(i) = results.T;
        }
    }

    return non_received == 0;
}