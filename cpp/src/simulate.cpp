#include <simulate.hpp>
#include <approx.hpp>

#include <matplot/matplot.h>
#include <vector>
#include <utility>
#include <cmath>

void simulate_function(double (*f)(double x), std::pair<double, double> x_lim, double y_max, int tries, double real_integral, std::string file)
{
    std::vector<double> x(0);
    std::vector<double> y(0);

    std::vector<double> x_avg(0);
    std::vector<double> y_avg(0);

    for(int n = 50; n <= 5000; n += 50)
    {
        double avg = 0;
        for(int k = 1; k <= tries; ++k)
        {
            double approx = approx_integral(f, x_lim, y_max, n);

            avg += approx;
            x.push_back(n);
            y.push_back(approx);
        }
        avg /= tries;
        x_avg.push_back(n);
        y_avg.push_back(avg);
    }

    matplot::scatter(x, y)->marker(".").marker_size(0.5).color("blue");
    matplot::hold(matplot::on);
    matplot::scatter(x_avg, y_avg)->marker(".").marker_size(2).color("red");
    matplot::plot({50, 5000}, {real_integral, real_integral})->line_width(2).color("green");
    matplot::hold(matplot::off);

    matplot::save(file);
}

void simulate_pi(int tries, std::string file)
{
    std::vector<double> x(0);
    std::vector<double> y(0);

    std::vector<double> x_avg(0);
    std::vector<double> y_avg(0);

    for(int n = 50; n <= 5000; n += 50)
    {
        double avg = 0;
        for(int k = 1; k <= tries; ++k)
        {
            double approx = approx_pi(n);

            avg += approx;
            x.push_back(n);
            y.push_back(approx);
        }
        avg /= tries;
        x_avg.push_back(n);
        y_avg.push_back(avg);
    }

    matplot::scatter(x, y)->marker(".").marker_size(0.5).color("blue");
    matplot::hold(matplot::on);
    matplot::scatter(x_avg, y_avg)->marker(".").marker_size(2).color("red");
    matplot::plot({50, 5000}, {M_PI, M_PI})->line_width(2).color("green");
    matplot::hold(matplot::off);

    matplot::save(file);
}