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
    plot(results.Tn, results.avg_Tn, file_base + "Tn.pdf");
    plot(results.Tn1, results.avg_Tn1, file_base + "Tn1.pdf");

    { // Tn asym) T(n)/(ln n / -ln(1-p))
        axis<double> result;
        result.x = results.avg_Tn.x;
        std::transform(
            results.avg_Tn.y.begin(),
            results.avg_Tn.y.end(),
            results.avg_Tn.x.begin(),
            std::back_inserter(result.y),
            [p](auto& t, auto& n){return t / (log(n) / -log(1-p));}
        );

        plot_line(result, file_base + "Tn_asym)-1.pdf");
    }

    { // PMF of Tni
        axis<int> val_count;
        
        val_count.y.resize(3 * (1/p), 0); //3 times expected value should be enough
        for(auto val : results.Tn1.y)
        {
            if(val <= val_count.y.size())
            {
                ++val_count.y.at(val - 1);
            }
        }

        val_count.x.resize(3 * (1/p), 0);
        for(int i = 0; i < val_count.x.size(); ++i)
        {
            val_count.x.at(i) = i + 1;
        }

        plot_line(val_count, file_base + "Tni_PMF.pdf");
    }
}
