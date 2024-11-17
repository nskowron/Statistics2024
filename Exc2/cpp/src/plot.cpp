#include <plot.hpp>
#include <simulation.hpp>
#include <axis.hpp>

#include <matplot/matplot.h>

#include <string>
#include <vector>

void plot(axis<double> result, axis<double> avg_result, std::string file)
{
    std::vector<double> result_x(result.x.begin(), result.x.end());
    std::vector<double> result_y(result.y.begin(), result.y.end());

    matplot::scatter(result.x, result.y)->marker(".").marker_size(0.5).color("blue");
    matplot::hold(matplot::on);
    matplot::plot(avg_result.x, avg_result.y)->line_width(2).color("red");
    matplot::hold(matplot::off);

    matplot::save(file);
}