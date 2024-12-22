/************************************************************************************************************/
/* Name			:   setuid()                    */						
/* Date			: 12/1/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			:  using setuid open txt file in another home directory from current directory */ 
/* Descrition			:  create 1 txt file in another usr change permision to rw- rw- --- .	*/
/*				    return back to arun login , Run this code*/
/*			                                                                                     */
/* o/p				: 
arun@arun:~/practise$ sudo ./a.out 1006 "/home/test/test.txt"
Hello World !! 
Before setuid
uid : 0 
Afterr setuid
uid : 0 
uid : 1006 
success


*/
                                                                                        
/************************************************************************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(int argc,char *argv[])
{ 
   int uid=atoi(argv[1]);
   int fd;
    
    printf("Hello World !! \n");
    printf("Before setuid\n");
    printf("uid : %d \n",getuid());
    printf("Afterr setuid\n");
    printf("uid : %d \n",setuid(uid));
    printf("uid : %d \n",getuid());
    
  fd=open(argv[2],O_CREAT|O_RDWR,S_IRWXO|S_IRWXU|S_IRWXG);
  if(fd==-1)
  {
    printf("error opening file\n");
  }
  else
  {
    printf("success\n");
  }

  close(fd);    
    
}


