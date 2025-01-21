# backend/CMakeLists.txt

# ------------------------------------------------
# Make static library
# ------------------------------------------------
add_library(trsys SHARED
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
target_include_directories(trsys PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# ------------------------------------------------
# Link Apache Arrow
# ------------------------------------------------
target_link_libraries(trsys PRIVATE
    Arrow::arrow_shared
)
