/* 
Name	: 
Date	: 14/12/2022
Descrition :give input in command and get it back
	Try one by one one code Library function used
	another one System calls used
	due to this we get Garbage value         Actually flw is Library fn --> Syscalls ---> Kernel 
o/p	: arun@arun:~/practise$ ./practise 
ARUN
ARUN


 */


#include <stdio.h>
#include <unistd.h>
#include <string.h>

# define SIZE 1024

int main()
{
 /* char arr[SIZE];
  read(STDIN_FILENO,arr,SIZE); 
  write(STDOUT_FILENO,arr,strlen(arr));*/
  
  
  char arr[SIZE];
  ssize_t numread;
  numread = read(STDIN_FILENO,arr,SIZE); 
  write(STDOUT_FILENO,arr,numread);//Here
  
  /*   write( STDOUT_FILENO,arr,numread  );  //space include*/
  
}

