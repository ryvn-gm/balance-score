add_executable(balance_score_example
    main.cpp
)

target_link_libraries(balance_score_example
    PRIVATE
        balance_score
)
