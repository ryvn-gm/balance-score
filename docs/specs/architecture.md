# 專案架構說明

## 概述

balance-score 是一個 C++17 的 Mobile SDK，用於接收穿戴式裝置的感測器訊號與生理數值，經過演算法處理後輸出計算結果。

## 目錄結構

```
balance-score/
├── CMakeLists.txt
├── CLAUDE.md
├── README.md
├── cmake/
├── include/
│   └── balance_score/
├── src/
│   └── CMakeLists.txt
├── tests/
│   └── CMakeLists.txt
├── examples/
│   ├── CMakeLists.txt
│   └── main.cpp
└── docs/
    └── specs/
```

## 各目錄用途

### `include/balance_score/`

公開 API 標頭檔（Public Headers）。這些是 SDK 使用者會引入的檔案。

- 只放對外公開的介面，不放實作細節
- 引用方式：`#include <balance_score/xxx.h>`

### `src/`

實作程式碼與私有標頭檔。

- `.cpp` 檔案：演算法實作、訊號處理邏輯
- 私有 `.h` 檔案：僅供內部使用，不對外暴露
- `CMakeLists.txt`：定義 `balance_score` 靜態函式庫的建置目標

### `tests/`

GoogleTest 測試檔案。本專案採用 TDD 開發流程，所有功能都先寫測試再寫實作。

- 測試檔命名：`xxx_test.cpp`
- 透過 CMake FetchContent 自動下載 GoogleTest v1.15.2
- 執行方式：`ctest --test-dir build --output-on-failure`

### `cmake/`

CMake 模組與平台工具鏈檔案。

- 預留給未來的 iOS / Android 交叉編譯工具鏈
- 例如：`ios.toolchain.cmake`、`android.toolchain.cmake`

### `examples/`

範例應用程式，模擬 mobile app 如何呼叫 SDK。

- `main.cpp`：互動式終端範例，可從 stdin 輸入資料
- 執行方式：`./build/examples/balance_score_example`
- 透過 `BUILD_EXAMPLES` CMake 選項控制是否建置

### `docs/specs/`

專案規格與架構文件。

### 根目錄檔案

| 檔案 | 用途 |
|------|------|
| `CMakeLists.txt` | 根建置設定：定義專案名稱、C++17 標準、啟用測試 |
| `CLAUDE.md` | AI 輔助開發的慣例設定：建置指令、TDD 流程、commit 規範 |
| `README.md` | 專案說明、建置與測試指令 |
| `.gitignore` | Git 忽略規則：編譯產物、build 目錄、IDE 檔案 |

## 建置系統

- **CMake 3.20+**：跨平台建置，支援 iOS/Android 工具鏈
- **靜態函式庫（STATIC）**：Mobile SDK 標準做法，直接連結進 App
- **Modern CMake 風格**：使用 target-based 屬性與 generator expressions

## 開發流程（TDD）

```
1. 在 tests/ 寫一個失敗的測試
2. 在 src/ 寫最少的程式碼讓測試通過
3. 重構，確保測試維持綠燈
```

## 命名慣例

| 類型 | 風格 | 範例 |
|------|------|------|
| 函式、變數、檔案 | `snake_case` | `process_signal()` |
| 類別、型別 | `PascalCase` | `SensorProcessor` |
| Namespace | `snake_case` | `balance_score` |
| 標頭保護 | `#pragma once` | — |
