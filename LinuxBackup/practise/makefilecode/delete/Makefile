all:linker
	./exe
linker:fileopen.o
	gcc fileopen.o -o exe
fileopen.o:01_fileopen.c
	gcc -c 01_fileopen.c -o fileopen.o
clean:
	rm fileopen.o exe A.txt
