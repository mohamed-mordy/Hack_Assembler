#include<stdio.h>

typedef struct list_g{
	char line[500];
	int line_no_green;
	struct list_g* next;
	struct list_g* previous;
}list_g;

typedef struct list_p{
	char line[500];
	int line_no_green;
	int line_no_pure;
	struct list_p* next;
	struct list_p* previous;
}list_p;


typedef struct list_e{
	char line[500];
	int line_no_green;
	int line_no_exact;
	struct list_e* next;
	struct list_e* previous;
}list_e;

typedef struct pair{
	char symbol[20];
	int value;
}pair;

typedef struct list_st{
	pair record;
	struct list_st* next;
	struct list_st* previous;
}list_st;

