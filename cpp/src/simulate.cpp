#include <simulate.hpp>

#include <matplot/matplot.h>
#include <vector>

void simulate()
{
    std::vector<double> x2 = {1, 2, 3, 4, 5};
    std::vector<double> y2 = {25, 16, 9, 4, 1};
    matplot::plot(x2, y2)->line_width(2).color("red");
    matplot::title("Example Plot");
}