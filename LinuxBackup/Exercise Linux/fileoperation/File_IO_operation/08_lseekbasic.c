/* 
Name	: 
Date	: 14/12/2022
Descrition : create a file and write a content 1234567890abcdefghij!@#$%^&*()
o/p	: arun@arun:~/practise$ gcc practise.c -o practise
arun@arun:~/practise$ ./practise 
1234567890!@#$%^&*()arun@arun:~/practise$ 



 */


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define SIZE 10

int main()
{
  int open_flag,fd;
  mode_t file_mode;  
  char arr[SIZE];
  ssize_t numread;
  
  
  
  open_flag = O_CREAT;  //Create a new file
  file_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH ;//rw-rw-r-- permission
  
  fd=open("A.txt",open_flag,file_mode);//open syscalls for openning file ,directly given filename
  
/*read( fd,arr,SIZE );//open and read it. store in arr
  write(1,arr,SIZE ); //STDOUT_FILENO,arr,SIZE); 1234567890
 
  read( fd,arr,SIZE );
  write(1,arr,SIZE ); *///abcdefghij  O/P 1234567890abcdefghij

  
  
  read( fd,arr,SIZE );//open and read it. store in arr
  write(1,arr,SIZE ); //STDOUT_FILENO,arr,SIZE);1234567890
  lseek(fd,10,SEEK_CUR);//Here Cursor move (current location + offset)//(curr + 10)
   read( fd,arr,SIZE );//Now cursor change position and Read it.
   write(1,arr,SIZE ); //
 
  
}

