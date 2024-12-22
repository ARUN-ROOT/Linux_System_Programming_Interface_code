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

int main(int argc, char *argv[])
{    
    int fd,flag,l_no,fl_no=0,i;
    char arr[SIZE];
    ssize_t numread,numwrite;
    mode_t mode;
    off_t fp;
    
    flag=O_CREAT | O_RDWR ;
    mode = S_IRWXU;
    
    fd=open("A.txt",flag,mode);
    
    numread= read(fd,arr,512);
    
    printf("content in txt file\n");
    numwrite=write(1,arr,numread);
    printf("*******\n");
    
    printf("line from : %s \n",argv[1]);
    l_no = atoi (argv[1]);
    
    fp=lseek(fd,0,SEEK_SET);
    printf("file pointer position : %ld\n",fp);
    
    for(i=0;i<numread;i++)
    {
      if(arr[i]=='\n')
      {
         fl_no++;
         printf("%d\n",fl_no);
      }
      if(fl_no==l_no)
      {
         fp=fl_no+1;
         break;
      }
    }
    lseek(fd,fp,SEEK_CUR);
    printf("Hai\n\n");
    
    numread= read(fd,arr,SIZE);
    write(1,arr,numread);
    
    
    
    
    
    
  
  
}

