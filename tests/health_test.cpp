#include <gtest/gtest.h>
#include <balance_score/health.h>

namespace balance_score {
namespace {

TEST(Health, ReturnsTrue) {
    EXPECT_TRUE(healthy());
}

TEST(Health, VersionIsNotEmpty) {
    EXPECT_FALSE(version().empty());
}

}  // namespace
}  // namespace balance_score
