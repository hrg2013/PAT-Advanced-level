#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
  int tag,radix;
  char n1[15];
  char n2[15];
  long int num;
  long int n;
  int temp;
  int flag,flagx,flagy;
  int x,y;
  int a,b,c;
  scanf("%s",n1);
  scanf("%s",n2);
  scanf("%d%d",&tag,&radix);

    int i,j,k;
    if(tag==1)
    {
      j = strlen(n1);
      num = 0;
      for(i=j-1;i>=0;i--)
      {   
          if(n1[i]<='9')
          temp = n1[i] - '0';
          else if(n1[i]<='Z')  temp = n1[i]-'A'+10;
          else temp = n1[i] - 'a' + 10;
          if(temp>=radix)
          {
        printf("Impossible");
             return 0;
          }
        num = num + temp*pow(radix,j-i-1); //decimal
      }

      j = strlen(n2); 
      if(j==2)
      {  
      flagy=0;
      	 a = n2[0]<='9'? n2[0]-'0':(n2[0]<='Z'? n2[0]-'A'+10:n2[0]-'a'+10);
      	 b = n2[1]<='9'? n2[1]-'0':(n2[1]<='Z'? n2[1]-'A'+10:n2[1]-'a'+10);

     	    if((num-b)%a == 0)
      	    flagy = 1;
      	 	y = (num-b)/a;	     
	   	 	if(a>=y || b>=y)
      	 	flagy = 0;

      	 if(flagy) 
		  printf("%d",y);
      	 else  printf("Impossible");
      	 return 0;
		   
      }
      
      
      for(k=pow(num,1.0/j);k<=pow(num,1.0/(j-1));k++)
      {
        n = 0;
      
        flag = 1;
        for(i=j-1;i>=0;i--)
         {
          if(n2[i]<='9')
          temp = n2[i] - '0';
          else if(n2[i]<='Z')  temp = n2[i]-'A'+10;
          else temp = n2[i] - 'a' + 10;
            if(temp>=k)  flag = 0;
          n = n + temp*pow(k,j-i-1); //decimal
         }

         if(n==num && flag)
           {
             printf("%d",k);
             return 0;
           }

      }
  
    }
    
    if(tag==2)
    {
      j = strlen(n2);
      num = 0;
      for(i=j-1;i>=0;i--)
      {   
          if(n2[i]<='9')
          temp = n2[i] - '0';
          else if(n2[i]<='Z')  temp = n2[i]-'A'+10;
          else temp = n2[i] - 'a' + 10;
          if(temp>=radix)
          {
            printf("Impossible");
             return 0;
          }
        num = num + temp*pow(radix,j-i-1); //decimal
      }

          j = strlen(n1);
      if(j==2)
      {  
         flagy=0;
      	 a = n1[0]<='9'? n1[0]-'0':(n1[0]<='Z'? n1[0]-'A'+10:n1[0]-'a'+10);
      	 b = n1[1]<='9'? n1[1]-'0':(n1[1]<='Z'? n1[1]-'A'+10:n1[1]-'a'+10);
      	    if((num-b)%a == 0)
      	    flagy = 1;
      	 	y = (num-b)/a; 
      	 	if(a>=y || b>=y)
      	 	flagy = 0;


      	 if(flagy) 
		  printf("%d",y);
      	 else  printf("Impossible");
      		return 0;
      }
      
      for(k=pow(num,1.0/j);k<=pow(num,1.0/(j-1));k++)
      {
        n = 0;

        flag = 1;
        for(i=j-1;i>=0;i--)
         {
            if(n1[i]<='9')
            temp = n1[i] - '0';
            else if(n1[i]<='Z')  temp = n1[i]-'A'+10;
            else temp = n1[i] - 'a' + 10;
            if(temp>=k) flag=0;
          n = n + temp*pow(k,j-i-1); //decimal
         }
         
         if(n==num && flag)
           {
             printf("%d",k);
             return 0;
           }

      }
  
    }
  

  printf("Impossible");
  
  
  return 0;
}
