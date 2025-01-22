# backtest/CMakeLists.txt

add_executable(backtest
	main.c
)

target_link_libraries(backtest
	PRIVATE
		trsys
)
