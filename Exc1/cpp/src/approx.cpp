#include <approx.hpp>
#include <simulation.hpp>

#include <random>

double approx_integral(function_simulation sim, int points)
{
    double total_area = (sim.limit.right - sim.limit.left) * (sim.max);

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> x_dist(sim.limit.left, sim.limit.right);
    std::uniform_real_distribution<double> y_dist(0, sim.max);

    int points_in_area = 0;
    for(int i = 0; i < points; ++i)
    {
        double x = x_dist(rng);
        double y = y_dist(rng);

        if(y <= sim.f(x))
        {
            ++points_in_area;
        }
    }

    return ((double)points_in_area / points) * total_area;
}

double approx_pi(int points)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> x_dist(-1, 1);
    std::uniform_real_distribution<double> y_dist(-1, 1);

    int points_in_area = 0;
    for(int i = 0; i < points; ++i)
    {
        double x = x_dist(rng);
        double y = y_dist(rng);

        if(x * x + y * y <= 1)
        {
            ++points_in_area;
        }
    }

    return ((double)points_in_area / points) * 4;
}