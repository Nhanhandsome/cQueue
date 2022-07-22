/*
 * main.c
 *
 *  Created on: Jul 22, 2022
 *      Author: Admin
 */




#include "stdio.h"

#include "cqueue.h"

Queue_Handle num_queue;


typedef struct Student_t Student;

struct Student_t{
	char name[20];
	int age;
};

Student student[100];

int main(){
	queue_init(&num_queue, 1000, sizeof(Student));
	for(uint16_t i = 0;i<100;i++){
		sprintf(student[i].name,"Nguyen Van %02d",i);
		student[i].age = i;
	}

	for(uint16_t i = 0;i<100;i++){

		queue_push(&num_queue, (void*)&student[i]);
	}
	printf("Num item in queue : %d\n",queue_get_num_item(&num_queue));

	Student result;
	for(uint16_t i = 0;i<50;i++){
		if(queue_pop(&num_queue,(void*)&result) == true){
			printf("Studen %02d: name - %s , age - %02d\n",i,result.name,result.age);
		}
	}
	printf("Num item in queue : %d\r\n",queue_get_num_item(&num_queue));
	return 0;
}
