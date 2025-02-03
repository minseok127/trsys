#include "include/candle_cantainer/vector_candle_container.h"

static candle_container_ops vector_candle_container_ops = {
	.init_candle_container = ,
	.free_candle_container = ,
	.atomic_update_candle = ,
	.fetch_candle_ptr_by_index = ,
	.fetch_candle_ptr_by_start_timestamp = ,
	.fetch_candle_ptr_by_end_timestamp = ,
	.fetch_candle_ptr_by_datetime = ,
	.fetch_open_by_index = ,
	.fetch_open_by_start_timestamp = ,
	.fetch_open_by_end_timestamp = ,
	.fetch_open_by_datetime = ,
	.fetch_high_by_index = ,
	.fetch_high_by_start_timestamp = ,
	.fetch_high_by_end_timestamp = ,
	.fetch_high_by_datetime = ,
	.fetch_low_by_index = ,
	.fetch_low_by_start_timestamp = ,
	.fetch_low_by_end_timestamp = ,
	.fetch_low_by_datetime = ,
	.fetch_close_by_index = ,
	.fetch_close_by_start_timestamp = ,
	.fetch_close_by_end_timestamp = ,
	.fetch_close_by_datetime =
};

struct candle_container_ops *get_vector_candle_container_ops()
{
	return &vector_candle_container_ops;
}
