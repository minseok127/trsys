# unittest/CMakeLists.txt

#----------------------------------------------------------------
# Basic Arrow Data Strucrues 
# https://arrow.apache.org/docs/cpp/tutorials/basic_arrow.html
#----------------------------------------------------------------
add_executable(basic_arrow_test
	basic_arrow_test.cpp
)

target_link_libraries(basic_arrow_test
	PRIVATE
		Arrow::arrow_shared
)

#----------------------------------------------------------------
# Arrow File I/O
# https://arrow.apache.org/docs/cpp/tutorials/io_tutorial.html
#----------------------------------------------------------------
add_executable(arrow_file_io_test
	arrow_file_io_test.cpp
)

target_link_libraries(arrow_file_io_test
	PRIVATE
		Arrow::arrow_shared
		Parquet::parquet_shared
)


