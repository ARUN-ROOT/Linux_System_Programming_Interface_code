/*
Name		: File opening
Date		: 10/12/2022
Description	: creating 2 file and opening it.Checking fd is different .
                 put getchar() function hold this process open terminal run it. then 
                 ps -aux note pid number
                 cd /proc/pid/fd -ls
                 directly given filename
                 Note: use existing file with content , then only it display cat 3 cat 4
                       otherwise not display 
o/p: 
gcc 06_fileopen1.c -o 06_fileopen1
gcc ./06_fileopen1
Sucessfully open fileopen1 abc with fd : 3 
Sucessfully open fileopen1 xyzwith fd : 4 

arun@arun:~$ cd /proc/3094/fd
arun@arun:/proc/3094/fd$ ls
0  1  2  3  4
arun@arun:/proc/3094/fd$ cat 3
Hai Arun Welcomearun@arun:/proc/3094/fd$ cat 4
Gopi welcomearun@arun:/proc/3094/fd$               

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int open_flag,file_fd,file_fd2;
  mode_t file_mode;
  
  open_flag = O_CREAT;  //Create a new file
  file_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH ;//rw-rw-r-- permission
  
  /************opening file1 and print fd *******************/
  file_fd=open("x.txt",open_flag,file_mode);//open syscalls for openning file ,directly given filename
  if(file_fd== -1)//check for error
  {
  printf("error : opening a file \n");
  exit(-1);//stdlib.h exit
  }
  else
  {
  printf("Sucessfully open fileopen1 abc with fd : %d \n",file_fd);
  }
  
  /************opening file2 and print fd *******************/
  file_fd2=open("y.txt",open_flag,file_mode);//open syscalls for openning file ,directly given filename
  if(file_fd2== -1)//check for error
  {
  printf("error : opening a file \n");
  exit(-1);//stdlib.h exit
  }
  else
  {
  printf("Sucessfully open fileopen1 xyz with fd : %d \n",file_fd2);
  }
  
  getchar();//hold the process until press key from Keyboard.
  close(file_fd);
  close(file_fd2);

}
