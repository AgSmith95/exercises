#include <benchmark/benchmark.h>

#include "algorithms.h"

#include <vector>
#include <algorithm> // for shuffle
#include <numeric>   // for iota
#include <random>

std::vector<std::vector<int>> test_data;
auto less = std::less();

static void my_minmax(benchmark::State& state) {
    for (auto _ : state) {
        for (const auto& e: test_data) {
            auto res = minmax_elements_2(e.begin(), e.end(), less);
            benchmark::DoNotOptimize(res);
        }
    }
}
// Register the function as a benchmark
BENCHMARK(my_minmax);

// Define another benchmark
static void their_minmax(benchmark::State& state) {
    for (auto _ : state) {
        for (const auto& e: test_data) {
            auto res = minmax_elements(e.begin(), e.end(), less);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(their_minmax);

int main(int argc, char** argv) {
    // my custom init
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::uniform_int_distribution<int> dist {-20, 20};
        auto gen = [&dist, &g]() { return dist(g); };

        test_data.emplace_back();
        unsigned i = 1;
        while (i < 100000) {
            test_data.emplace_back(i);
            //std::iota(test_data.back().begin(), test_data.back().end(), -5);
            std::generate(test_data.back().begin(), test_data.back().end(), gen);
            //std::shuffle(test_data.back().begin(), test_data.back().end(), g);
            i *= 10;
        }
    }

    // Google-provided init and test-runner
    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
    return 0;
}
