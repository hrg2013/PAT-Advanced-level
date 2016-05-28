#include<iostream>
#include<iomanip>  

using namespace std;

main()
{
	double W[3][3];
	int i,j;
	for(i=0;i<3;i++)
	{
     	cin >> W[i][0] >> W[i][1] >> W[i][2];
	}
    int choose[3];
    double max[3];
    for(i=0;i<3;i++)
    {
    	max[i]=0;
    	for(j=0;j<3;j++)
    	{
    		if(W[i][j]>max[i])
    		{
    			max[i]=W[i][j];choose[i] = j;
    		}
    	}
    	if(choose[i]==0) cout << "W ";
    	if(choose[i]==1) cout << "T ";
    	if(choose[i]==2) cout << "L ";
    }
    double sum = 2*(max[0]*max[1]*max[2]*0.65-1);
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum;
    
	
	
	return 0;
}
