# This is a comment

#out: assembler.c functions.o
#	gcc -o out assembler.c functions.o
#
#functions.o: functions.c dict.o
#	gcc -c functions.c dict.o
#
#dict.o: dict.c
#	gcc -c dict.c
#
#

out: assembler.c functions.c dict.c
	gcc -o out assembler.c functions.c dict.c
