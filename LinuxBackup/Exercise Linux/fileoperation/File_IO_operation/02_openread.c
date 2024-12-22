/* 
Name	: return type checking.
Date	: 14/12/2022
Descrition : open a file write something 
             Read that file and store it buffer.
             read retuen type is ssize_t (in bytes)print it using  %ld;
             print stringlen in that stored buffer
             print it output terminal
             close that file
             Note:Each character has 1 byte
o/p	: arun@arun:~/practise$ gcc practise.c -o practise
	arun@arun:~/practise$ ./practise 
	success with fd : 3
	numread (in Bytes)  11
	reading string length from file 11
	Hai Arun  

 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define SIZE 512

int main(int argc, char *argv[])
{
int fd,flag,i,j;
mode_t mode;
ssize_t numread;
char arr[SIZE];

flag = O_CREAT;
mode = S_IRWXU;

fd=open("A.txt",flag,mode);
if(fd==-1)
{
  perror("open()");
  exit(-1);
}
else
{
  printf("success with fd : %d\n",fd);
}
numread =read(fd,arr,SIZE);
printf("numread (in Bytes)  %ld\n",numread);//ARUN (4+1)5/(Character +1 )
printf("reading string length from file %d\n",j=strlen(arr));//5 
for(i=0;i<=numread;i++)
{
  printf("%c",arr[i]);
}

close(fd);


}

