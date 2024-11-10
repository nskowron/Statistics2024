#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>

struct function_simulation
{
    struct limit
    {
        double left;
        double right;
    };

    double (*f)(double);
    limit limit;
    double max;
};

struct simulation_results
{
    struct axis
    {
        std::vector<double> x;
        std::vector<double> y;
    };

    axis result;
    axis avg_result;
};

#endif