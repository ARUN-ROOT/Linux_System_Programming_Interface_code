#include <stdio.h>

int main()
{
int sum=0,num,in=0;
printf("Enter How many num : ");
scanf("%d",&num);
for(int i=0;i<=num;i++)
{
	scanf("%d",&in);

sum=sum+in;
i++;
}
printf("%d\n",sum);
printf("Hai\n");
return 0;
}
