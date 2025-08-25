# Benchmark for issue 2427 (simdjson)

The objective of this benchmark is to report the speed of the call to `parser.iterate` on a small 
JSON imput.

# Usage

For macOS/Linux, follow the following instructions.

```cpp
cmake -B build
cmake --build build
./build/benchmark
```

Usage under Windows is similar.

## Possible results


### Apple M4/LLVM 17
```
JSON Parsing                                       :   6.29 GB/s
```

### Intel Ice Lake processor (2GHz base)/GCC12

```
JSON Parsing                                       :   4.49 GB/s
```
