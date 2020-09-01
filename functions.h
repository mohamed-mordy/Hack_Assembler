#include<stdio.h>
#include"ADT.h"
/***********************************Functions declarations section*********************************/

list_g* green_code_loader(const char* filename);
void print_green(const list_g* head);
void print_pure(const list_p* head);
list_p* pure_code_builder(list_g* green_head);
void error(void);
void drop_g(list_g* head_g);
void drop_p(list_p* head_p);
void drop_e(list_e* head_e);
list_st* initialize_st(void);
void print_st(list_st* head);
list_st* add_2_st(pair this, list_st* head);
