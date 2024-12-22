/************************************************************************************************************/
/* Name : ashell                                   */  
/* Date : 2/1/2023                                                                  */
/* Author : Arun.V                                                                     */
/* Code link :        */
/* Descrition : */
/*                                                                                     */
/* o/p :

 

*/
                                                                                       
/************************************************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "ashellcolors.h"

#define BUILTIN_COMMANDS 5	

char pwd[1024];
char path[1024];


void shell();
char *readcommandline(void);
int shell_execute(char **args);

char * builtin[] = {"cd", "exit", "help", "pwd", "echo"};
/*******************************************************************************/
int shell_cd(char ** args){
	if (args[1] == NULL){
		fprintf(stderr, "minsh: one argument required\n");
	}
	else if (chdir(args[1]) < 0){
		perror("minsh");
	}
	getcwd(pwd, sizeof(pwd));	// Update present working directory
	return 1;
}
int shell_exit(char ** args){
	return 0;
}

int shell_help(char ** args){
	printf("\nA mini implementation of the Unix Shell by Arun and Muthu.\n");
	printf("\nCommands implemented: ");
	printf("\n\t- help");
	printf("\n\t- exit");
	printf("\n\t- pwd");
	printf("\n\t- echo");
	printf("\n\t- ls");
	printf("\n\t- mkdir-dir1-[dir2 ...]");
	printf("\n\t- rmdir-dir1-[dir2 ...]");
	printf("\n\t- cat-[file1 file2 ...]");
	printf("\n\t- mv-filename1-filename2");
	printf("\n\t- rm-filename");
	printf("\n\t- clear");
	
	printf("\n\n");
	printf("Any Doubt in this ashell contact: ");
	printf("Arun-7402548630 Muthu-6380695575");
	printf("\n\n");
	return 1;
}

int shell_pwd(char ** args){
	printf("%s\n", pwd);
	return 1;
}
int shell_echo(char ** args){
	int i = 1;
	while (1){
		// End of arguments
		if (args[i] == NULL){
			break;
		}
		printf("%s ", args[i]);
		i++;
	}
	printf("\n");
}
int (* builtin_function[]) (char **) = {
	&shell_cd,
	&shell_exit,
	&shell_help,
	&shell_pwd,
	&shell_echo
};
/*******************************************************************************/
int main(int argc,char *argv[])
{
  
  //char *getcwd(char *buf, size_t size);
  getcwd(pwd,sizeof(pwd));
  
  strcpy(path,pwd);
  strcat(path,"/cmds/");
  printf("%s\n",path);
  shell();

  return 0;
}

void shell()
{
   char *commandline;
   char **arguments;
   int status;
   int n=0,i=0;
   char arr[1024];
   
   printf("\n******************************************\n");
   printf("\tEach Command arguments seperated by '-'\n");
   printf("\tyour command must echo-arun\n");
   printf("\ttype help shows list of commands implementation\n");
   printf("********************************************\n");
   
   status=1;
   while(status)
   {
      printf(GREEN"ashell$");
      
     commandline=readcommandline();/***>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>calling>>>>>>>>>>>>>>>**/
    // printf("your command : %s\n",commandline);
    
     n=strlen(commandline);
      for(i=0;i<n;i++)
      {
      arr[i]=commandline[i];
     
      }
      arr[n]='\0';
     // printf("%s\n",arr);
     
      char *token=strtok(arr,"-");
      int position = 0;
      int no_of_tokens = 64;
      char ** tokens = malloc(sizeof(char *) *no_of_tokens);
      while(token!=NULL)
      {
         //printf("%s\n",token);
         tokens[position]=token;
         position++;
         token=strtok(NULL,"-");
      }
      tokens[position] = NULL;
      arguments=tokens;
      status=shell_execute(arguments);
      
      
   }
  
}

char *readcommandline()
{
   char c;
   int count=0;
   char *arrcommand=(char*)malloc(sizeof(char)*1024);
   //printf("Enter command ");
   c=getchar();
   while(c!='\n')
   {
     arrcommand[count]=c;
     count++;
     c=getchar();
   }
   
   return arrcommand;
   
 
}

int status_process (char **args)
{
  int status;
  pid_t pid,wpid;
  
  pid=fork();
  
  if(pid==0)//child process
  {
     char cmd_dir[1024];
     strcpy(cmd_dir,path);
     strcat(cmd_dir,args[0]);
     
     //execute cmd using excutable file of that command
     if(execv(cmd_dir,args)==-1)
     {
     printf("error");
     }
     exit(-1);
  }
  else if(pid<0)
  {
  printf("child process not created");
  }
  else
  {
    do
    { 
      wpid=waitpid(pid,&status,WUNTRACED);
    }while(!WIFEXITED(status)&&!WIFSIGNALED(status));
    
  }
  return 1;
}

int shell_execute(char **args)
{
 // printf("inside shell execute\n");
 /* printf("args[0] %s\n",args[0]);
  printf("args[1] %s\n",args[1]);*/
  
   if(args[0]==NULL)
  {
     return 1;
  }
  
  int std_in,std_out,std_err;
  std_in = dup(0);
  std_out = dup(1);
  std_err = dup(2);
  
 for(int i = 0 ; i < BUILTIN_COMMANDS ; i++){
		if ( strcmp(args[0], builtin[i]) == 0 ){
			int ret_status = (* builtin_function[i])(args);
			
			// Restore the Standard Input and Output file descriptors
			dup2(std_in, 0);
			dup2(std_out, 1);
			dup2(std_err, 2);

			return ret_status;
		}
	}
  
  int ret_status=status_process(args);//fork used child process execute commands parent processs wait until child complete
        dup2(std_in, 0);
	dup2(std_out, 1);
	dup2(std_err, 2);

	return ret_status;

}


