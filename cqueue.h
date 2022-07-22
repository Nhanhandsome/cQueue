/*
 * cqueue.h
 *
 *  Created on: Jul 22, 2022
 *      Author: Admin
 */

#ifndef FLASHFIRMWAREAPP_SERVICE_CQUEUE_H_
#define FLASHFIRMWAREAPP_SERVICE_CQUEUE_H_


#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

typedef struct xQueue_Handle_t Queue_Handle;

struct xQueue_Handle_t{
    void *buff;
    size_t length;
    size_t size;
    volatile unsigned int head;
    volatile unsigned int tail;
    unsigned int count;
};


void queue_init(Queue_Handle *p_queue,size_t length,size_t size);
bool queue_push(Queue_Handle *p_queue,void *item);
bool queue_pop(Queue_Handle *p_queue,void *item);
void queue_deinit(Queue_Handle *p_queue);
unsigned int queue_get_num_item(Queue_Handle *p_queue);

#endif /* FLASHFIRMWAREAPP_SERVICE_CQUEUE_H_ */
