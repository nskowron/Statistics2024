#include <functions.hpp>
#include <simulate.hpp>
#include <plot.hpp>
#include <simulation.hpp>

#include <string>
#include <cmath>

#include <chrono>
#include <iostream>

int main(void)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    std::string basic_filename = std::string(OUTPUT_DIRECTORY) + "Plot";

    {
        function_simulation sim;
        sim.f = f;
        sim.limit.left = 0.0;
        sim.limit.right = 8.0;
        sim.max = 2.0;

        plot(simulate_function(sim, 5), 12.0, basic_filename + "1-1.pdf");
        plot(simulate_function(sim, 50), 12.0, basic_filename + "1-2.pdf");
    }

    {
        function_simulation sim;
        sim.f = g;
        sim.limit.left = 0.0;
        sim.limit.right = M_PI;
        sim.max = 1.0;

        plot(simulate_function(sim, 5), 2.0, basic_filename + "2-1.pdf");
        plot(simulate_function(sim, 50), 2.0, basic_filename + "2-2.pdf");
    }

    {
        function_simulation sim;
        sim.f = h;
        sim.limit.left = 0.0;
        sim.limit.right = 1.0;
        sim.max = 27.0 / 64.0;

        plot(simulate_function(sim, 5), 0.2, basic_filename + "3-1.pdf");
        plot(simulate_function(sim, 50), 0.2, basic_filename + "3-2.pdf");
    }

    {
        plot(simulate_pi(5), M_PI, basic_filename + "4-1.pdf");
        plot(simulate_pi(50), M_PI, basic_filename + "4-2.pdf");
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Execution time: " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << " seconds" << std::endl;
}