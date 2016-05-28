#include<stdio.h>

main()
{
	int n;
	int a[100];
	scanf("%d",&n);
	int i ;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	int sum = 0;
	sum = sum + a[0]*6;
	for(i=0;i<n-1;i++)
	{
		if(a[i+1]>a[i])
		sum = sum + 6*(a[i+1]-a[i]);
		if(a[i+1]<a[i])
		sum = sum + 4*(a[i] - a[i+1]);
	}
	
	sum = sum + 5*n;
	printf("%d",sum);
	
	
	
	
	return 0;
}
