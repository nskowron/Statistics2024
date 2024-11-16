#include <simulation.hpp>

#include <matplot/matplot.h>
#include <vector>

single_simulation_results single_simulate(int n)
{
    single_simulation_results results;

    

    return results;
}

full_simulation_results full_simulate(int tries)
{
    full_simulation_results results;

    for(int n = 1000; n <= 100000; n += 1000)
    {
        single_simulation_results avg{ 0, 0, 0, 0 };

        for(int k = 1; k <= tries; ++k)
        {
            single_simulation_results sim = single_simulate(n);

            avg.B += sim.B;
            avg.U += sim.U;
            avg.C += sim.C;
            avg.D += sim.D;

            results.add(n, sim);
        }
        avg.B /= tries;
        avg.U /= tries;
        avg.C /= tries;
        avg.D /= tries;

        results.add_avg(n, avg);
    }

    return results;
}

void full_simulation_results::add(int n, const single_simulation_results& result)
{
    B.x.push_back(n);
    U.x.push_back(n);
    C.x.push_back(n);
    D.x.push_back(n);

    B.y.push_back(result.B);
    U.y.push_back(result.U);
    C.y.push_back(result.C);
    D.y.push_back(result.D);
}

void full_simulation_results::add_avg(int n, const single_simulation_results& result)
{
    avg_B.x.push_back(n);
    avg_U.x.push_back(n);
    avg_C.x.push_back(n);
    avg_D.x.push_back(n);

    avg_B.y.push_back(result.B);
    avg_U.y.push_back(result.U);
    avg_C.y.push_back(result.C);
    avg_D.y.push_back(result.D);
}
