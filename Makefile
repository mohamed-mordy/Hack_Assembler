# This is a comment

objects = assembler.o functions.o dict.o

asm: $(objects)
	gcc -o asm $(objects); rm *.o;

assembler.o: assembler.c functions.h
	gcc -c assembler.c

functions.o: functions.c functions.h dict.h
	gcc -c functions.c

dict.o: dict.c dict.h
	gcc -c dict.c


.PHONY: clean
clean:
	rm *.hack *.o *.exe
