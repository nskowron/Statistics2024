#include <simulation.hpp>

#include <matplot/matplot.h>
#include <vector>

simulation_results simulate_balls_and_bins(int tries)
{
    simulation_results results;

    for(int n = 1000; n <= 100000; n += 1000)
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
