#include<stdio.h>

main()
{
	double polya[1001];
	double polyb[1001];
	int i;
	for(i=0;i<1001;i++)
	{
		polya[i] = 0;
		polyb[i] = 0;
	}
	
	int k;
	int e;
	double c;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
	    scanf("%d%lf",&e,&c);
	    polya[e] = c;
	}
	
		scanf("%d",&k);
	for(i=0;i<k;i++)
	{
	    scanf("%d%lf",&e,&c);
	    polyb[e] = c;
	}
    
    int count = 0;
    for(i=0;i<1001;i++)
    {
    	polya[i] = polyb[i] + polya[i];
    	if(polya[i]!=0)
    	count++;
    }
    printf("%d",count);
    for(i=1000;i>=0;i--)
    if(polya[i]!=0)
    printf(" %d %.1lf",i,polya[i]);
	
	
	
	return 0;
 } 
