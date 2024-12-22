all:test.o
	./test
test.o:test.c
	gcc -o test test.c
test.c:
	echo "#include <stdio.h> \n int main() \n { \n printf("\"welcome"\");\n }" >test.c
clean:
	rm test.c test
