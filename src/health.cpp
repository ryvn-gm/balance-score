#include <balance_score/health.h>
#include <balance_score/balance_score_c.h>

namespace balance_score {

bool healthy() {
    return true;
}

std::string version() {
    return "0.1.0";
}

}  // namespace balance_score

extern "C" {

bool bs_healthy(void) {
    return balance_score::healthy();
}

const char* bs_version(void) {
    static const std::string v = balance_score::version();
    return v.c_str();
}

}
