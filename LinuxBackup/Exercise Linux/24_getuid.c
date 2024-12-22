/************************************************************************************************************/
/* Name			:   getuid()                    */						
/* Date			: 11/1/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			:                                                                            */
/* Descrition			:  									*/
/*			                                                                                     */
/* o/p				: 
arun@arun:~/practise$ ./a.out
Hai
UID 1000 
arun@arun:~/practise$ 

*/
                                                                                        
/************************************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>



int main(int argc,char *argv[])
{ 
    printf("Hai\n");
    //uid_t getuid(void);
    printf("UID %d \n",getuid());
}


