#include <plot.hpp>
#include <simulation.hpp>

#include <matplot/matplot.h>

#include <string>

void plot(simulation_results results, std::string file)
{
    matplot::scatter(results.result.x, results.result.y)->marker(".").marker_size(0.5).color("blue");
    matplot::hold(matplot::on);
    matplot::plot(results.avg_result.x, results.avg_result.y)->line_width(2).color("red");
    matplot::hold(matplot::off);

    matplot::save(file);
}