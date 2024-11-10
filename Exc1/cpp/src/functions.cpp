#include <cmath>

double f(double x)
{
    return std::pow(x, 1.0 / 3.0);
}

double g(double x)
{
    return std::sin(x);
}

double h(double x)
{
    return 4 * x * std::pow(1 - x, 3);
}