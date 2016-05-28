#include<stdio.h>
main()
{
	int N,M,C1,C2;
	scanf("%d%d%d%d",&N,&M,&C1,&C2);
	int team[500];
	int G[500][500];
	int i,j;
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	G[i][j] = 10000;
	
	for(i=0;i<N;i++)
	scanf("%d",&team[i]);
	int a,b,d;
	for(i=1;i<=M;i++)
	{
			scanf("%d%d%d",&a,&b,&d);
			G[a][b] = d;
			G[b][a] = d;
	}
//以上为初始化

    int F[500];
    int D[500];  
    int P[500][10];	
    int pathcount[500];
    int max=0;
    int v;
    for(v=0;v<N;v++)
    {
    	F[v] = 0;
    	D[v] = G[C1][v];
    	if(D[v]<10000)
    	{
    		P[v][0] = 1;
    		P[v][1] = C1;
    		pathcount[v] = 1;
    	}
		else {P[v][0] = 0; pathcount[v] = 0;} //无前驱 
    }
    pathcount[C1] = 1;
    D[C1] = 0;
	F[C1] = 1;
    int dteam;
	int min,w;
	int sum_team[500]; 
	sum_team[C1] = team[C1];
	for(i=1;i<N;i++)
	{
	    min = 10000;
	    dteam = 0;
		for(w=0;w<N;w++)			
		  if(!F[w])
		  {
		  	if(D[w]<min)
		  	 { v = w;min=D[w]; }
		  	
		  }

	    for(j=1;j<=P[v][0];j++)
	        if(dteam<sum_team[P[v][j]])
	          dteam = sum_team[P[v][j]];
	     F[v] = 1;
		 sum_team[v] = dteam +  team[v];


		 
		 //更新最短路
		 for(w=0;w<N;w++)
		 {
		 	if(!F[w])
		 	{
		 		if(min + G[v][w]<D[w])
		 		{
		 			D[w] = min + G[v][w];
		 			P[w][0] = 1;
		 			P[w][1] = v;
		 			pathcount[w] = pathcount[v];
		 		}
		 		else if(min + G[v][w]==D[w])
		 		{
		 			P[w][0]++;
		 			P[w][P[w][0]] = v;
		 			pathcount[w] = pathcount[w] + pathcount[v];
		 		}
		 		
		 	}
		 	
		 	
		}    


		    

	
	} 
//    printf("%d %d %d\n",P[4][0],P[4][1],P[4][2]);
//    printf("%d %d %d %d %d",pathcount[0],pathcount[1],pathcount[2],pathcount[3],pathcount[4]);
	printf("%d %d",pathcount[C2],sum_team[C2]);
	 
	
	
	return 0;
}



