#include<stdio.h>
#include<stdlib.h>


typedef struct list{
	char line[500];
	struct list* next;
}list;

// load function: this functions loads the file into the memory as a linked list
// input: the file name
// return: pointer to the head of the list
list* load(const char* filename)
{
	FILE* fptr = fopen(filename, "r"); // open the file
	if(fptr == NULL) // check the pointer, and make sure everything is ok
	{
		printf("error opening the file \n"); // if :(, tell the client and exit
		exit(1);
	}
	list* head = malloc(sizeof(list)); // oooooh, mallooooooooooc
	list* head_2_return = head; // this is a copy of "head" to return it later
	                            // I'm doing this, since i need to append 
                                // to the list. i.e. (Keeping it in order)
	while(1)                    
	{
        int m = 0; // This is used to BRAKE the loop
		int i = 0; // This is to index the characters of each line
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
		head -> next = malloc(sizeof(list)); // allocate memory for the next line
		head = head -> next; // deal with the head of the list
	}
	head -> next = NULL; // terminate the list with "NULL"

	fclose(fptr); // close the file (hygiene)
	return head_2_return;
}

void print_list(list* head)
{
	while(head != NULL)
	{
		int i = 0;
		while(1)
		{
			printf("%c", head -> line[i]);
			if((head -> line[i]) == '\n') break;
			i++;
		}
		head = head -> next;
	}
}

