# backend/CMakeLists.txt

# ------------------------------------------------
# Make static library
# ------------------------------------------------
add_library(trsys_backend STATIC
	# src/core/

	# src/drivers/

	# src/storage/

	# src/backtest/

	# src/trader/
)

# ------------------------------------------------
# Set include path
# ------------------------------------------------
target_include_directories(trsys_backend PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# ------------------------------------------------
# Link Apache Arrow
# ------------------------------------------------
target_link_libraries(trsys_backend PUBLIC
    ARROW::arrow
    ARROW::parquet
)
