# unittest/CMakeLists.txt

add_executable(unittest
    main.c
)

target_link_libraries(unittest
    PRIVATE
        trsys_backend
)
