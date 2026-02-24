# balance-score

C++ mobile SDK for computing balance scores from wearable sensor and physiological data.

## Prerequisites

- CMake 3.20+
- C++17 compatible compiler (Clang, GCC, MSVC)

On macOS:

```bash
brew install cmake
```

## Build

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

## Test

```bash
ctest --test-dir build --output-on-failure
```

## Project Structure

```
balance-score/
├── include/balance_score/   # Public API headers
├── src/                     # Implementation
├── tests/                   # GoogleTest-based tests
├── examples/                # Example applications
├── cmake/                   # CMake modules & toolchains
├── docs/specs/              # Architecture & specs
├── CMakeLists.txt           # Root build configuration
└── CLAUDE.md                # Development conventions
```

## Run Example

```bash
./build/examples/balance_score_example
```
