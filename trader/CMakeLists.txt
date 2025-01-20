# trader/CMakeLists.txt

add_executable(trader
    main.c
)

target_link_libraries(trader
    PRIVATE
        trsys
)
