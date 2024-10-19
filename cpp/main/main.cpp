#include <functions.hpp>

#include <iostream>
#include <matplot/matplot.h>

int main(void)
{
    // Create sample data
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {1, 4, 9, 16, 25};

    // Create a plot
    matplot::plot(x, y);
    matplot::save(std::string(OUTPUT_DIRECTORY) + "example_plot.pdf");

    std::cout << "Hello World!";
}