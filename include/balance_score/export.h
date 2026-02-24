#pragma once

#if defined(_WIN32)
  #if defined(BALANCE_SCORE_BUILDING)
    #define BALANCE_SCORE_API __declspec(dllexport)
  #else
    #define BALANCE_SCORE_API __declspec(dllimport)
  #endif
#elif defined(__GNUC__) || defined(__clang__)
  #define BALANCE_SCORE_API __attribute__((visibility("default")))
#else
  #define BALANCE_SCORE_API
#endif
