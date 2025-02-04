#ifndef CANDLE_CONTAINER_H
#define CANDLE_CONTAINER_H

#include <stdint.h>

#ifndef __cacheline_aligned
#define __cacheline_aligned __attribute__((aligned(64)))
#endif /* __cacheline_aligned */

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
 * struct candle_data - Structure for storing a single OHLCV candle.
 * @date: e.g. 2024-01-01 => 20240101
 * @time: e.g. 12:04:01 => 120401 (optional)
 * @start_timestamp: the candle's start unix epoch timestamp
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
	double		open;
	double		high;
	double		low;
	double		close;
	double		volume;
	int64_t		state;
} __cacheline_aligned;

#define CANDLE_NULL_MASK	(0x8000000000000000ULL)
#define CANDLE_MUTABLE_MASK	(0x4000000000000000ULL)
#define CANDLE_INDEX_MASK	(0x3fffffffffffffffULL)

#define GET_CANDLE_INDEX(candle_state)	(candle_state & CANDLE_INDEX_MASK)
#define IS_CANDLE_MUTABLE(candle_state)	(candle_state & CANDLE_MUTABLE_MASK)
#define IS_CANDLE_NULL(candle_state)	(candle_state & CANDLE_NULL_MASK)

/*
 * struct candle_container_ops - Interface for container operations.
 * @init_candle_container: initialize the candle container
 * @free_candle_container: free the candle container
 * @atomic_update_candle: function pointer to apply a new trade data
 * @get_*_by_index: function pointer to fetch a data by index
 * @get_*_by_start_timestamp: function pointer to fecth a data by
 * start timestamp
 * @get_*_by_end_timestamp: function pointer to fetch a data by
 * end timestamp
 * @get_*_by_datetime: function pointer to fetch a data by datetime
 *
 * This structure abstracts operations on a candle_container.
 */	
struct candle_container_ops {
	void (*init_candle_container)(struct candle_container *container_ptr,
		int candle_type);

	void (*free_candle_container)(struct candle_container *container_ptr);

	int64_t (*update_candle)(struct candle_container *container_ptr,
		int64_t trade_timestamp, int32_t price);

	struct candle_data (*get_candle_by_index)(
		struct candle_container *container_ptr, int32_t index);

	struct candle_data (*get_candle_by_start_timestamp)(
		struct candle_container *container_ptr, int64_t start_timestamp);

	struct candle_data (*get_candle_by_end_timestamp)(
		struct candle_container *container_ptr, int64_t end_timestamp);

	struct candle_data (*get_candle_by_datetime)(
		struct candle_container *container_ptr, int32_t date, int32_t time);

	int32_t (*get_open_by_index)(
		struct candle_container *container_ptr, int32_t index);

	int32_t (*get_open_by_start_timestamp)(
		struct candle_container *container_ptr, int64_t start_timestamp);

	int32_t (*get_open_by_end_timestamp)(
		struct candle_container *container_ptr, int64_t end_timestamp);

	int32_t (*get_open_by_datetime)(
		struct candle_container *container_ptr, int32_t date, int32_t time);

	int32_t (*get_high_by_index)(
		struct candle_container *container_ptr, int32_t index);

	int32_t (*get_high_by_start_timestamp)(
		struct candle_container *container_ptr, int64_t start_timestamp);

	int32_t (*get_high_by_end_timestamp)(
		struct candle_container *container_ptr, int64_t end_timestamp);

	int32_t (*get_high_by_datetime)(
		struct candle_container *container_ptr, int32_t date, int32_t time);

	int32_t (*get_low_by_index)(
		struct candle_container *container_ptr, int32_t index);

	int32_t (*get_low_by_start_timestamp)(
		struct candle_container *container_ptr, int64_t start_timestamp);

	int32_t (*get_low_by_end_timestamp)(
		struct candle_container *container_ptr, int64_t end_timestamp);

	int32_t (*get_low_by_datetime)(
		struct candle_container *container_ptr, int32_t date, int32_t time);

	int32_t (*get_close_by_index)(
		struct candle_container *container_ptr, int32_t index);

	int32_t (*get_close_by_start_timestamp)(
		struct candle_container *container_ptr, int64_t start_timestamp);

	int32_t (*get_close_by_end_timestamp)(
		struct candle_container *container_ptr, int64_t end_timestamp);

	int32_t (*get_close_by_datetime)(
		struct candle_container *container_ptr, int32_t date, int32_t time);

	int64_t (*get_volume_by_index)(
		struct candle_container *container_ptr, int32_t index);

	int64_t (*get_volume_by_start_timestamp)(
		struct candle_container *container_ptr, int64_t start_timestamp);

	int64_t (*get_volume_by_end_timestamp)(
		struct candle_container *container_ptr, int64_t end_timestamp);

	int64_t (*get_volume_by_datetime)(
		struct candle_container *container_ptr, int32_t date, int32_t time);
};

/*
 * struct candle_container - Generic container for candle_data.
 * @container_impl: pointer to the underlying candle container
 * @container_ops: interface to the candle container
 *
 * This is an abstraction for various types of candle containers. Each candle
 * container implementation, optimized for its specific purpose, must provide a
 * pointer to the implemented container and interface to communicate.
 */
struct candle_container {
	void *contanier_impl;
	struct candle_container_ops *container_ops;
};

#endif /* CANDLE_CONTAINER_H */
