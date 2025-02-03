# backend/CMakeLists.txt

# ------------------------------------------------
# Make static library
# ------------------------------------------------
add_library(trsys SHARED

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
	Parquet::parquet_shared
)
