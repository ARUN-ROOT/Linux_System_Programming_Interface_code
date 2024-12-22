/* 
Name	: 
Date	: 15/12/2022
Descrition :
o/p	: 

 */


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define SIZE 512

int main()
{    
    int fd,flag;
    char arr[SIZE];
    ssize_t numread;
    mode_t mode;
    
    flag=O_CREAT | O_RDWR ;
    mode = S_IRWUSR;
    
    fd=open("A.txt",flag,mode);
    numread= (0,arr,512);
    numwrite=(fd,arr,numread);
    
  
  
}

