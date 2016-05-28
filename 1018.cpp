#include<stdio.h>
#include<stdlib.h>
#define Maxvexs 500
#define infinity 1000

typedef struct{
     int vexs[Maxvexs];
	 int arcs[Maxvexs][Maxvexs];
	 int vexn,arcn;
}MGraph;

typedef int Distance[Maxvexs+1];
typedef int Path[Maxvexs+1];
typedef int Bike[Maxvexs+1];

int Bike_Get(int a, int b)
{
	if(a<=b/2)
	return 0;
	else return(a-b/2);
}


void Dijkstra(MGraph G, int v2, Distance D, Path P, Bike B, int Cm)
{
   int F[Maxvexs];
   int v,min,w,i,dis=0;
   for(v=0; v<G.vexn; v++)
   {
     F[v] = 0; //置空最短路径集
     D[v] = G.arcs[0][v];
	 if(D[v]<infinity)  { P[v] = 0; B[v] = Bike_Get(G.vexs[v],Cm);  }
	 else {   P[v] = -1;  B[v] = -1; } 
   }

   D[0] = 0;
   F[0] = 1;   //将v1加入路径集
   int tempB,flag;
   for(i=1;i<G.vexn;i++)
   {
     min = infinity;
	 for(w=0;w<G.vexn;w++)
		 if(!F[w])   //不在路径集
			 if(D[w]<min)
			 {v=w; min = D[w];}
	F[v] = 1; //add to 路径集
    flag = 1;
	//更新最短路 
	for(w=0;w<G.vexn;w++)
	{ 
		if(F[w])
			continue;
		if(min+G.arcs[v][w]<D[w])
		{

		   	    D[w] = min + G.arcs[v][w];
		   		P[w] = v;
		   		B[w] = Bike_Get(G.vexs[w],Cm) + B[v];
		}
		if(min+G.arcs[v][w]==D[w])
		{
			if(Bike_Get(G.vexs[w],Cm) + B[v] > B[w])
			{
				D[w] = min + G.arcs[v][w];
		   		P[w] = v;
		   		B[w] = Bike_Get(G.vexs[w],Cm) + B[v];
			}
		 } 
	} 
   } 
   //printf("%d %d %d",B[1],B[2],B[3]);
   int need = Cm/2 - B[v2] - G.vexs[v2];
   int count = 0;
   int way[Maxvexs]; 
   while(v2!=0)
   {  	
   	  way[count] = v2;
   	  count++;
	  v2 = P[v2];
   }
   
   if(need>0)
   {
   		printf("%d 0",need);
   		for(i=count-1;i>=0;i--)
   		 printf("->%d",way[i]);
   		 printf(" 0");
   }
   else 
   {
   	   		printf("0 0");
   		for(i=count-1;i>=0;i--)
   		 printf("->%d",way[i]);
   		 printf(" %d",-need);
   }

}

main()
{
	int Cm,N,Sp,M;
	scanf("%d %d %d %d",&Cm,&N,&Sp,&M);
	MGraph* G = (MGraph*)malloc(sizeof(MGraph));
	int i,j,k,time;
	G->vexn = N+1;
	G->arcn = M;
	for(i=1;i<=N;i++)
	{
		scanf("%d",&(G->vexs[i]));
	}
	for(i=0;i<=N;i++)
		for(j=0;j<=N;j++)
			G->arcs[i][j] = infinity;
			
	for(i=0;i<M;i++)
	{
		scanf("%d %d %d",&j,&k,&time);
		G->arcs[j][k] = time;
		G->arcs[k][j] = time;
	}
	int D[Maxvexs+1];
	int P[Maxvexs+1];
	int B[Maxvexs+1];
	Dijkstra(*G, Sp,  D,  P,  B,  Cm);
	
	 
	
	
	return 0;
 } 
