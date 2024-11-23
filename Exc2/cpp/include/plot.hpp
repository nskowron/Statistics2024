#ifndef PLOT_HPP
#define PLOT_HPP

#include <simulation.hpp>

#include <string>

void plot(axis<double> result, axis<double> avg_result, std::string file);
void plot_line(axis<double> result, std::string file);

#endif