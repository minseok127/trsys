```
trsys/
├── CMakeLists.txt
├── README.md
├── doc/
├── unittest/
│   └── CMakeLists.txt
│   └── arrow_data_structure.cpp
│   └── arrow_file_io.cpp
│   └── arrow_compute.cpp
│   └── mimalloc_test.cpp
├── scripts/
│   └── init.sh
│   └── install.sh
├── backtest/
│   └── CMakeLists.txt
├── trader/
│   └── CMakeLists.txt
├── datafactory/
│   └── CMakeLists.txt
├── config/
├── data/
├── backend/              # libtrsys
│   ├── CMakeLists.txt
│   ├── include/
│   │   ├── core/
│   |   |   └── candle_table.h
│   |   |   └── market_api.h
│   │   ├── drivers/
│   |   |   └── arrow_candle_table_driver.h
│   |   |   └── std_vector_candle_table_driver.h
│   |   |   └── binance_market_api_driver.h
│   │   ├── storage/
│   │   ├── backtest/
│   │   ├── trader/
│   │   ├── datafactory/
│   └── src/
│       ├── core/
│       |   └── candle_table.cpp
│       |   └── market_api.cpp
│       ├── drivers/
│       |   └── arrow_candle_table_driver.cpp
│       |   └── std_vector_candle_table_driver.cpp
│       |   └── binance_market_api_driver.cpp
│       ├── storage/
│       ├── backtest/
│       ├── trader/
│       ├── datafactory/
└── external/
    └── arrow/             # Apache Arrow (Git submodule)
    └── mimalloc/          # Microsoft mimalloc (Git submodule)
```
