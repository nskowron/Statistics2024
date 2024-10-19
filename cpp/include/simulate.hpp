#ifndef SIMULATE_HPP
#define SIMULATE_HPP

#include <string>
#include <utility>

void simulate_function(double (*f)(double), std::pair<double, double> x_lim, double y_max, int tries, double real_integral, std::string file);
void simulate_pi(int tries, std::string file);

#endif