#ifndef VECTOR_CANDLE_CONTAINER_H
#define VECTOR_CANDLE_CONTAINER_H

#include "candle_container.h"

struct candle_container_ops *get_vector_candle_container_ops(void);

void init_vector_candle_container(struct candle_container *container_ptr);

void free_vector_candle_container(struct candle_container *container_ptr);

#endif /* VECTOR_CANDLE_CONTAINER_H */
