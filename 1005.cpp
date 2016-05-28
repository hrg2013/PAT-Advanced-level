#include<stdio.h>

main()
{
	char N[120];
	int i;
	int a[100];
	scanf("%s",N);
	int sum = 0;
	i=0;
	while(48<=N[i]&&N[i]<=57)
	{sum = sum + N[i]-48;  i++;}
	if(sum==0)
	{printf("zero");
	return 0;
	}
	i = 0;
	while(sum>0)
	{
		a[i] = sum%10;
		i++;
		sum = sum/10;
	 }; 
	 int j;
	 for(j=i-1;j>0;j--)
	 {

	 	if(a[j]==0) printf("zero ");
	 	if(a[j]==1) printf("one ");
	 	if(a[j]==2) printf("two ");
	 	if(a[j]==3) printf("three ");
	 	if(a[j]==4) printf("four ");
	 	if(a[j]==5) printf("five ");
	 	if(a[j]==6) printf("six ");
	 	if(a[j]==7) printf("seven ");
	 	if(a[j]==8) printf("eight ");
	 	if(a[j]==9) printf("nine ");	 	
	 }

	 	if(a[j]==0) printf("zero");
	 	if(a[j]==1) printf("one");
	 	if(a[j]==2) printf("two");
	 	if(a[j]==3) printf("three");
	 	if(a[j]==4) printf("four");
	 	if(a[j]==5) printf("five");
	 	if(a[j]==6) printf("six");
	 	if(a[j]==7) printf("seven");
	 	if(a[j]==8) printf("eight");
	 	if(a[j]==9) printf("nine");
	

	return 0;
}
