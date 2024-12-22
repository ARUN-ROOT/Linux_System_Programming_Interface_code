/* 
Name			: 
Date			: 4/1/2023
Author			: Arun.V
Code link		:
Descrition		: open txt file ,parent write something and Child Write something
o/p			:


 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{ 

  int fd;
    
  fd=open("test.txt",O_CREAT|O_RDWR|O_APPEND,S_IRWXU);
  if(fd==-1)
  {
    perror("open()");
  }
    
  pid_t pid;
  
  pid=fork();
  
  if(pid==-1)
  {
    printf("failed to create child process\n");
  }
  else if(pid==0)
  {
    printf("Child Process \n");
    char *str="I am child\n";
    write(fd,str,strlen(str));
    printf("Child write sucess\n");
  }
  else
  {
    printf("Parent Process \n");
    wait(NULL);
    char *arr="Hai i am parent updated\n";
    write(fd,arr,strlen(arr));
    printf("Parent write sucess\n");
      
  }
  
  close(fd);
}
