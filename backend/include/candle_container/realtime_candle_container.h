#ifndef REALTIME_CANDLE_CONTAINER_H
#define REALTIME_CANDLE_CONTAINER_H

#include "candle_container.h"

struct candle_conatiner *init_realtime_candle_container(int candle_type);

void free_realtime_candle_container(struct candle_container *container);

#endif /* REALTIME_CANDLE_CONTAINER_H */
