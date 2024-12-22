#include <simulation.hpp>

#include <vector>
#include <random>
#include <set>
#include <algorithm>

#include <iostream>

int get_index_ballanced(std::uniform_int_distribution<int>& dist,
                        std::mt19937& rng,
                        const std::vector<int>& bins,
                        int d)
{
    std::set<int> unique_index;
    while(unique_index.size() < d)
    {
        unique_index.insert(dist(rng));
    }

    auto min_index = std::min_element(unique_index.begin(), unique_index.end(),
        [bins](auto a, auto b){ return bins.at(a) < bins.at(b); });

    return *min_index;
}

single_simulation_results single_simulate_ballanced(int n, int d)
{
    single_simulation_results results{ 0, 0, 0, 0 };

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> bin(0, n - 1);

    std::vector<int> bins(n, 0);
    int m = 0;

    {
        int have_one = 0;
        int have_two = 0;

        int index;

        for(int i = 0; i < n; ++i)
        {
            index = get_index_ballanced(bin, rng, bins, d);
            ++m;

            if(bins.at(index) == 0)
            {
                ++have_one;
            }
            else if(bins.at(index) == 1)
            {
                if(results.B == 0)
                {
                    results.B = m;
                }
                ++have_two;
            }

            ++bins.at(index);
        }
        results.U = n - have_one;

        results.L = *std::max_element(bins.begin(), bins.end());

        if(results.B == 0)
        {
            results.B = m + 1;
        }
        
        while(have_one < n)
        {
            index = get_index_ballanced(bin, rng, bins, d);
            ++m;

            if(bins.at(index) == 0)
            {
                ++have_one;
            }
            else if(bins.at(index) == 1)
            {
                ++have_two;
            }

            ++bins.at(index);
        }
        results.C = m;

        while(have_two < n)
        {
            index = get_index_ballanced(bin, rng, bins, d);
            ++m;

            if(bins.at(index) == 1)
            {
                ++have_two;
            }

            ++bins.at(index);
        }
        results.D = m;
    }

    return results;
}

full_simulation_results full_simulate_ballanced(int tries, int d)
{
    full_simulation_results results;

    for(int n = 1000; n <= 100000; n += 1000)
    {
        for(int k = 1; k <= tries; ++k)
        {
            const single_simulation_results sim = single_simulate_ballanced(n, d);

            results.add(n, sim);
        }
        std::cout << n << std::endl;
    }
    results.calculate_avg(tries);

    return results;
}

void full_simulation_results::add(int n, const single_simulation_results& result)
{
    B.x.push_back(n);
    U.x.push_back(n);
    C.x.push_back(n);
    D.x.push_back(n);
    L.x.push_back(n);

    B.y.push_back(result.B);
    U.y.push_back(result.U);
    C.y.push_back(result.C);
    D.y.push_back(result.D);
    L.y.push_back(result.L);
}

void full_simulation_results::calculate_avg(int tries)
{
    for(int i = 0; i < B.x.size(); i += tries)
    {
        int sum = std::accumulate(B.y.begin() + i, B.y.begin() + i + tries, 0);

        avg_B.x.push_back(B.x.at(i));
        avg_B.y.push_back(sum / (double)tries);


        sum = std::accumulate(U.y.begin() + i, U.y.begin() + i + tries, 0);

        avg_U.x.push_back(U.x.at(i));
        avg_U.y.push_back(sum / (double)tries);


        sum = std::accumulate(C.y.begin() + i, C.y.begin() + i + tries, 0);

        avg_C.x.push_back(C.x.at(i));
        avg_C.y.push_back(sum / (double)tries);


        sum = std::accumulate(D.y.begin() + i, D.y.begin() + i + tries, 0);

        avg_D.x.push_back(D.x.at(i));
        avg_D.y.push_back(sum / (double)tries);


        sum = std::accumulate(L.y.begin() + i, L.y.begin() + i + tries, 0);

        avg_L.x.push_back(L.x.at(i));
        avg_L.y.push_back(sum / (double)tries);
    }
}
