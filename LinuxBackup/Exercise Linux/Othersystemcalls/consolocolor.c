/************************************************************************************************************/
/* Name			: Terminalcolors.c                                 */	   
/* Date			: 19/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
/*			          */
/* o/p				: 

*/
                                                                                        
/************************************************************************************************************/


#include <stdio.h>


int main(int argc,char *argv[])
{
  printf("Arun\n");
  printf("\x1b[31m" "ARUN\n");
  printf ("%s\n","\x1b[31;47m school of \x1b[34m linux\x1b[0m");
  printf("%s\n","\e[32mwelcome\033[0m");

  return 0;
}
 
