/* 
Name	: 
Date	: 16/12/2022
Descrition : lseek tail command
              user want to print last 5 line
O/P:




 */


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define SIZE 3421

int main(int argc, char *argv[])
{    
  int fd,userl_no=0,i,filel_no=0,temp=0,cursor=0;
  char arr[SIZE];
  ssize_t numread;
  off_t fp=0,m_fp=0,m_fp_eachline[SIZE]={0},count=1;//WITHOUT ARRAY SIZE HOW DCLARED
  
  
  userl_no= atoi(argv[1]);
  
  fd=open("A.txt",O_RDONLY);
  if(fd==-1)
  {
    perror("open()");
    exit(-1);
  }
  
  numread=read(fd,arr,SIZE);
  if(numread == -1)
  {
    perror("read()");
    exit(-1);
  }
  //*******line number*******////
  fp=lseek(fd,0,SEEK_SET);//cursor move to 0th place
  perror("lseek()");
  
  for( i= 0;i<numread;i++)
  {  
    m_fp++;//moving file pointer
    
   if(arr[i]== '\n')  //finding nxt line
   { 
     m_fp_eachline[count]=m_fp; //Each nxt line moving pointer value stored in array
     filel_no++; //line number increase
     count++;    //array count increase
     
   } 
    
   
  }
  printf("filel_no : %d\n",filel_no);//Total Number of lines print here
  for(int x=0;x<count;x++)
  {
    printf("m_fp_eachline[%d] : %ld \n",x,m_fp_eachline[x]);//Print all moving file pointer value in array
  }
  cursor=filel_no-userl_no;// Cursor move at particular line user 3 // 50=53-3 
  printf("cursor %d\n",cursor);
  
  lseek(fd,m_fp_eachline[cursor],SEEK_CUR);//that cursor moving file pointer,put in SEEK_CUR
  perror("lseek()");
  
  numread=read(fd,arr,SIZE);
  write(1,arr,numread);

  close(fd);
    
}

