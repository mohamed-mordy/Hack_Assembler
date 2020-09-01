#include"testers.h"

void print_green(const list_g* head)
{
	while(head != NULL)
	{
		int i = 0;
		printf("%d ", head -> line_no_green);
		while(1)
		{
			printf("%c", head -> line[i]);
			if((head -> line[i]) == '\n') break;
			i++;
		}
		head = head -> next;
	}
}

void print_pure(const list_p* head)
{
	while(head != NULL)
	{
		printf("%d", head -> line_no_green);
		printf("\t");
		printf("%d", head -> line_no_pure);
		printf("\t");
		printf("%s", head -> line);
		printf("\n");
		head = head -> next;
	}
}

void print_st(list_st* head)
{
	while(head != NULL)
	{
		printf("%s\t%d\n", head -> record.symbol, head -> record.value);
		head = head -> next;
	}
}

