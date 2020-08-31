/**************************************************************************************************/
/*********************************************Authorship*******************************************/
/**
  * Author: Mohamed M. A. Mordy

  * Date & time: August 31, 2020. 4:30 AM

  * Aim: Design and implementation of an assembler for the HACK platform, translates from
         the HACK assemply language to the HACK machine language

  * Notes: 1. This project is part of the course "the elements of computing systems"
           2. This version(0.0) of the project is under major construction
		   3.
		   4.
 */	

/**********************************Preprocessor directives section*********************************/
#include<stdio.h>
#include<stdlib.h>
#include"functions.h"

/*******************************Global variables declarations section******************************/
/**************************************ADT declarations section************************************/
/***********************************Functions declarations section*********************************/

/*********************************fucntions implementations section********************************/
// main function: Mandatory for any C code to be executable
int main(int argc, char* argv[])
{
	if(argc != 2){
		printf("Usage: assembler *.asm\n");
		exit(1);
	}
	list* my_file_green = load(argv[1]);
	print_list(my_file_green);
	return 0;
}





/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

