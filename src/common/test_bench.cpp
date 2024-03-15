#include <benchmark/benchmark.h>

class MyBenchmark {
 public:
  static int addition(int a, int b) { return a + b; }

  static int subtraction(int a, int b) { return a - b; }
};

// Fonction de benchmark pour l'addition
static void BM_Addition(benchmark::State& state) {
  // Récupération des arguments passés à la fonction de benchmark
  int a = state.range(0);
  int b = state.range(1);

  for (auto _ : state) {
    int result = MyBenchmark::addition(a, b);
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_Addition)->Args({10, 20})->Args({100, 200});

// Fonction de benchmark pour la soustraction
static void BM_Subtraction(benchmark::State& state) {
  // Récupération des arguments passés à la fonction de benchmark
  int a = state.range(0);
  int b = state.range(1);

  for (auto _ : state) {
    int result = MyBenchmark::subtraction(a, b);
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_Subtraction)->Args({10, 5})->Args({100, 50});

BENCHMARK_MAIN();
