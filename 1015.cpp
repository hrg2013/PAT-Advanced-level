#include<iostream>
#include<math.h>
using namespace std;

main()
{
	int N[1000];
	int D[1000];
	int radix[20];
	int n = 0;
	int a,b;
	while(1)
	{
		cin >> a;
		if(a<0)
		break;
		cin >> b;

		N[n] = a;
		D[n] = b;
		n++;
	}
	int i,j,flag,k;
	for(i=0;i<n;i++)
	{
		a = N[i];
		b = D[i];
		flag = 0;
		// a是否为质数
		for(j=2;j<=a/2;j++)
		  if(a%j==0)
		  {
		  	flag = 1;
		  	break;
		  }
		  if(a==1)
		    flag = 1; 

		   
		  
		//求a的reverse
		j = 0;
		while(a>0)
		{
			radix[j] = a%b;
			j++;
			a /= b;	
		}   
		
		a = 0;
		for(k=0;k<j;k++)
		a += radix[k]*pow(b,j-1-k);
		
		for(j=2;j<=a/2;j++)
		  if(a%j==0)
		  {
		  	flag = 1;
		  	break;
		  }		
		  if(a==1)
		    flag = 1; 
	    if(flag)
	    cout << "No" << endl;
	    else
	    cout << "Yes" << endl;
		
	}
	

	
	
	
	return 0;
}
