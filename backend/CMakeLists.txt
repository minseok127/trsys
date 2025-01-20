# backend/CMakeLists.txt

# ------------------------------------------------
# Make static library
# ------------------------------------------------
add_library(trsys STATIC
	# src/core/

	# src/drivers/

	# src/storage/

	# src/backtest/

	# src/trader/

	# src/datafactory/
)

# ------------------------------------------------
# Set include path
# ------------------------------------------------
target_include_directories(trsys PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# ------------------------------------------------
# Link Apache Arrow
# ------------------------------------------------
target_link_libraries(trsys PUBLIC
    ARROW::arrow
    ARROW::parquet
)
