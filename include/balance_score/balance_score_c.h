#pragma once

#include <balance_score/export.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

BALANCE_SCORE_API bool bs_healthy(void);
BALANCE_SCORE_API const char* bs_version(void);

#ifdef __cplusplus
}
#endif
