#include <simulation.hpp>
#include <plot.hpp>
#include <stations.hpp>

#include <string>
#include <algorithm>
#include <cmath>

void process_results(full_simulation_results& results, const std::string& file_base);

int main()
{
    {
        std::string file_base = std::string(OUTPUT_DIRECTORY) + "Plot_5_";
        full_simulation_results results = full_simulate_broadcast(50, 0.5);
        process_results(results, file_base);
    }

    {
        std::string file_base = std::string(OUTPUT_DIRECTORY) + "Plot_1_";
        full_simulation_results results = full_simulate_broadcast(50, 0.1);
        process_results(results, file_base);
    }
}

void process_results(full_simulation_results& results, const std::string& file_base)
{
    plot(results.T, results.avg_T, file_base + "T.pdf");

    //plot(results.Tn.at(0), results.avg_Tn.at(0), file_base + "")
    // { // c) cmp(n)/n
    //     axis<double> result;
    //     result.x = results.avg_cmp.x;
    //     std::transform(
    //         results.avg_cmp.y.begin(),
    //         results.avg_cmp.y.end(),
    //         results.avg_cmp.x.begin(),
    //         std::back_inserter(result.y),
    //         [](auto& c, auto& n){return c / n;}
    //     );

    //     plot_line(result, file_base + "c)-1.pdf");
    // }
}
