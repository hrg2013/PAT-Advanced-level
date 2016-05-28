#include<iostream>
using namespace std;

main()
{
	int i,N,M;
	string ID[2000];
	string SQ[2000];
	int g[2000][4];
	cin >> N >> M;
	for(i=0;i<N;i++)
	{
			cin >> ID[i] >> g[i][0] >> g[i][1] >> g[i][2];
			g[i][3] = g[i][0]+g[i][1]+g[i][2];
			g[i][3] = g[i][3]/3;
	}
    int flag;
	int rank[2000][4];
	int k,j;
	for(k=0;k<4;k++)
	{
		for(i=0;i<N;i++)
    	{
	       rank[i][k] = 1;
	       for(j=0;j<N;j++)
	         if(g[j][k] > g[i][k])
	         rank[i][k]++;  	   
    	}	
	}
	
	for(i=0;i<M;i++)
	 cin >> SQ[i];
	for(i=0;i<M;i++)
	{
         	   	flag = 1;
	   for(j=0;j<N;j++) 
	   {

	   	  if(SQ[i]==ID[j])
	   	  {   
	   	    flag = 0;
	   	  	if(rank[j][3]<=rank[j][0] && rank[j][3]<=rank[j][1] &&rank[j][3]<=rank[j][2])
	   	  	  cout << rank[j][3] << " A" << endl;
	   	  	  else if(rank[j][0]<=rank[j][3] && rank[j][0]<=rank[j][1] &&rank[j][0]<=rank[j][2])
	   	  	  cout << rank[j][0] << " C" << endl;
	   	  	  else if(rank[j][1]<=rank[j][0] && rank[j][1]<=rank[j][2] &&rank[j][3]<=rank[j][3])
	   	  	  cout << rank[j][1] << " M" << endl;
	   	  	  else if(rank[j][2]<=rank[j][0] && rank[j][2]<=rank[j][1] &&rank[j][2]<=rank[j][3])
	   	  	  cout << rank[j][2] << " E" << endl;
	   	  }
	   }
	   if(flag)
	   cout << "N/A" << endl;
	}

	 
	
	
	
	return 0;
 } 
