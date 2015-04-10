 /* Write a C program to implement Shortest Job first (Non Preemptive)Scheduling Algorithm.
(Consider all processes are arrived at time 0).
*/
 
#include<stdio.h>
int main()
{

	int n;
	
	printf("Enter total number of processes: "); 
	scanf("%d",&n);	
	
	int i, j, temp, temp1, p[n], b[n], t[n], w[n];

	float avg_tt=0,avg_wt=0;

	for( i=0 ; i<n ; i++ )
        {
                        b[i]=0;
                        w[i]=0;
        }


	printf("\n");
	for(i=0;i<n;i++)
        {
		printf("Enter the burst times for P[%d]: ",i);
	        scanf("%d",&b[i]);
                p[i]=i;
        }
        
	for(i=0;i<n;i++)
        {
                        for(j=i;j<n;j++)
                        {
                                    if(b[i]>b[j])
                                    {
                                                temp=b[i];
                                                temp1=p[i];
                                                b[i]=b[j];
                                                p[i]=p[j];
                                                b[j]=temp;
                                                p[j]=temp1;
                                    }
			}
	}
		
	w[0]=0;
	for(i=0;i<n;i++)
		w[i+1]=w[i]+b[i];
			
	for(i=0;i<n;i++)
        {
		t[i]=w[i]+b[i];
		avg_wt=avg_wt+w[i];
		avg_tt=avg_tt+t[i];
        }
        		
        		
	avg_wt=avg_wt/n;
	avg_tt=avg_tt/n;


	printf("\Process \t Waiting time \t Turnaround time \n");
	for(i=0;i<n;i++)
	
	printf("P[%d] \t\t %d \t\t %d \n",p[i],w[i],t[i]);

	printf("Average waiting time = %f\n",avg_wt);
	printf("Average turn around timen= %f\n",avg_tt);

return 1;

}

