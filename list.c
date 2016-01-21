/*
list.c
stan
January,20,2016
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list.h"

/************************************************************************************
*																					*
*--------------------------------list_init------------------------------------------*
************************************************************************************/

//void list_init(List *list, void(*destory)(void *data)){
void list_init(List *list){
list->size = 0;
//list->destory = destory;
list->head = NULL;
list->tail = NULL;
printf("inited\n");
return;
}

//list_destory
void list_destory(List *list) {
	void *data;
	while (list_size(list)>0){
		
		if(list_rem_next(list,NULL,(void**)&data) == 0) {
		//	list->destory(data);
			free(list);
		}
	}
	memset(list, 0, sizeof(List));
	return;

}

//list_ins_next

int list_ins_next(List *list, ListElmt *element, const void *data) {
	ListElmt *new_element;
	if((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL) return -1;
	new_element->data = (void *)data;
	if(element == NULL){
		if(list_size(list) == 0) list->tail = new_element;
		new_element->next = list->head;
		list->head = new_element;
	}
	else{
		if(element->next == NULL) list->tail = new_element;
		new_element->next = element->next;
		element->next = new_element;	
	}
	printf("add new element\n");
	printf("with value : %d\n",*((int *) data));
	list->size++;
	printf("size is now : %d\n",list->size);
	return 0;
}

//list_rem_next

int list_rem_next(List *list, ListElmt *element, void **data) {
	ListElmt *old_element;
	if(list_size(list) == 0) return -1;
	
	if(element == NULL){
		*data = list->head->data;
		old_element = list->head;
		list->head = list->head->next;
	}
	
	if(list_size(list) == 1) list->tail = NULL;
	
	else{
		if(element->next == NULL) return -1;
		*data = element->next->data;
		old_element = element->next;
		element->next = element->next->next;
		
		if(element->next == NULL) list->tail = element;
	}
	free(old_element);
	list->size--;
	return 0;
}

int main (int argc, char* argv[]){
	ListElmt test;
	ListElmt *travel;
	List test_list;
	int value = 2;
	list_init(&test_list);
	list_ins_next(&test_list,&test,&value);
	value = 3;
	list_ins_next(&test_list,&test,&value);
	travel = test_list.head;
	while(travel != NULL){
		printf("data is : %d\n",*(int*)travel->data);
		travel = travel->next;
		
	}
}
