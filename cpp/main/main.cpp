#include <functions.hpp>
#include <approx.hpp>
#include <simulate.hpp>

#include <matplot/matplot.h>

int main(void)
{
    matplot::subplot(2, 1, 1);
    simulate();
    matplot::subplot(2, 1, 2);
    simulate();
    matplot::save(std::string(OUTPUT_DIRECTORY) + "example_plot.pdf");
}