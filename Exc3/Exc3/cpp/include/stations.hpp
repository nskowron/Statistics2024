#ifndef STATIONS_HPP
#define STATIONS_HPP

#include <simulation.hpp>

#include <vector>
#include <random>


class simulation_receiver
{
private:
    static std::uniform_real_distribution<double> dist;
    std::mt19937 rng;
    double p;

public:
    simulation_receiver(double p);

    bool receive();
};

class simulation_broadcaster
{
private:
    std::vector<simulation_receiver> receivers;

    int non_received;

public:
    single_simulation_results results;

public:
    simulation_broadcaster(int n, double p);

    bool broadcast();
};

#endif