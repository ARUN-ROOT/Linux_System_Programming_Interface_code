/*
* Name		: 
* Date		: 11/5/23			
* Author	: 
* Descrption	:
* Output	:
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

# define SIZE 512

int main()
{ 
  int fd1,fd2,flag,mode;
  flag=O_CREAT | O_RDWR | O_APPEND;
  mode = S_IRWXU | S_IRWXG | S_IRWXO ;
  ssize_t numread;
  char arr[SIZE];
  int ulink;
  char header[1024]="HTTP/1.1 200 OK\nContent-type:text/html\nConnection: close\n\n";
                   
 
  int sock_fd,c_fd;
  
  //char servermsg[]="How are u";
  
  sock_fd=socket(AF_INET,SOCK_STREAM,0);
  
  struct sockaddr_in serveraddress;
  serveraddress.sin_family=AF_INET;
  serveraddress.sin_port=htons(8108);
  serveraddress.sin_addr.s_addr=inet_addr("127.0.0.1");
  
 // ulink=unlink("./socket");
  perror("unlink");
  
  
  // int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
  bind(sock_fd,(struct sockaddr*)&serveraddress,sizeof(serveraddress));
  perror("bind()");
  
  // int listen(int sockfd, int backlog);
  listen(sock_fd,5);
  perror("listen()");
  
  // int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
  c_fd=accept(sock_fd,NULL,NULL);
  perror("accept()");
  
  //receive notification from client
  char clientmsg[1024];
  recv(c_fd,clientmsg,254, 0);
  printf("%s\n",clientmsg);
    


  
  
  
    //fd1=open("./index.html",flag,mode);//open HTML file in curent diretory
    fd1=open("./index.html",O_RDONLY);//open HTML file in curent diretory
     perror("open()");
   //*****************************   
    char buf[1024];
    ssize_t read_byte;
    read_byte=read(c_fd,buf,1024);
    perror("read()");
    
    buf[read_byte+1]='\0';
    printf("%s",buf);
    //*****************************
    
     write(c_fd,header,1024);
     perror("write()");
  
    numread =read(fd1,arr,SIZE);//read file open html and store it to arr 
    perror("read()");
    
    arr[numread+1]='\0';//Add null byte end of read html file
    printf("%s",arr);
    
    write(c_fd,arr,numread);
    perror("write()");
  
    printf("%s",arr); 
    close(c_fd);  
    close(sock_fd);

   
  return 0;  
}









