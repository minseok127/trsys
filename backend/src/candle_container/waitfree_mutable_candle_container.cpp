#include "include/candle_cantainer/waitfree_mutable_candle_container.h"

static candle_container_ops waitfree_mutable_candle_container_ops = {
	.init_candle_container = ,
	.free_candle_container = ,
	.update_candle = ,
	.get_candle_by_index = ,
	.get_candle_by_start_timestamp = ,
	.get_candle_by_end_timestamp = ,
	.get_candle_by_datetime = ,
	.get_open_by_index = ,
	.get_open_by_start_timestamp = ,
	.get_open_by_end_timestamp = ,
	.get_open_by_datetime = ,
	.get_high_by_index = ,
	.get_high_by_start_timestamp = ,
	.get_high_by_end_timestamp = ,
	.get_high_by_datetime = ,
	.get_low_by_index = ,
	.get_low_by_start_timestamp = ,
	.get_low_by_end_timestamp = ,
	.get_low_by_datetime = ,
	.get_close_by_index = ,
	.get_close_by_start_timestamp = ,
	.get_close_by_end_timestamp = ,
	.get_close_by_datetime =
};
