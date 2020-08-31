#include<stdio.h>
#include<stdlib.h>
/***********************************Functions declarations section*********************************/

typedef struct list{
	char line[500];
	struct list* next;
}list;

list* load(const char* filename);
void print_list(list* head);

