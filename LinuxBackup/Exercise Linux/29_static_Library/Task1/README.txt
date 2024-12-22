How to Create static library

Step 1 : Create Headerfile.h arthimetic.h in that prototype of functions
	int add(int a,int b);
	int sub(int a,int c);
	
step 2 : Create seperate Source file () in that function definition
	add.c 
	int add(int a,int b)
	{
	 return a+b;
	} 
	
	sub.c
	int sub(int a,int b)
	{
	 return a-b;
	} 
	
step 3: Create Obj file
        gcc -c add.c 
        gcc -c sub.c
        so add.o and sub.o automatically created.
        
Step 4: Create archieve file
        ar -rs libraryname.h add.o sub.o
        
step 5: Create Main file main.c
	#include <stdio.h>
	#include "arthimetic.h"
	
	int a=5,b=2;
	
	void main()
	{
	 printf("add %d sub %d \n",add(a,b),sub(a,b));
	}
	
step 6: gcc main.c libarth.a
        ./a.out
        
        
Note: Delete source files add.c sub.c 
      Delete Obj files add.o sub.o
      
      Just Run,gcc main.c libarth.a
               ./a.out
               
For Giving customers, Only Header.h libarth.a main.c
	
	
	
