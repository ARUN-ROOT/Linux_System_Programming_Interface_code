/* 
Name	: log creation with Filename , Date , Time ,Line Number with Message
Date	: 21/12/2022
Descrition : 
 
 */


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
#define LOG(msg,i) ({ \
     logFd=open("log.txt",O_CREAT|O_RDWR|O_APPEND,S_IRWXU);\
     write(logFd,msg,strlen(msg));\
     })*/
/*
     
    
#define LOG(msg,i) ({ \
     char line[10];\
     char *date,*file,*time;\
     int n,n1,n2,n3,n4;\
     file=__FILE__ ;\
     date=__DATE__ ;\
     time=__TIME__ ;\
     sprintf(line,"%d",i);\
     n1=strlen(file);\
     n2=strlen(date);\
     n3=strlen(time);\
     n4=strlen(msg);\
     n=( strlen(file)+ strlen(date) + strlen(time) + strlen(msg) );\
     printf("total %d\n",n);\
     char str[n];\
     strcpy(str,file);\
     strcat(str," ");\
     strcat(str,date);\
     strcat(str," ");\
     strcat(str,time);\
     strcat(str," ");\
     strcat(str,line);\
     strcat(str," ");\
     strcat(str,msg);\
     printf("%s\n",str);\
     logFd=open("log.txt",O_CREAT|O_RDWR|O_APPEND,S_IRWXU);\
     write(logFd,str,strlen(str));\
     })  
     */


     
    
#define LOG(msg,i) ({ \
     char line[10];\
     int n;\
     sprintf(line,"%d",i);\
     n=( strlen(__FILE__)+ strlen(__DATE__) + strlen(__TIME__) + strlen(line)+ strlen(msg) );\
     printf("total %d\n",n);\
     char str[n];\
     strcpy(str,__FILE__);\
     strcat(str," ");\
     strcat(str,__DATE__);\
     strcat(str," ");\
     strcat(str,__TIME__);\
     strcat(str," ");\
     strcat(str,line);\
     strcat(str," ");\
     strcat(str,msg);\
     printf("%s\n",str);\
     logFd=open("log.txt",O_CREAT|O_RDWR|O_APPEND,S_IRWXU);\
     write(logFd,str,strlen(str));\
     })  
     

int main(int argc, char *argv[])
{    
  int fd,logFd,line=0;
 
  
  fd=open("A.txt",O_CREAT|O_RDWR,S_IRWXU);
  
  //printf("Line number is: %s\n",__DATE__);

  
  LOG (" Write Success\n",__LINE__);
  
  
  printf("Kindly check log file\n");
  close(logFd);

     
  
}

