arun@arun:~/Exercise Linux/29_static_Library/Task5$ gcc -c header.c
arun@arun:~/Exercise Linux/29_static_Library/Task5$ ar -rcs test.a header.o
arun@arun:~/Exercise Linux/29_static_Library/Task5$ gcc -o info main.c test.a 
arun@arun:~/Exercise Linux/29_static_Library/Task5$ ./info arun 25
your age 25 
your name arun 
arun@arun:~/Exercise Linux/29_static_Library/Task5$ 




header.h	header.c	main.c(argv[])

		header.o	
		
		ar -rcs test.a header.o
		
		gcc -o info main.c test.a
	
			./info arun 25
			
			o/p:your age:25
