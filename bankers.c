// Banker's algorithm

#include<stdio.h>

void main()
{
	int p, r ,i,j;

	
	printf("\nEnter number of processes: ");
	scanf("%d", &p);
	printf("\nEnter number of resources: ");
	scanf("%d", &r);
	
	int ava[r], total[r]; //Total resources
	int curr[p][r];
	int max[p][r];
	int need[p][r];
	int exe, safe;
	int running[p];
	int end=0;
	
	for( i=0 ; i<r ; i++)
	{
		printf("\nEnter max num of resource %d: ", i);
		scanf("%d", &total[i]);
		ava[i]=total[i];
		}
		
	for( i=0 ; i<p ; i++ )
	{
		for( j=0 ; j<r ; j++ )
		{
		printf("\nCurrent[%d][%d]= ", i, j);
		scanf("%d", &curr[i][j]);
		}
	}
	
	for( i=0 ; i<p ; i++ )
	{
		for( j=0 ; j<r ; j++ )
		{
		printf("\nMax Claim[%d][%d]= ", i, j);
		scanf("%d", &max[i][j]);
		}
	}

// Calculate Need	
	for( i=0 ; i<p ; i++ )
	{
		for( j=0 ; j<r ; j++ )
		{
		need[i][j]= max[i][j] - curr[i][j];
		printf("%d ", need[i][j]);
		}
		printf("\n");
	}
	
	
	

// Calculate available
	printf("\nAvailable matrix: ");
	for( j=0 ; j<r ; j++)
	{
	for( i=0 ; i<p ; i++)
	{
		ava[j]= ava[j]- curr[i][j];
		printf("\n%d = %d", j, ava[j]);
	}
	}
	
	
	
	for( i=0  ; i<p ; i++)
		running[i]=0;	
// LOGIC
	//printf("\nbefore logic");
		
	while( end<p )	// when all processes are executed/ deadlock detected
	{
	safe=0;
		for( i=0; i< p ; i++)
		{
			//printf("\nlogic");
			if(running[i])
				break;
			else
			{
	
				exe=1;
				for(j=0 ; j< r ; j++)
				{
					if(max[i][j] - curr[i][j] > ava[j])
					{
					exe=0;
					break;
					}
				}
			
				if(exe==1)
				{
					for(j=0 ; j<r ; j++){
					ava[j]= ava[j] + need[i][j];}
					safe=1;
					end++;
					running[i]=end;
		
				break;
				}
			}
		}
			//printf("\naft logic");
	if(safe)
	{
		printf("\nSafe state. No deadlocks. Order of processes: \n");
		for( j=0 ; j<p ; j++)
		{
			printf("\n Process %d: %d", j, running[j] );
		}
	}	
}
}	
	
	
		
			
	

	
	
	
	
