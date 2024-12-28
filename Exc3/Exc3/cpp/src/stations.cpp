#include <stations.hpp>


std::uniform_real_distribution<double> Receiver::dist(0, 1);

Receiver::Receiver(double p) :
    p(p),
    rng(std::random_device()())
{}

bool Receiver::receive()
{
    return dist(rng) <= p;
}


Broadcaster::Broadcaster(int n, double p) :
    non_received(n),
    receivers(n, Receiver(p)),
    results{0, std::vector<int>(n, 0)}
{}

bool Broadcaster::broadcast()
{
    ++results.T;

    for(int i = 0; i < receivers.size(); ++i)
    {
        if(results.Tn.at(i) == 0 && receivers.at(i).receive())
        {
            --non_received;
            results.Tn.at(i) = results.T;
        }
    }

    return non_received == 0;
}