# unittest/CMakeLists.txt

#----------------------------------------------------------------
# Basic Arrow Data Strucrues 
# https://arrow.apache.org/docs/cpp/tutorials/basic_arrow.html
#----------------------------------------------------------------
add_executable(arrow_data_structure
	arrow_data_structure.cpp
)

target_link_libraries(arrow_data_structure
	PRIVATE
		Arrow::arrow_shared
)

#----------------------------------------------------------------
# Basic Arrow File I/O
# https://arrow.apache.org/docs/cpp/tutorials/io_tutorial.html
#----------------------------------------------------------------
add_executable(arrow_file_io
	arrow_file_io.cpp
)

target_link_libraries(arrow_file_io
	PRIVATE
		Arrow::arrow_shared
		Parquet::parquet_shared
)

#----------------------------------------------------------------
# Basic Arrow Compute
# https://arrow.apache.org/docs/cpp/tutorials/compute_tutorial.html
#----------------------------------------------------------------
add_executable(arrow_compute
	arrow_compute.cpp
)

target_link_libraries(arrow_compute
	PRIVATE
		Arrow::arrow_shared
)

#----------------------------------------------------------------
# mimalloc
#----------------------------------------------------------------
add_executable(mimalloc_test
	mimalloc_test.cpp
)

target_link_libraries(mimalloc_test
	PRIVATE
		mimalloc
)
