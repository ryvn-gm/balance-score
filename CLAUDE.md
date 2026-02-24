# balance-score

Mobile SDK (C++17) that computes balance scores from wearable sensor / physiological data.

## Build

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

## Test

```bash
cmake --build build
ctest --test-dir build --output-on-failure
```

Or run the test binary directly:

```bash
./build/tests/balance_score_tests
```

## Development Workflow

This project follows strict TDD (Test-Driven Development):

1. Write a failing test in `tests/`
2. Write the minimum code in `src/` to make it pass
3. Refactor while keeping tests green

## Project Structure

- `include/balance_score/` - Public API headers (consumed by SDK users)
- `src/` - Implementation files and private headers
- `tests/` - GoogleTest-based tests
- `examples/` - Example applications demonstrating SDK usage
- `cmake/` - CMake modules and platform toolchain files
- `docs/specs/` - Architecture and specification documents

## Code Conventions

- C++17 standard, no compiler extensions
- Namespace: `balance_score`
- Naming: `snake_case` for functions, variables, files; `PascalCase` for types/classes
- Header guards: `#pragma once`
- Public headers go in `include/balance_score/`, private headers in `src/`

## Commit Conventions

- Atomic commits: one logical change per commit
- Imperative mood in commit messages (e.g., "Add signal processor" not "Added signal processor")
- Do NOT include Co-Authored-By lines
- Push to origin after each commit
