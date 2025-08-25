#ifndef BENCHMARKER_H
#define BENCHMARKER_H
#include "counters/event_counter.h"
#include  <atomic>
event_collector collector;

// Returns the average elapsed time in nanoseconds
template <class function_type>
double bench(const function_type &&function, size_t N = 1000000, size_t repeat = 100) {
  event_aggregate aggregate{};
  for(size_t trial = 0; trial < repeat; trial++) {
    std::atomic_thread_fence(std::memory_order_acquire);
    collector.start();
    for (size_t i = 0; i < N; i++) {
      function();
    }
    std::atomic_thread_fence(std::memory_order_release);
    event_count allocate_count = collector.end();
    aggregate << allocate_count;
  }
  return aggregate.elapsed_ns() / N;
}
#endif // BENCHMARKER_H