#include <plot.hpp>
#include <simulation.hpp>
#include <axis.hpp>

#include <matplot/matplot.h>

#include <string>
#include <vector>

template<typename T>
void plot(axis<T> result, axis<T> avg_result, std::string file)
{
    std::vector<double> result_x(result.x.begin(), result.x.end());
    std::vector<double> result_y(result.y.begin(), result.y.end());

    std::vector<double> avg_result_x(avg_result.x.begin(), avg_result.x.end());
    std::vector<double> avg_result_y(avg_result.y.begin(), avg_result.y.end());

    matplot::scatter(result_x, result_y)->marker(".").marker_size(0.5).color("blue");
    matplot::hold(matplot::on);
    matplot::plot(avg_result_x, avg_result_y)->line_width(2).color("red");
    matplot::hold(matplot::off);

    matplot::save(file);
}