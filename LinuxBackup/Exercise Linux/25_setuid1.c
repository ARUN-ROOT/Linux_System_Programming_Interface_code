/************************************************************************************************************/
/* Name			:   setuid()                    */						
/* Date			: 12/1/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			:   */ 
/* Descrition			:  	*/

/*			                                                                                     */
/* o/p				: 
arun@arun:~/practise$ gcc practise.c
arun@arun:~/practise$ ./a.out 1001
Hello World !! 
Before setuid
uid : 1000 
Afterr setuid
uid : -1 
uid : 1000 
arun@arun:~/practise$ sudo ./a.out 1006
[sudo] password for arun: 
Hello World !! 
Before setuid
uid : 0 
Afterr setuid
uid : 0 
uid : 1006 
arun@arun:~/practise$ 


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
  
    
    printf("Hello World !! \n");
    printf("Before setuid\n");
    printf("uid : %d \n",getuid());
    printf("Afterr setuid\n");
    printf("uid : %d \n",setuid(uid));
    printf("uid : %d \n",getuid());
    
  
}


