#include <plot.hpp>
#include <simulation.hpp>
#include <axis.hpp>

#include <matplot/matplot.h>

#include <string>
#include <vector>

void plot(axis<double> result, axis<double> avg_result, std::string file)
{
    auto y_lim = matplot::gca()->y2lim();
    y_lim.at(0) = 0;
    matplot::ylim(y_lim);

    matplot::scatter(result.x, result.y)->marker(".").marker_size(0.5).color("blue");
    matplot::hold(matplot::on);
    matplot::plot(avg_result.x, avg_result.y)->line_width(2).color("red");
    matplot::hold(matplot::off);

    matplot::save(file);
}

void plot_line(axis<double> result, std::string file)
{
    auto y_lim = matplot::gca()->y2lim();
    y_lim.at(0) = 0;
    matplot::ylim(y_lim);

    matplot::plot(result.x, result.y)->line_width(2).color("red");

    matplot::save(file);
}