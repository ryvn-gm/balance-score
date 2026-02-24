include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(balance_score_tests
    health_test.cpp
)

target_link_libraries(balance_score_tests
    PRIVATE
        balance_score
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(balance_score_tests)
