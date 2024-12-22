/************************************************************************************************************/
/* Name			: getcwd()	                                      */	   
/* Date			: 21/1/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
/*			                                                                                     */
/* o/p				: 
arun@arun:~/practise$ ./a.out
/home/arun/practise

 

*/
                                                                                        
/************************************************************************************************************/

#include <unistd.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
  char cwd[1024];
  
  //char *getcwd(char *buf, size_t size);
  getcwd(cwd,sizeof(cwd));

  printf("%s\n",cwd);
  
}
