/* 
Name	: 
Date	: 14/12/2022
Descrition : without printf shows output
o/p	: arun@arun:~/practise$ gcc practise.c -o practise
	arun@arun:~/practise$ ./practise 
	ARUNarun@arun:~/practise$
 */


#include <stdio.h>
#include <unistd.h>

int main()
{
 //Try one by one 
 write(STDOUT_FILENO,"ARUN",4);  //ARUNarun@arun:~/practise$
 write(STDOUT_FILENO,"ARUN\n",4); //ARUNarun@arun:~/practise$ 
 write(STDOUT_FILENO,"ARUN\n",5); //ARUN
                                    //arun@arun:~/practise$ 

}

