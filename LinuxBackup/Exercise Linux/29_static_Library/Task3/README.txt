arun@arun:~/Exercise Linux/29_static_Library/Task3$ gcc main.c
/usr/bin/ld: /tmp/ccM05BQ3.o: in function `main':
main.c:(.text+0xe): undefined reference to `num'
collect2: error: ld returned 1 exit status
arun@arun:~/Exercise Linux/29_static_Library/Task3$ gcc -c header.c 
arun@arun:~/Exercise Linux/29_static_Library/Task3$ ls
header.c  header.h  header.o  main.c
arun@arun:~/Exercise Linux/29_static_Library/Task3$ ar -rcs demo.a header.o
arun@arun:~/Exercise Linux/29_static_Library/Task3$ ls
demo.a  header.c  header.h  header.o  main.c
arun@arun:~/Exercise Linux/29_static_Library/Task3$ gcc main.c demo.a 
arun@arun:~/Exercise Linux/29_static_Library/Task3$ ./a.out
your number 25 
arun@arun:~/Exercise Linux/29_static_Library/Task3$ 


