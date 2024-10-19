#include <functions.hpp>
#include <approx.hpp>
#include <simulate.hpp>

#include <matplot/matplot.h>
#include <string>
#include <utility>
#include <cmath>

int main(void)
{
    simulate_function(f, std::make_pair<double, double>(0, 8), 2.0, 5, 12.0, std::string(OUTPUT_DIRECTORY) + "Plot1-1.pdf");
    simulate_function(f, std::make_pair<double, double>(0, 8), 2.0, 50, 12.0, std::string(OUTPUT_DIRECTORY) + "Plot1-2.pdf");
    simulate_function(g, std::make_pair<double, double>(0, M_PI), 1.0, 5, 2.0, std::string(OUTPUT_DIRECTORY) + "Plot2-1.pdf");
    simulate_function(g, std::make_pair<double, double>(0, M_PI), 1.0, 50, 2.0, std::string(OUTPUT_DIRECTORY) + "Plot2-2.pdf");
    simulate_function(h, std::make_pair<double, double>(0, 1), 27.0 / 64.0, 5, 0.2, std::string(OUTPUT_DIRECTORY) + "Plot3-1.pdf");
    simulate_function(h, std::make_pair<double, double>(0, 1), 27.0 / 64.0, 50, 0.2, std::string(OUTPUT_DIRECTORY) + "Plot3-2.pdf");

    simulate_pi(5, std::string(OUTPUT_DIRECTORY) + "Plot4-1.pdf");
    simulate_pi(50, std::string(OUTPUT_DIRECTORY) + "Plot4-2.pdf");
}