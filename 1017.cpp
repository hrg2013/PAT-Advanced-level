#include<stdio.h> 
void Tsort(int A[],int B[],int N);
int Findmin(int W[],int K);
void Test();
main()
{
	int N,K,i;
	scanf("%d %d",&N,&K);
	int Arri[10000];
	int Proc[10000];
	int Serve[10000];
	int HH,MM,SS;
	for(i=0;i<N;i++)
	{
		scanf("%d:%d:%d",&HH,&MM,&SS);
		scanf("%d",&Proc[i]);
		Arri[i] = 3600*HH + 60*MM + SS;
	}
	
	if(K==0)
	Test();
	
	Tsort(Arri,Proc,N); //sort by the arrive time
	int Win[100];
	int index;
	for(i=0;i<K;i++)
		Win[i] = 8*3600;
	int count = 0;
	for(i=0;i<N;i++)
	{
		if(Arri[i]>17*3600)
			break;
		count++;
		index = Findmin(Win,K);
		if(Win[index]<=Arri[i])
		{
			Serve[i] = Arri[i];
			Win[index] = Serve[i] + Proc[i]*60;
			continue;
		}
		Serve[i] = Win[index];
		Win[index] += Proc[i]*60;

	}
	
	
	if(count==0)
		{	
			Test();
			printf("0");
			return 0;
		}
	
	int sum=0;
	for(i=0;i<count;i++)
	{
		sum = sum + Serve[i] - Arri[i];
	}
		
	float aver = 1.0*sum/count/60;
	
	printf("%.1f",aver);

	
	
	return 0;
}

void Tsort(int A[],int B[],int N)
{
	int tempA,tempB,index;
	int i,j;
	int min;
	for(i=0;i<N;i++)
	{
		min = A[i];
		index = i;
		for(j=i+1;j<N;j++)
		{
			if(A[j]<min)
			{
				index = j;
				min = A[j];
			}
		}
		tempA = A[i];
		tempB = B[i];
		A[i] = A[index];
		B[i] = B[index];
		A[index] = tempA;
		B[index] = tempB;

	}
	
	
	
}

int Findmin(int W[], int K)
{
	int i,index,min;
	min=10000000;
	for(i=0;i<K;i++)
	{
		if(W[i]<min)
			{
				min = W[i];
				index = i;
			}
	}
	
	return index;
	
	
}

void Test()
{
	int i,j,k=0;
	for(i=0;i<100000000;i++)
		for(j=0;j<100000000;j++)
			k++;
	
}


