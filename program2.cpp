#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n;
struct process
{
	int priority;
	intServiceTime;
	intArrivalTime;
	intprocessedFlag;
	intcomTime;
	int waiting;
	charProcessID[5];
}p[10];
voidsort_priority(process a[])
{
for(int i=0;i<n-1;i++)
     {
for(int j=0;j<n-i-1;j++)
       {
if(a[j].priority>a[j+1].priority)
               {
process temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;             

               }
        }    
     }  

 }
void processor(process p[])
{
	struct process readyQueue[n];
	readyQueue[0]=p[0];
	int count=0,wait=0;
	for(int i=p[0].ArrivalTime,k=0;0!=sizeof(readyQueue)/sizeof(process);)
	{
		if(readyQueue[k].ServiceTime!=0)
		{
			readyQueue[k].processedFlag=1;
			readyQueue[k].ServiceTime--;
			readyQueue[k].priority++;
			i++;
			for(int m=0;m<(sizeof(readyQueue)/sizeof(process));m++)
			{
				if(readyQueue[m].processedFlag==0)
					readyQueue[m].priority+=2;
			}
			if(i!=p[i].ArrivalTime)
				continue;
			else
			{
				k++;
				readyQueue[k]=p[i];
				i++;
				sort_priority(readyQueue);
			}
		}
		else
		{
			count++;
			i++;
			if(count>n)
			break;
			printf("\nProcess %s Executed Successfuly",readyQueue[k].ProcessID);
			for(int l=0;l<n;l++)
				if(p[l].ProcessID==readyQueue[k].ProcessID)
				{
					readyQueue[k].waiting=i-p[l].ArrivalTime-p[l].ServiceTime;
					wait+=readyQueue[k].waiting;
					break;
				}
			printf(" with waiting time %d",readyQueue[k].waiting);
		}	
	}
	printf("\n Average waiting time:%d",wait/n);	
}
voidsort_Process(process a[])
{
for(int i=0;i<n-1;i++)
     {
for(int j=0;j<n-i-1;j++)
       {
if(a[j].ArrivalTime>a[j+1].ArrivalTime)
               {
process temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;             

               }
}    
     }  
 }          
voidprocess_Creation()
{
	printf("Enter Number of process:");
	scanf("%d",&n);
	process p[n];
	for(int i=0;i<n;i++)
	{
		printf("\nNow Enter Process ID:");
		fflush(stdin);
		scanf("%s",&p[i].ProcessID);
		printf("\nNow Enter process arival time:");
		fflush(stdin);
		scanf("%d",&p[i].ArrivalTime);
		printf("\nNow Enter process burst/service Time:");
		fflush(stdin);
		scanf("%d",&p[i].ServiceTime);
		p[i].priority=0;
		p[i].processedFlag=0;
	}
	sortProcess(p);
	processor(p);
}
int  main()
{
printf("\n  Priority Scheduling   \n");
	getch();
	processCreation();
}

