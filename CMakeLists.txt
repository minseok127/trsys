# trsys/CMakeLists.txt

cmake_minimum_required(VERSION 3.15)
project(trsys LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

# ------------------------------------------------
# Add Apache Arrow
# ------------------------------------------------
set(ARROW_INSTALL_PATH "${CMAKE_CURRENT_LIST_DIR}/external/arrow/cpp/install")
find_package(Arrow REQUIRED PATHS ${ARROW_INSTALL_PATH})
find_package(Parquet REQUIRED PATHS ${ARROW_INSTALL_PATH})

# ------------------------------------------------
# Backend for trsys
# ------------------------------------------------
#add_subdirectory(backend)

# ------------------------------------------------
# Executable
# ------------------------------------------------
add_subdirectory(unittest)
#add_subdirectory(backtest)
#add_subdirectory(trader)
#add_subdirectory(datafactory)

