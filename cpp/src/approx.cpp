#include <approx.hpp>

#include <random>

double approx_integral(double (*f)(double), std::pair<double, double> x_lim, std::pair<double, double> y_lim, int points)
{
    double total_area = (x_lim.second - x_lim.first) * (y_lim.second - y_lim.first);

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> x_dist(x_lim.first, x_lim.second);
    std::uniform_real_distribution<double> y_dist(y_lim.first, y_lim.second);

    int points_in_area = 0;
    for(int i = 0; i < points; ++i)
    {
        double x = x_dist(rng);
        double y = y_dist(rng);

        if(y <= f(x))
        {
            ++points_in_area;
        }
    }

    return (points_in_area / points) * total_area;
}