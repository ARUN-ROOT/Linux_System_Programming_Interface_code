/************************************************************************************************************/
/* Name			: dup                                      */	   
/* Date			: 7/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
/*			                                                                                     */
/* o/p				: 
arun@arun:~/practise$ gcc practise.c
arun@arun:~/practise$ ./a.out
before dup fd 3
before dup copyfd 0
After dup fd 3
After dup copyfd 4
arun@arun:~/practise$ 

*/
                                                                                        
/************************************************************************************************************/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>



int main(int argc,char *argv[])
{
 int fd;
 int copyfd;
 
 fd=open("a.txt",O_CREAT|O_APPEND|O_WRONLY);
 if(fd==-1)
 {
   perror("error in open");
   exit(-1);
 }
 printf("before dup fd %d\n",fd);
 printf("before dup copyfd %d\n",copyfd);
 
 //int dup(int oldfd);
 copyfd=dup(fd);//lowest fd value occupy.
 printf("After dup fd %d\n",fd);
 printf("After dup copyfd %d\n",copyfd);
 
 write(copyfd,"ARUN",5);//using copyfd write operation in same file.Already know fd also used to write same file.
 
 
 
 

}
 
