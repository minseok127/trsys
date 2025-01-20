# trsys/CMakeLists.txt

cmake_minimum_required(VERSION 3.15)
project(trsys LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# ------------------------------------------------
# Apache Arrow build options
# ------------------------------------------------
option(ARROW_BUILD_TESTS "Build Arrow tests" OFF)
option(ARROW_BUILD_SHARED "Build shared Arrow libs" ON)
option(ARROW_BUILD_STATIC "Build static Arrow libs" OFF)
option(ARROW_PARQUET "Enable Parquet component" ON)

# ------------------------------------------------
# Add external libraries
# ------------------------------------------------
add_subdirectory(external/arrow/cpp)

# ------------------------------------------------
# Backend for trsys
# ------------------------------------------------
add_subdirectory(backend)

# ------------------------------------------------
# Executable
# ------------------------------------------------
add_subdirectory(unittest)
add_subdirectory(backtest)
add_subdirectory(trader)
add_subdirectory(datafactory)

