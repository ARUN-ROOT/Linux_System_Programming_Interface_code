/* 
Name	: 
Date	: 15/12/2022
Descrition :
o/p	: arun@arun:~/practise$ gcc practise.c -o practise
arun@arun:~/practise$ ./practise 
arun
arun
���@���`

arun@arun:~/practise$ gcc practise.c -o practise
arun@arun:~/practise$ ./practise 
arun
arun

 */


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define SIZE 512

int main()
{   char arr[SIZE];
    ssize_t numread;
  
 /* read(0,arr,512); //reading from terminal store in arr
    write(1,arr,512);*/  // writing to terminal with Garbage value
  
 
    numread=read(0,arr,512); //solve above issue ,Here variable stored numread
    write(1,arr,numread);//numread used here
  
  
  
}

