#include <plot.hpp>
#include <simulation.hpp>

#include <matplot/matplot.h>

#include <string>

void plot(simulation_results results, double expected_result, std::string file)
{
    matplot::scatter(results.result.x, results.result.y)->marker(".").marker_size(0.5).color("blue");
    matplot::hold(matplot::on);
    matplot::scatter(results.avg_result.x, results.avg_result.y)->marker(".").marker_size(2).color("red");
    matplot::plot({50, 5000}, {expected_result, expected_result})->line_width(2).color("green");
    matplot::hold(matplot::off);

    matplot::save(file);
}