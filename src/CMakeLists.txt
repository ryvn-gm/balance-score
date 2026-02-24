add_library(balance_score STATIC)

target_sources(balance_score
    PRIVATE
        health.cpp
)

target_include_directories(balance_score
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(balance_score PUBLIC cxx_std_17)
