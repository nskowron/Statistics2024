#include <simulation.hpp>
#include <plot.hpp>
#include <stations.hpp>

#include <string>
#include <algorithm>
#include <cmath>

void process_results(full_simulation_results& results, const std::string& file_base, double p);

int main()
{
    {
        double p = 0.5;
        std::string file_base = std::string(OUTPUT_DIRECTORY) + "Plot_5_";
        full_simulation_results results = full_simulate_broadcast(50, p);
        process_results(results, file_base, p);
    }

    {
        double p = 0.1;
        std::string file_base = std::string(OUTPUT_DIRECTORY) + "Plot_1_";
        full_simulation_results results = full_simulate_broadcast(50, p);
        process_results(results, file_base, p);
    }
}

void process_results(full_simulation_results& results, const std::string& file_base, double p)
{
    plot(results.T, results.avg_T, file_base + "T.pdf");
    plot(results.Tn, results.avg_Tn, file_base + "Tn.pdf");

    { // test) T(n)/(ln n / -ln(1-p))
        axis<double> result;
        result.x = results.avg_T.x;
        std::transform(
            results.avg_T.y.begin(),
            results.avg_T.y.end(),
            results.avg_T.x.begin(),
            std::back_inserter(result.y),
            [p](auto& t, auto& n){return t / (log(n) / -log(1-p));}
        );

        plot_line(result, file_base + "test)-1.pdf");
    }
}
