#ifndef APPROX_HPP
#define APPROX_HPP

#include <utility>

double approx_integral(double (*f)(double), std::pair<double, double> x_lim, double y_max, int points);
double approx_pi(int points);

#endif