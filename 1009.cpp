#include<stdio.h>

main()
{
	double polya[1001];
	double polyb[1001];
    double polyc[2001];
	int i;
	for(i=0;i<1001;i++)
	{
		polya[i] = 0;
		polyb[i] = 0;
	}
	for(i=0;i<2001;i++)
	polyc[i] = 0; 
	
	int k,j;
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
    	if(polya[i]==0)
    	continue;
        for(j=0;j<1001;j++)
		if(polyb[j]!=0)
		{
		  polyc[i+j] += polya[i]*polyb[j]; 
		}    	
    }
    for(i=0;i<2001;i++) 
    if(polyc[i]!=0)
    count++;
    
    printf("%d",count);
    for(i=2000;i>=0;i--)
    if(polyc[i]!=0)
    printf(" %d %.1lf",i,polyc[i]);
	
	
	
	return 0;
 } 
