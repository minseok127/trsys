#ifndef CANDLE_CONTAINER_H
#define CANDLE_CONTAINER_H

#include <stdint.h>

#include <string>

#ifndef __cacheline_aligned
#define __cacheline_aligned __attribute__((aligned(64)))
#endif /* __cacheline_aligned */

/*
 * struct candle_data - Data structure for a single OHLCV
 * @date: e.g. 2024-01-01 => 20240101
 * @time: e.g. 12:04:01 => 120401 (optional)
 * @start_timestamp: the candle's start unix epoch timestamp
 * @open: the opening price
 * @high: the highest price
 * @low: the lowest price
 * @close: the closing price
 * @volume: the trading volume
 * @state: the state of the candle
 *
 * This is a definition of a candle. But the fields of a real candle data may
 * have different physical layouts depending on the candle_container type.
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
 * struct candle_container_ops - Interface of candle_container
 * @update_candle: function pointer to apply a new trade data
 * @get_*_by_index: function pointer to fetch a data by index
 * @get_*_by_start_timestamp: function pointer to fecth a data by
 * start timestamp
 * @get_*_by_end_timestamp: function pointer to fetch a data by
 * end timestamp
 * @get_*_by_datetime: function pointer to fetch a data by datetime
 *
 * This structure abstracts the operations of a candle_container. Users interact
 * with a unified interface for all types of candle_container, eliminating
 * dependencies between the internal candle_container implementation and
 * external user code.
 */	
struct candle_container_ops {
	int64_t (*update_candle)(void *candle_table,
		int64_t trade_timestamp, int32_t price);

	struct candle_data (*get_candle_by_index)(
		void *candle_table, int32_t index);

	struct candle_data (*get_candle_by_start_timestamp)(
		void *candle_table, int64_t start_timestamp);

	struct candle_data (*get_candle_by_end_timestamp)(
		void *candle_table, int64_t end_timestamp);

	struct candle_data (*get_candle_by_datetime)(
		void *candle_table, int32_t date, int32_t time);

	int32_t (*get_open_by_index)(
		void *candle_table, int32_t index);

	int32_t (*get_open_by_start_timestamp)(
		void *candle_table, int64_t start_timestamp);

	int32_t (*get_open_by_end_timestamp)(
		void *candle_table, int64_t end_timestamp);

	int32_t (*get_open_by_datetime)(
		void *candle_table, int32_t date, int32_t time);

	int32_t (*get_high_by_index)(
		void *candle_table, int32_t index);

	int32_t (*get_high_by_start_timestamp)(
		void *candle_table, int64_t start_timestamp);

	int32_t (*get_high_by_end_timestamp)(
		void *candle_table, int64_t end_timestamp);

	int32_t (*get_high_by_datetime)(
		void *candle_table, int32_t date, int32_t time);

	int32_t (*get_low_by_index)(
		void *candle_table, int32_t index);

	int32_t (*get_low_by_start_timestamp)(
		void *candle_table, int64_t start_timestamp);

	int32_t (*get_low_by_end_timestamp)(
		void *candle_table, int64_t end_timestamp);

	int32_t (*get_low_by_datetime)(
		void *candle_table, int32_t date, int32_t time);

	int32_t (*get_close_by_index)(
		void *candle_table, int32_t index);

	int32_t (*get_close_by_start_timestamp)(
		void *candle_table, int64_t start_timestamp);

	int32_t (*get_close_by_end_timestamp)(
		void *candle_table, int64_t end_timestamp);

	int32_t (*get_close_by_datetime)(
		void *candle_table, int32_t date, int32_t time);

	int64_t (*get_volume_by_index)(
		void *candle_table, int32_t index);

	int64_t (*get_volume_by_start_timestamp)(
		void *candle_table, int64_t start_timestamp);

	int64_t (*get_volume_by_end_timestamp)(
		void *candle_table, int64_t end_timestamp);

	int64_t (*get_volume_by_datetime)(
		void *candle_table, int32_t date, int32_t time);
};

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
 * struct candle_container - Generic data structure for candles
 * @container_ops: interface to the candle container
 * @candle_table: pointer to the underlying candle table
 * @candle_storage: file management related data structure
 * @candle_type: type of candles
 *
 * This structure abstracts objects that manage a specific candle type of a
 * specific symbol, including memory access and file-based access, etc. It also
 * contains candle_container_ops, the interface for interacting with these
 * objects.
 *
 * All types of candle_container must provide an initialization function that
 * returns this structure and a free function for this structure. Users should
 * be able to interact with any candle_container without relying on its internal
 * implementation.
 */
struct candle_container {
	struct candle_container_ops *container_ops;
	void *candle_table;
	void *candle_storage;
	int candle_type;
};

#endif /* CANDLE_CONTAINER_H */
