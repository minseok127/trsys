#ifndef CANDLE_CONTAINER_H
#define CANDLE_CONTAINER_H

#include <stdint.h>

#ifndef __cacheline_aligned
#define __cacheline_aligned __attribute__((aligned(64)))
#endif /* __cacheline_aligned */

/*
 * struct candle_data - Structure for storing a single OHLCV candle.
 * @date: e.g. 2024-01-01 => 20240101
 * @time: e.g. 12:04:01 => 120401 (optional)
 * @start_timestamp: the candle's start unix epoch timestamp
 * @end_timestamp: the candle's end unix epoch timestamp
 * @first_trade_timestamp: the candle's first traded unix epoch timestamp
 * @open: the opening price
 * @high: the highest price
 * @low: the lowest price
 * @close: the closing price
 * @volume: the trading volume
 * @state: the state of the candle
 */
struct candle_data {
	int32_t		date;
	int32_t		time;
	int64_t		start_timestamp;
	int64_t		end_timestamp;
	int64_t		first_trade_timestamp;
	int32_t		open;
	int32_t		high;
	int32_t		low;
	int32_t		close;
	uint64_t	volume;
	int64_t		state;
} __cacheline_aligned;

#define CANDLE_IS_NULL_MASK	(0x8000000000000000ULL)
#define CANDLE_INDEX_MASK	(0x7fffffffffffffffULL)

#define GET_CANDLE_INDEX(candle_state)	(candle_state & CANDLE_INDEX_MASK)
#define IS_CANDLE_NULL(candle_state)	(candle_state < 0)

enum candle_type_enum {
	CANDLE_TYPE_YEAR,
	CANDLE_TYPE_MONTH,
	CANDLE_TYPE_WEEK,
	CANDLE_TYPE_DAY,
	CANDLE_TYPE_1H,
	CANDLE_TYPE_30M,
	CANDLE_TYPE_5M,
	CANDLE_TYPE_1M,
};

/*
 * struct candle_container - Generic container for candle_data.
 * @candle_table: pointer to the underlying candle data table
 * @auxiliary: pointer to auxiliary data structures for the container
 * @candle_type: the type of the candle table
 *
 * This container abstracts both the candle_data table and any additional data
 * structures needed for efficient managment.
 */
struct candle_container {
	void *candle_table;
	void *auxiliary;
	int	candle_type;
};

/*
 * struct candle_container_ops - Interface for container operations.
 * @atomic_update_candle: function pointer to apply a new trade data
 * @fetch_by_index: function pointer to fetch a candle by index
 * @fetch_by_start_timestamp: function pointer to fecth a candle by
 * start timestamp
 * @fetch_by_end_timestamp: function pointer to fetch a candle by
 * end timestamp
 * @fetch_by_datetime: function pointer to fetch a candle by datetime
 *
 * This structure abstracts operations on a candle_container.
 */	
struct candle_container_ops {
	int (*atomic_update_candle)(struct candle_container *container_ptr,
		int64_t trade_timestamp, int32_t price);

	struct candle_data *(*fetch_by_index)(
		struct candle_container *container_ptr, int32_t index);

	struct candle_data *(*fetch_by_start_timestamp)(
		struct candle_container *container_ptr, int64_t start_timestamp);

	struct candle_data *(*fetch_by_end_timestamp)(
		struct candle_container *container_ptr, int64_t end_timestamp);

	struct candle_data *(*fetch_by_datetime)(
		struct candle_container *container_ptr, int32_t date, int32_t time);
};

#endif /* CANDLE_CONTAINER_H */
