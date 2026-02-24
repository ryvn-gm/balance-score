#!/usr/bin/env python3
"""Demo: load balance_score shared library via ctypes."""

import ctypes
import pathlib
import platform

script_dir = pathlib.Path(__file__).resolve().parent
build_dir = script_dir.parent / "build" / "src"

ext = ".dylib" if platform.system() == "Darwin" else ".so"
lib_path = build_dir / f"libbalance_score{ext}"

if not lib_path.exists():
    print(f"Library not found: {lib_path}")
    print("Build with: cmake -B build -DBUILD_SHARED_LIBS=ON && cmake --build build")
    raise SystemExit(1)

lib = ctypes.CDLL(str(lib_path))

lib.bs_healthy.restype = ctypes.c_bool
lib.bs_healthy.argtypes = []

lib.bs_version.restype = ctypes.c_char_p
lib.bs_version.argtypes = []

print(f"balance-score SDK v{lib.bs_version().decode()}")
print(f"healthy: {lib.bs_healthy()}")
