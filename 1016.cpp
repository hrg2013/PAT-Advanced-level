#include<stdio.h>
#include<string.h>

double pay(int a,int b);

struct record
{
	char ID[20];
	int time;
	int flag;
};
struct customer
{
	char ID[20];
	int ontime[500];
	int offtime[500];
	int sorted;
};
	int rate[24];
main()
{

	int N;

	struct record r[1000];
	char line[10];
	int i,j,k;
	int month,b,c,d;
	for(i=0;i<24;i++)
	  scanf("%d",&rate[i]);
	  
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%s",&r[i].ID);
		scanf("%d:%d:%d:%d",&month,&b,&c,&d);
		r[i].time = (b*24+c)*60 + d;
		scanf("%s",line);
		if(strcmp(line,"on-line")==0)
		  r[i].flag = 1;
		  else
		  r[i].flag = 0;	
	}
	
	
	
	// data loaded

	int count = 0;  //顾客数 
	struct customer cus[500];
/*	for(i=0;i<500;i++)
	{
		cus[i].ID[0] = '1';
		cus[i].ontime[0] = 0;
		cus[i].offtime[0] = 0;   //第一个数记录有多少个数据 
		cus[i].sorted = 0;
	}*/
	
	for(i=0;i<N;i++)
	{

		for(j=0;j<count;j++)
		  if(strcmp(cus[j].ID,r[i].ID)==0)
		      break;
		if(j == count)
		  count++; 
		strcpy(cus[j].ID,r[i].ID);
		if(r[i].flag)
		{
			b = ++cus[j].ontime[0];
			
			cus[j].ontime[b] = r[i].time;
		}
		else
		{
			b = ++cus[j].offtime[0];
			
			cus[j].offtime[b] = r[i].time;
		}	     
		
	}
	int hour1,min1,day1,hour2,min2,day2,dtime;
	int m,temp,s,record;
	double amount,price;
	for(i=0;i<count;i++) //排序并输出每个顾客的数据
	{
		k = 0;
		while(cus[k].sorted)
		 k++;
		 
		for(j=k;j<count;j++)
	    	if(strcmp(cus[j].ID,cus[k].ID)<0 && !cus[j].sorted)
	    	{
	    		k = j;
	    	}
	    cus[k].sorted = 1;  //输出顾客k 
		

		//对时间序列进行排序
		record = cus[k].ontime[0];
		for(j=1;j<=record;j++)
		{
		    m = j;
			for(s=m;s<=record;s++)
			  if(cus[k].ontime[s] < cus[k].ontime[m])
			      m = s;
			temp = cus[k].ontime[m];
			cus[k].ontime[m] = cus[k].ontime[j];
			cus[k].ontime[j] = temp;	  		
		}	
		
		record = cus[k].offtime[0];		
		for(j=1;j<=record;j++)
		{
		    m = j;
			for(s=m;s<=record;s++)
			  if(cus[k].offtime[s] < cus[k].offtime[m])
			      m = s;
			temp = cus[k].offtime[m];
			cus[k].offtime[m] = cus[k].offtime[j];
			cus[k].offtime[j] = temp;	  		
		}	
		
		if(cus[k].ontime[0]==0 || cus[k].offtime[0]==0 || cus[k].ontime[1]>cus[k].offtime[cus[k].offtime[0]])
		{
		  continue;
		}

		
		// m s 分别作为指针
		m = 1;
		s = 1;
		amount = 0;
        
		if(month<10)
		printf("%s 0%d\n",cus[k].ID,month);
		else
		printf("%s %d\n",cus[k].ID,month); 
		while(m<=cus[k].ontime[0] && s <=cus[k].offtime[0])
		{
			b = cus[k].ontime[m];
			c = cus[k].offtime[s];
			if(b>c)
			{
				s++;
				continue;
			}

			
			while(b<c && m<cus[k].ontime[0])
			{
				m++;
				b = cus[k].ontime[m];
			}
			if(b<c)
			{
				day1 = b/1440;
				hour1 = (b%1440)/60;
				min1 = (b%1440)%60;
				day2 = c/1440;
				hour2 = (c%1440)/60;
				min2 = (c%1440)%60;
				if(day1<10)
					printf("0%d:",day1);  else printf("%d:",day1);
				if(hour1<10)
					printf("0%d:",hour1);  else printf("%d:",hour1);
				if(min1<10)
					printf("0%d",min1);  else printf("%d",min1);	
				if(day2<10)
					printf(" 0%d:",day2);  else printf(" %d:",day2);
				if(hour2<10)
					printf("0%d:",hour2);  else printf("%d:",hour2);
				if(min2<10)
					printf("0%d ",min2);  else printf("%d ",min2);											
				printf("%d ",c-b);
				
				price = pay(b,c);
				
				printf("$%.2lf\n",price);		
				amount += price;
				break;
			}
            
			m--;
			//输出当前on和off
			b = cus[k].ontime[m];
			day1 = b/1440;
			hour1 = (b%1440)/60;
			min1 = (b%1440)%60;
			day2 = c/1440;
			hour2 = (c%1440)/60;
			min2 = (c%1440)%60;
			if(day1<10)
				printf("0%d:",day1);  else printf("%d:",day1);
			if(hour1<10)
				printf("0%d:",hour1);  else printf("%d:",hour1);
			if(min1<10)
				printf("0%d",min1);  else printf("%d",min1);	
			if(day2<10)
				printf(" 0%d:",day2);  else printf(" %d:",day2);
			if(hour2<10)
				printf("0%d:",hour2);  else printf("%d:",hour2);
			if(min2<10)
				printf("0%d ",min2);  else printf("%d ",min2);											
			printf("%d ",c-b);	
			
			price = pay(b,c);
			printf("$%.2lf\n",price);		
			amount += price;
			
			m++;
			s++;
			 
			
		}
		
		printf("Total amount: $%.2lf\n",amount);
		
	 } 
	
	

	
	
	return 0;
}



double pay(int b ,int c)
{
	int hour1,min1,day1,hour2,min2,day2,dtime;
	int j;
	double price = 0;
	day1 = b/1440;
	hour1 = (b%1440)/60;
	min1 = (b%1440)%60;
	day2 = c/1440;
	hour2 = (c%1440)/60;
	min2 = (c%1440)%60;
	if(day1==day2)
	{
		if(hour1 == hour2)
		price = rate[hour1] * (c-b) *0.01;
	    else 
		{
			price += rate[hour1] * (60-min1) * 0.01;
			price += rate[hour2] * min2 *0.01;
			dtime = c - b - (60-min1) - min2;
			for(j=1;j<=dtime/60;j++)
			 price += rate[hour1+j] *60 *0.01;
		}
	}
	else
	{

		price += pay(b,(day1+1)*24*60-1);
		price += 0.01*rate[23];
		price += pay(day2*24*60,c);
        dtime = day2-day1-1;
        for(j=0;j<24;j++)
           price += rate[j]*60*0.01*dtime;
	}
	
	
	

	return price;
}

