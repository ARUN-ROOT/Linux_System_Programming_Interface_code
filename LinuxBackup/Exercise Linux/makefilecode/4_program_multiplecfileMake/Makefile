all:test
	./test
test:main.o add.o
	gcc main.o add.o -o test
main.o:main.c
	gcc -c main.c -o main.o
add.o:add.c
	gcc -c add.c -o add.o
clean:
	rm main.o add.o test
