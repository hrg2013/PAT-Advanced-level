#include<iostream>
using namespace std;
int travel[1000];   
int G[1000][1000];//邻接表 

main()
{
  int flag;
  int N,M,K;

  int Queue[1000];
  cin >> N >> M >> K;
  int a,b,c;
  int Concern[1000];
  int i,j,k;
  for(i=0;i<1000;i++)
  for(j=0;j<1000;j++)
     G[i][j] = 0; 
     
  for(i=1;i<=M;i++)
  {
    cin >> a >> b;
    G[a][0] ++ ;
    G[a][G[a][0]] = b;
    G[b][0] ++;
    G[b][G[b][0]] = a;  
   } 
   
   for(i=0;i<K;i++)
   cin >> Concern[i];
  int count;
  for(i=0;i<K;i++)
  {
    for(j=0;j<=N;j++)
    Queue[j] = 0;
    a = Concern[i];
    for(j=1;j<=N+1;j++)
      travel[j] = 0;  //untraveled
    count=0;
    b = 1;
    if(a==1)
    b = 2;
    flag = 1;
    while(flag)
    {

      travel[b] = 1;
      Queue[0] += 1;
      Queue[Queue[0]] = b;
      while(Queue[0])
      {
        k = Queue[1];//删除队头元素
        for(j=2;j<=Queue[0];j++)
         Queue[j-1] = Queue[j];
         
        Queue[0] -= 1;
        for(j=1;j<=G[k][0];j++)
          {
            c = G[k][j];
            if(!travel[c] && c!=a)
            {
              travel[c] = 1;
                  Queue[0] += 1;
            Queue[Queue[0]] = c;
            }
              
          } 
        
      }
      
      count ++;
      while((travel[b] || b==a) && b<=N)
      {        
        if(b==N)
        {
           flag = 0;
           if(!travel[b]&&b!=a)
           count++;
        }

        b++;

      }      
    }
    
    cout << count-1 << endl;
    
    
    
  }
  
  
  return 0;
 } 
 

