#include<stdio.h>

main()
{
	int n;
	scanf("%d",&n);
	int a[10000];
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	int first;
	int last;
    int max=-5;
    int r_f;
    int r_l;
    int sum;
	for(first=0;first<n;first++)
	{

		sum = 0;

		for(last = first;last<n;last++)
		{
			sum = sum + a[last];
			if(sum>max)
			   { max = sum; r_f = first; r_l = last;}
			
		}

	}
	if(max>=0)
	printf("%d %d %d",max,a[r_f],a[r_l]);
	else
	printf("0 %d %d",a[0],a[n-1]);
}
