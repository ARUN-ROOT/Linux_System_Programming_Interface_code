/* 
Name	: 
Date	: 24/12/2022
Descrition : 
 o/p	:
arun@arun:~/practise$ ./practise
hello world
Hai
hello world
Hai
Hai
Hai
arun@arun:~/practise$ gcc practise.c -o practise
arun@arun:~/practise$ ./practise
hello world
hello world
Hai
Hai
Hai
Hai


 */


#include <stdio.h>
#include <unistd.h>


int main()
{  
   fork();
   printf("hello world\n");      
   fork();                       
   printf("Hai\n");           

}

/*



*/
