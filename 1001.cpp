#include<stdio.h>

main()
{
int a,b;
scanf("%d%d",&a,&b);
int sum = a + b;

int flag;
int x[100]; //记录输出 
int n = 0;  //sum的位数

if(sum>0) flag = 1;
else if(sum<0) flag = -1;
else flag = 0;
sum = sum*flag;
while(sum>0)
{
	x[n] = sum%10;
	n++;
	sum /= 10;
 };

 if(flag==-1)
 printf("-");
 int i;
 for(i=n-1;i>=0;i--)
 {
 	printf("%d",x[i]);
 	if(i%3==0 && i!=0)
 	printf(",");
 }
 
 if(flag==0)
 printf("0");
 

 


return 0; 
} 
