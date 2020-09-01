#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"functions.h"

// load function: this functions loads the green code into the memory as a linked list
//                the code, is structured using the list (list_g)
// input: the file name
// return: pointer to the head of the list
list_g* green_code_loader(const char* filename)
{
	FILE* fptr = fopen(filename, "r"); // open the file
	if(fptr == NULL) // check the pointer, and make sure everything is ok
	{
		printf("error opening the file \n");
		exit(1);
	}
	list_g* head = malloc(sizeof(list_g));
	list_g* head_2_return = head; // this is a copy of "head" to return it later
	head -> previous = NULL;
	int lineNumber = 1; // keep track of the number of each line
	while(1)                    
	{
        int m = 0; // This is used to BRAKE the loop
		int i = 0; // This is to index the characters of each line
		head -> line_no_green = lineNumber; // set the line number
		while(1)
		{
			m = fscanf(fptr, "%c", &(head -> line[i]));
			if(m == EOF) // This will be executed only once during the program cycle
			{
				head -> line[i] = '\n'; // Put something, it will be important later
				break;                  // Since each line contains'\n' so should be here
			} 
			if((head -> line[i]) == '\n') 
			{
				break;
			}
			
			i++;
		}

		if(m == EOF)   // It is very important to "break" here
		{              // We don't need to use "malloc" again
			break;
		}
		lineNumber++;  // increment the line number, we are going to deal with a new line
		head -> next = malloc(sizeof(list_g)); // allocate memory for the new line
		list_g* tmp = head;
		head = head -> next;
		head -> previous = tmp;
	}
	head = head -> previous; // In this function, we will always delete the last node
	free(head -> next);      // to make the code (very green i.e. "as is")
	head -> next = NULL; // terminate the list with "NULL"
	fclose(fptr); // close the file (hygiene)
	return head_2_return;
}


list_p* pure_code_builder(list_g* green_head)
{
	if(green_head == NULL) error();
	list_p* pure_head = malloc(sizeof(list_p));
	pure_head -> previous = NULL;
	list_p* pure_head_2_return = pure_head;
	int pure_line_number = 1;
	while(green_head != NULL)
	{
		int i = 0; // index the characters of the green line code
		int j = 0; // index the characters of the pure line code
		char instruction[100];
		while(1)
		{
			if((green_head -> line[i]) == '\n')
			{
				instruction[j] = '\0';
				break;
			}
			else if(isspace(green_head -> line[i]))
			{
				i++;
				continue;
			}
			else if((green_head -> line[i] == '/') && (green_head -> line[i + 1] == '/'))
			{
				instruction[j] = '\0';
				break;
			}
			else
			{
				instruction[j] = green_head -> line[i];
				i++;
				j++;
			}
		}
		if(instruction[0] == '\0')
		{
			green_head = green_head -> next;
			continue;
		}
		strcpy(pure_head -> line, instruction);
		pure_head -> line_no_pure = pure_line_number;
		pure_line_number++;
		pure_head -> line_no_green = green_head -> line_no_green;
		green_head = green_head -> next;
		if(green_head == NULL) break; // the position of this line of code is critical
		pure_head -> next = malloc(sizeof(list_p));
		list_p* tmp = pure_head;
		pure_head = pure_head -> next;
		pure_head -> previous = tmp;
	}
	pure_head -> next = NULL;
	// we will do some checks here
	if(pure_head -> line_no_pure == 0)
	{
		pure_head = pure_head -> previous;
		free(pure_head -> next);
		pure_head -> next = NULL;
	}
	return pure_head_2_return;
}

void error(void)
{
	printf("undefined error\n");
	exit(1);
}

void drop_g(list_g* head_g)
{
	if(head_g == NULL) error();
	while(head_g != NULL)
	{
		list_g* tmp = head_g -> next;
		free(head_g);
		head_g = tmp;
	}
}

void drop_p(list_p* head_p)
{
	if(head_p == NULL) error();
	while(head_p != NULL)
	{
		list_p* tmp = head_p -> next;
		free(head_p);
		head_p = tmp;
	}
}

