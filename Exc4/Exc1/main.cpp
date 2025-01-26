#include <iostream>
#include <boost/math/distributions/binomial.hpp>
#include <boost/math/distributions/geometric.hpp>

int main(void)
{
    for(int n : {100, 1000, 10000})
    {
        std::cout << "n: " << n << std::endl;

        boost::math::binomial X(n, 0.5);
        double E = boost::math::mean(X);
        { // a
            double P = 1 - boost::math::cdf(X, (6.0 / 5.0) * E - 1);
            std::cout << "a) " << P << std::endl;
        }
        { // b
            double P = 2 * (1 - boost::math::cdf(X, (11.0 / 10.0) * E - 1));
            std::cout << "b) " << P << std::endl;
        }
    }
}