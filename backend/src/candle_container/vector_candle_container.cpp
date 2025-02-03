#include "include/candle_cantainer/vector_candle_container.h"

static candle_container_ops vector_candle_container_ops = {
	.init_candle_container = ,
	.free_candle_container = ,
	.atomic_update_candle = ,
	.fetch_by_index = ,
	.fetch_by_start_timestamp = ,
	.fetch_by_end_timestamp = ,
	.fetch_by_datetime =
};

struct candle_container_ops *get_vector_candle_container_ops()
{
	return &vector_candle_container_ops;
}
