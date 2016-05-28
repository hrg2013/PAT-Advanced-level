#include<stdio.h>
main()
{
	int N;
	char ID[100][15];
	scanf("%d",&N);
	int time[100][8];
	int i;
	for(i=0;i<N;i++)
	{
	  scanf("%s",ID[i]);
	  scanf("%d:%d:%d",&time[i][0],&time[i][1],&time[i][2]);
	  scanf("%d:%d:%d",&time[i][3],&time[i][4],&time[i][5]);
	  time[i][6] = time[i][0]*3600 + time[i][1]*60 + time[i][2];
	  time[i][7] = time[i][3]*3600 + time[i][4]*60 + time[i][5];
	}
	
	int min = 10000000;
	int max = 0;
	int minN,maxN;
	for(i=0;i<N;i++)
	{
		if(min>time[i][6])
		{
			min = time[i][6]; minN = i;
		}
		if(max<time[i][7])
		{
			max = time[i][7]; maxN = i;
		}
	}
	
	printf("%s %s",ID[minN],ID[maxN]);
	
	
	
	
	return 0;
 } 
