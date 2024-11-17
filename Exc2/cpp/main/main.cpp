#include <simulation.hpp>
#include <plot.hpp>

#include <string>

int main()
{
    std::string file_base = std::string(OUTPUT_DIRECTORY) + "Plot";

    full_simulation_results results = full_simulate(50);

    plot(results.B, results.avg_B, file_base + "B.pdf");
    plot(results.U, results.avg_U, file_base + "U.pdf");
    plot(results.C, results.avg_C, file_base + "C.pdf");
    plot(results.D, results.avg_D, file_base + "D.pdf");
}
