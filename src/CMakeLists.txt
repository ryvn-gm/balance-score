add_library(balance_score)

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

set_target_properties(balance_score PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)

target_compile_definitions(balance_score PRIVATE BALANCE_SCORE_BUILDING)
