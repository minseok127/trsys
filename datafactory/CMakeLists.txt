# datafactory/CMakeLists.txt

add_executable(datafactory
	main.c
)

target_link_libraries(datafactory 
	PRIVATE
		trsys
)
