/*
 * cqueue.c
 *
 *  Created on: Jul 22, 2022
 *      Author: Admin
 */



#include "cqueue.h"





void queue_init(Queue_Handle *p_queue,size_t length,size_t size){
    p_queue->length = length+1;
    p_queue->size = size;
    p_queue->count = 0;
    p_queue->head = 0;
    p_queue->tail = 0;
    p_queue->buff = malloc(p_queue->length*p_queue->size);
    if(p_queue->buff == NULL){
    	printf("Queue init false\r\n");
    	return;
    }
}
void queue_deinit(Queue_Handle *p_queue){
	p_queue->count = 0;
	p_queue->head = 0;
	p_queue->tail = 0;
	p_queue->length = 0;
	free(p_queue->buff);
}
bool queue_push(Queue_Handle *p_queue,void *item){
    unsigned int next = (unsigned int) (p_queue->head + 1) % p_queue->length;
    if (next != p_queue->tail) {
//        p_queue->buff[p_queue->head] = c;
        memcpy(p_queue->buff+p_queue->head*p_queue->size,item,p_queue->size);
        p_queue->head = next;
        p_queue->count += 1;
        return true;
    }
    printf("queue push false\r\n");
    return false;
}
bool queue_pop(Queue_Handle *p_queue,void *item){
	if (p_queue->head != p_queue->tail) {
		// data[0] = p_queue->buff[p_queue->tail];
        memcpy(item,p_queue->buff+p_queue->tail*p_queue->size,p_queue->size);
		p_queue->tail = (unsigned int) (p_queue->tail + 1) % p_queue->length;
		p_queue->count -= 1;
		return true;
	}
	printf("queue pop false\r\n");
	return false;
}
unsigned int queue_get_num_item(Queue_Handle *p_queue){
	return p_queue->count;
}
