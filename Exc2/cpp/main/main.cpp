#include <simulation.hpp>
#include <plot.hpp>

#include <string>
#include <algorithm>
#include <cmath>

int main()
{
    std::string file_base = std::string(OUTPUT_DIRECTORY) + "Plot_";

    full_simulation_results results = full_simulate(50);

    axis<int> D_C;
    D_C.x = results.D.x;
    std::transform(
        results.D.y.begin(),
        results.D.y.end(),
        results.C.y.begin(),
        std::back_inserter(D_C.y),
        [](auto& d, auto& c){return d - c;}
    );

    axis<double> avg_D_C;
    avg_D_C.x = results.avg_D.x;
    std::transform(
        results.avg_D.y.begin(),
        results.avg_D.y.end(),
        results.avg_C.y.begin(),
        std::back_inserter(avg_D_C.y),
        [](auto& d, auto& c){return d - c;}
    ); 

    plot(results.B, results.avg_B, file_base + "B.pdf");
    plot(results.U, results.avg_U, file_base + "U.pdf");
    plot(results.C, results.avg_C, file_base + "C.pdf");
    plot(results.D, results.avg_D, file_base + "D.pdf");
    plot(D_C, avg_D_C, file_base + "D-C.pdf");

    { // a) b(n)/n
        axis<double> result;
        result.x = results.avg_B.x;
        std::transform(
            results.avg_B.y.begin(),
            results.avg_B.y.end(),
            results.avg_B.x.begin(),
            std::back_inserter(result.y),
            [](auto& b, auto& n){return b / n;}
        );

        plot_line(result, file_base + "a)-1.pdf");
    }

    { // a) b(n)sqrt(n)
        axis<double> result;
        result.x = results.avg_B.x;
        std::transform(
            results.avg_B.y.begin(),
            results.avg_B.y.end(),
            results.avg_B.x.begin(),
            std::back_inserter(result.y),
            [](auto& b, auto& n){return b / std::sqrt(n);}
        );

        plot_line(result, file_base + "a)-2.pdf");
    }

    { // b) u(n) / n
        axis<double> result;
        result.x = results.avg_U.x;
        std::transform(
            results.avg_U.y.begin(),
            results.avg_U.y.end(),
            results.avg_U.x.begin(),
            std::back_inserter(result.y),
            [](auto& u, auto& n){return u / n;}
        );

        plot_line(result, file_base + "b)-1.pdf");
    }

    { // c) c(n) / n
        axis<double> result;
        result.x = results.avg_C.x;
        std::transform(
            results.avg_C.y.begin(),
            results.avg_C.y.end(),
            results.avg_C.x.begin(),
            std::back_inserter(result.y),
            [](auto& c, auto& n){return c / n;}
        );

        plot_line(result, file_base + "c)-1.pdf");
    }

    { // c) c(n) / n ln n
        axis<double> result;
        result.x = results.avg_C.x;
        std::transform(
            results.avg_C.y.begin(),
            results.avg_C.y.end(),
            results.avg_C.x.begin(),
            std::back_inserter(result.y),
            [](auto& c, auto& n){return c / (n * std::log(n));}
        );

        plot_line(result, file_base + "c)-2.pdf");
    }

    { // c) c(n) / n*n
        axis<double> result;
        result.x = results.avg_C.x;
        std::transform(
            results.avg_C.y.begin(),
            results.avg_C.y.end(),
            results.avg_C.x.begin(),
            std::back_inserter(result.y),
            [](auto& c, auto& n){return c / (n * n);}
        );

        plot_line(result, file_base + "c)-3.pdf");
    }

    { // d) d(n) / n
        axis<double> result;
        result.x = results.avg_D.x;
        std::transform(
            results.avg_D.y.begin(),
            results.avg_D.y.end(),
            results.avg_D.x.begin(),
            std::back_inserter(result.y),
            [](auto& d, auto& n){return d / n;}
        );

        plot_line(result, file_base + "d)-1.pdf");
    }

    { // d) d(n) / n ln n
        axis<double> result;
        result.x = results.avg_D.x;
        std::transform(
            results.avg_D.y.begin(),
            results.avg_D.y.end(),
            results.avg_D.x.begin(),
            std::back_inserter(result.y),
            [](auto& d, auto& n){return d / (n * std::log(n));}
        );

        plot_line(result, file_base + "d)-2.pdf");
    }

    { // d) d(n) / n*n
        axis<double> result;
        result.x = results.avg_D.x;
        std::transform(
            results.avg_D.y.begin(),
            results.avg_D.y.end(),
            results.avg_D.x.begin(),
            std::back_inserter(result.y),
            [](auto& d, auto& n){return d / (n * n);}
        );

        plot_line(result, file_base + "d)-3.pdf");
    }

    { // e) d(n)-c(n) / n
        axis<double> result;
        result.x = avg_D_C.x;
        std::transform(
            avg_D_C.y.begin(),
            avg_D_C.y.end(),
            avg_D_C.x.begin(),
            std::back_inserter(result.y),
            [](auto& d_c, auto& n){return d_c / n;}
        );

        plot_line(result, file_base + "e)-1.pdf");
    }

    { // e) d(n)-c(n) / n ln n
        axis<double> result;
        result.x = avg_D_C.x;
        std::transform(
            avg_D_C.y.begin(),
            avg_D_C.y.end(),
            avg_D_C.x.begin(),
            std::back_inserter(result.y),
            [](auto& d_c, auto& n){return d_c / (n * std::log(n));}
        );

        plot_line(result, file_base + "e)-2.pdf");
    }

    { // e) d(n)-c(n) / n ln ln n
        axis<double> result;
        result.x = avg_D_C.x;
        std::transform(
            avg_D_C.y.begin(),
            avg_D_C.y.end(),
            avg_D_C.x.begin(),
            std::back_inserter(result.y),
            [](auto& d_c, auto& n){return d_c / (n * std::log(std::log(n)));}
        );

        plot_line(result, file_base + "e)-3.pdf");
    }
}
