#include <simulate.hpp>
#include <approx.hpp>

#include <matplot/matplot.h>
#include <vector>

simulation_results simulate_function(function_simulation sim, int tries)
{
    simulation_results results;

    for(int n = 50; n <= 5000; n += 50)
    {
        double avg = 0;
        for(int k = 1; k <= tries; ++k)
        {
            double approx = approx_integral(sim, n);

            avg += approx;
            results.result.x.push_back(n);
            results.result.y.push_back(approx);
        }
        avg /= tries;
        results.avg_result.x.push_back(n);
        results.avg_result.y.push_back(avg);
    }

    return results;
}

simulation_results simulate_pi(int tries)
{
    simulation_results results;

    for(int n = 50; n <= 5000; n += 50)
    {
        double avg = 0;
        for(int k = 1; k <= tries; ++k)
        {
            double approx = approx_pi(n);

            avg += approx;
            results.result.x.push_back(n);
            results.result.y.push_back(approx);
        }
        avg /= tries;
        results.avg_result.x.push_back(n);
        results.avg_result.y.push_back(avg);
    }

    return results;
}