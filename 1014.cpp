#include<iostream>
using namespace std;

main()
{
	int N,M,K,Q;
	cin >> N >> M >> K >> Q;
	int time[1001];
	int i;
	for(i=1;i<=K;i++)
	 cin >> time[i];
	int ask[1001];
	for(i=1;i<=Q;i++)
	 cin >> ask[i];
	int win[1001][2];//每个人去的窗口编号和等候时间 
	int wincount[21][3];  //窗口的排队人数和最后一人办完的时间和下个人办完的时间
	int sche[21][1001];  
	for(i=1;i<=N;i++)
	{
    	wincount[i][0] = 0;	
		wincount[i][1] = 0;	
		sche[i][0] = 1; //当前窗口正在办第几个人 
	}
    
	
	for(i=1;i<=N*M;i++)
	{
		if(i>K)
		break;
		
		wincount[(i-1)%N+1][0] ++;
		wincount[(i-1)%N+1][1] += time[i];
		
		win[i][0] =  wincount[(i-1)%N+1][1];
		win[i][1] =  wincount[(i-1)%N+1][0];
		sche[(i-1)%N+1][wincount[(i-1)%N+1][0]] = time[i];
		
	}
	
	int min;
	int choose;
	int j;
	int temp;
	if(K>N*M)
	{
		for(i=1;i<=N;i++)
		   wincount[i][2] = sche[i][sche[i][0]]; 
		
		for(i=N*M+1;i<=K;i++)
		{
			//find the min time
			choose = 1;
			min = 100000;
			
			for(j=1;j<=N;j++)
			{
				if(min>wincount[j][2])
				   {
				   	  min = wincount[j][2];
				   	  choose = j;
				   }
			}		
			
			for(j=1;j<=N;j++)
			{
				wincount[j][2] -= min;
			}
			j = choose;
			sche[j][0] += 1;
			wincount[j][2] += sche[j][sche[j][0]];	
			wincount[j][0] ++;
			wincount[j][1] += time[i];
			sche[j][wincount[j][0]] = time[i];
			win[i][0] = wincount[j][1];
		    win[i][1] = wincount[j][0];
		
		}

	}
	
	int out;
	for(i=1;i<=Q;i++)
	  {
	  	out = 480 + win[ask[i]][0];
	  	if(out-time[ask[i]]>=17*60)
	  	 cout << "Sorry" << endl;
	  	 else if(out/60<10 && out%60<10)
	  	 cout << "0" << out/60 << ":" << "0" << out%60 << endl;
	  	 else if(out/60>=10 && out%60>=10)
	  	 cout << out/60 << ":" << out%60 << endl;
	  	 else if(out/60>=10 && out%60<10)
	  	 cout <<  out/60 << ":" << "0" << out%60 << endl;
	  	 else
	  	 cout << "0" << out/60 << ":" << out%60 << endl;
	  }
	  

	return 0;
}
