#include<stdio.h>

main()
{
     int P[100];
     int G[100][100];
     int N,M;
     scanf("%d%d",&N,&M);
     int i,j;
     int k,a,b;
     for(i=1;i<=N;i++)    
     {
	     P[i] = 0;
	     G[i][0] = 0;
	 }
     
     for(i=1;i<=M;i++)
     {
     	scanf("%d%d",&a,&k);
     	G[a][0] = k;
     	for(j=1;j<=k;j++)
     	{
     		scanf("%d",&b);
     		P[b] = a;
     		G[a][j] = b;
     	}
     }

     int count;
     int max = 0;
     //以b作为迭代初始 找root 
     int GEN[100];
     for(i=1;i<=N;i++)
     {
     	if(G[i][0]>0)
     	{
     		GEN[i] = 0;
     		continue;
     	}
     	
     	j = i;
     	count = 0;
     	while(P[j]!=0)
     	{
     		j = P[j];
     		count++;
     	}
     	GEN[i] = count;
     	if(count>max)
     	max = count;
     }

     int re[100];
     for(i=0;i<100;i++)
	 re[i] = 0; 
     for(i=1;i<=N;i++)
        re[GEN[i]]++;

     if(N==1)
     {
     	      printf("1");
     	     return 0;
     }
           printf("0");
     for(i=1;i<=max;i++)
         printf(" %d",re[i]);
     
	
}
