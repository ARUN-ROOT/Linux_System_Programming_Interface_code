/* 
Name	: standard Macros
Date	: 14/12/2022
Descrition : standard macros
o/p	:arun@arun:~/practise$ gcc -o practise practise.c
	 arun@arun:~/practise$ ./practise 
0
1
2
 */


#include <stdio.h>
#include <unistd.h>

int main()
{
  printf("%d\n",STDIN_FILENO); // 0
  printf("%d\n",STDOUT_FILENO);// 1
  printf("%d\n",STDERR_FILENO);// 2

}

