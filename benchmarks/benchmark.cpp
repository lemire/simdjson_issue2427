#include "simdjson.h"
#include "benchmarker.h"
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <fmt/core.h>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

void pretty_print(const std::string &name, size_t num_bytes,
                  double agg) {
  fmt::print("{:<50} : ", name);
  fmt::println(" {:5.2f} GB/s ", num_bytes / agg);
}


// See https://github.com/simdjson/simdjson/issues/2427
int main(int argc, char **argv) {
  simdjson::ondemand::parser parser;
  auto json = R"( {"channel":"ticker","type":"update","data":[{"symbol":"BTC/USD","bid":115112.9,"bid_qty":0.12760955,"ask":115113.0,"ask_qty":7.10992311,"last":115113.0,"volume":869.96254971,"vwap":115905.6,"low":114551.1,"high":117354.0,"change":-2230.0,"change_pct":-1.90}]}  )"_padded;
  pretty_print("JSON Parsing", json.size(),
    bench([&]() { auto r = parser.iterate(json); (void)r; }));
  return EXIT_SUCCESS;
}
