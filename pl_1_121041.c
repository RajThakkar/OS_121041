/* 
Write a C program to implement First Come First Serve Scheduling Algorithm. (Consider all processes are arrived at time 0).

Inputs: Number of processes, Burst Time of each process.
Outputs: Turnaround time and waiting time of each process.
*/

#include<stdio.h>
int main()
{
	int n,avgwt=0,avgtt=0,i,j;
    	printf("Enter total number of processes: ");
   	scanf("%d",&n);
   	
	int bt[n],wt[n],tt[n];
	printf("\nEnter Process Burst Time: \n");
    	for(i=0;i<n;i++)
    	{
		printf("P[%d]:",i);
        	scanf("%d",&bt[i]);
	}

   	wt[0]=0;    //waiting time for first process is 0

    //calculating waiting time
    
    for(i=1;i<n;i++)
    {
	wt[i]=0;	// as all processes arrive at 0
        for(j=0;j<i;j++)
	{
            wt[i]+=bt[j];
	}
    }
 
	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
	
//*************calculating turnaround time******************

    for(i=0;i<n;i++)
    {
        tt[i]=bt[i]+wt[i];
        avgwt+=wt[i];
        avgtt+=tt[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tt[i]);
    }
	
    avgwt/=i;
    avgtt/=i;
    printf("\n\nAverage Waiting Time: %d",avgwt);
    printf("\nAverage Turnaround Time: %d\n",avgtt);
 
    return 0;

}