void drop_e(list_e* head_e)
{
	if(head_e == NULL) error();
	while(head_e != NULL)
	{
		list_e* tmp = head_e -> next;
		free(head_e);
		head_e = tmp;
	}
}

list_st* initialize_st(void)
{
	list_st* head_st = malloc(sizeof(list_st));
	list_st* head_st_2_return = head_st;
	head_st -> previous = NULL;
	list_st* tmp;
	for(int i = 0; i <= 9; i++)
	{
		sprintf(head_st -> record.symbol, "R%c", i + 48);
		head_st -> record.value = i;
		head_st -> next = malloc(sizeof(list_st));
		tmp = head_st;
		head_st = head_st -> next;
		head_st -> previous = tmp;
	}
	int j = 0;
	for(int i = 10; i <= 15; i++)
	{
		sprintf(head_st -> record.symbol, "R%c%c", 1 + 48, j + 48);
		head_st -> record.value = i;
		head_st -> next = malloc(sizeof(list_st));
		tmp = head_st;
		head_st = head_st -> next;
		head_st -> previous = tmp;
		j++;
	}
	
	strcpy(head_st -> record.symbol, "SCREEN");
	head_st -> record.value = 16384;
	head_st -> next = malloc(sizeof(list_st));
	tmp = head_st;
	head_st = head_st -> next;
	head_st -> previous = tmp;

	strcpy(head_st -> record.symbol, "KBD");
	head_st -> record.value = 24576;
	head_st -> next = malloc(sizeof(list_st));
	tmp = head_st;
	head_st = head_st -> next;
	head_st -> previous = tmp;

	strcpy(head_st -> record.symbol, "SP");
	head_st -> record.value = 0;
	head_st -> next = malloc(sizeof(list_st));
	tmp = head_st;
	head_st = head_st -> next;
	head_st -> previous = tmp;

	strcpy(head_st -> record.symbol, "LCL");
	head_st -> record.value = 1;
	head_st -> next = malloc(sizeof(list_st));
	tmp = head_st;
	head_st = head_st -> next;
	head_st -> previous = tmp;

	strcpy(head_st -> record.symbol, "ARG");
	head_st -> record.value = 2;
	head_st -> next = malloc(sizeof(list_st));
	tmp = head_st;
	head_st = head_st -> next;
	head_st -> previous = tmp;

	strcpy(head_st -> record.symbol, "THIS");
	head_st -> record.value = 3;
	head_st -> next = malloc(sizeof(list_st));
	tmp = head_st;
	head_st = head_st -> next;
	head_st -> previous = tmp;

	strcpy(head_st -> record.symbol, "THAT");
	head_st -> record.value = 4;
	head_st -> next = NULL;
	return head_st_2_return;
}


list_st* add_2_st(pair this, list_st* head)
{
	head -> previous = malloc(sizeof(list_st));
	list_st* tmp = head;
	head = head -> previous;
	head -> record = this;
	head -> previous = NULL;
	head -> next = tmp;
	return head;
}

bool search_st(pair this,const list_st* head)
{
	if(head == NULL) error();
	while(head != NULL)
	{
		if(head -> record == this)
		{
			return true;
		}
		else
		{
			head = head -> next;
		}
	}
	return false;
}

char* substring(const char* label, int from , int to)
{
	if(strlen(label) > 50) error();
	char  sub_label[50];
	int j = 0;
	for(int i = from, i <= to, i++)
	{
		sub_label[j] = label[i];
		j++;
	}
	return sub_label;
}

list_e* mid_exact_code(list_p* head_p, list_st* head_st)
{
	if(head_p == NULL || head_st == NULL) error();
	list_e* head_e = malloc(sizeof(list_e));
	pair tmp_pair;

	while(head_p != NULL)
	{
		if(head_p->line[0] == '(' && head_p->line[strlen(head_p->line)-1] == ')')
		{
			char* lbl_ptr = 
		}
	}
}













list_e* exact_code_builder(list_p* head_p, list_st* head_st)
{
	list_e* head_e = malloc(sizeof(list_e));
	pair tmp_pair;
	while(1)
	{
		if(head_p -> line[0] == '@')
		{
			strcpy(head_e -> )
		}
	}
}

