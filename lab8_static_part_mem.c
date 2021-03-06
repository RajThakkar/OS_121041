/*There are 5 processes requiring the memory :

P1 -> 100 KB
P2 - > 275 KB
P3  -> 170 KB
P4 -> 340 KB
P5 -> 500 KB

Take the suitable layout and size of memory  and show graphically  how first fit, best fit, worse fit and next fit will assign the memory block.

What will the amount of Internal for static / External fragmentation for dynamic partitioning.*/

// **********************STATIC PARITIONING**************************************
#include<stdio.h>

int main()
{
	int m,p,i,j, flag, ch, best, cnt;
	int k=0;
	int frag=0;
	int total=0;
	printf("\nEnter number of memory blocks: ");
	scanf("%d", &m);
	printf("\nEnter number of processes: ");
	scanf("%d", &p);	
	
	int mem[m], pro[p], init_mem[m];
	
	for( i=0 ; i<m ; i++)
	{
		printf("\nEnter size of mem block %d : ", i);
		scanf("%d", &mem[i]);
		total=total+mem[i];
		
	}
	for( i=0 ; i<m ; i++)	// To support multiple algos with same input in a do while
	{
		init_mem[i]=mem[i];
	}
	for( i=0 ; i<p ; i++)
	{
		printf("\nEnter size of process %d : ", i);
		scanf("%d", &pro[i]);
	}
do
{	
	printf("\n1. First Fit");
	printf("\n2. Best Fit");
	printf("\n3. Next Fit");
	printf("\n4. Worst Fit");
	printf("\n0. Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &ch);
	
	switch(ch)
	{
//************ First FIT *********************
	case 1:
	
	for( i=0 ; i<m ; i++)	//Initialise the sizes of memory blocks
	{
		mem[i]=init_mem[i];
	}
			
	for( i=0 ; i<p ; i++)
	{
	flag=0;
		for( j=0 ; j<m ; j++)
		{
		if( mem[j] >= pro[i])
		{
			mem[j]=mem[j]-pro[i];
			flag=1;
		}
		if(flag == 1){
			printf("\nProcess %d allocated in mem block %d", i, j);
			break;}
		else{
			printf("\nProcess %d cannot be allocated.",i);
			break;}
		}	
	}
	break;
//************ BEST FIT *********************	
	case 2:

	for( i=0 ; i<m ; i++)
	{
		mem[i]=init_mem[i];
	}
		
	for( i=0 ; i<p ; i++)
	{
	flag=0;

		for( j=0 ; j<m ; j++)
		{
			if( mem[j] >= pro[i])
			{
				if( flag==0 )
					best=mem[j];
				if( best >= mem[j] ){
					flag=1;
					best=mem[j];
					k=j;
					}
			}
		}
		
		if(flag==0)
		
			printf("\nProcess %d cannot be allocated.",i);
		else
		{
			mem[k]=mem[k]- pro[i];
			printf("\nProcess %d allocated in %d.",i, k);
			
		}
	}
//************ NEXT FIT *********************
	break;
	case 3:

	for( i=0 ; i<m ; i++)
	{
		mem[i]=init_mem[i];
	}
	
	for( i=0 ; i<p ; i++)
	{
	k=0;		
	flag=0;
		for( j=k, cnt=0 ; cnt<m ; j++, cnt++)
		{
		if( j==m )
			j=0;
		if( mem[j] >= pro[i])
		{
			mem[j]=mem[j]-pro[i];
			flag=1;
			k=j;	// to start the next iteration from last allocated block
		}
		if(flag == 1){
			printf("\nProcess %d allocated in mem block %d", i, j);
			break;}
		else
			printf("\nProcess %d cannot be allocated.",i);
		}	
		
	}
	break;	
//************ WORST FIT *********************
	case 4:
	
	for( i=0 ; i<m ; i++)
	{
		mem[i]=init_mem[i];
	}
	
	for( i=0 ; i<p ; i++)
	{
	flag=0;

		for( j=0 ; j<m ; j++)
		{
			if( mem[j] >= pro[i])
			{
				if( flag==0 )
					best=mem[j];
				if( best <= mem[j] ){
					flag=1;
					best=mem[j];
					k=j;
					}
			}
		}
		
		if(flag==0)
		
			printf("\nProcess %d cannot be allocated.",i);
		else
		{
			mem[k]=mem[k]- pro[i];
			printf("\nProcess %d allocated in %d.",i, k);
			
		}
	}	
	break;		
	
	case 0:
	return 0;
			
	
	}
// ********************** INTERNAL FRAG ********************************* No external*****************
	for( i=0 ; i<m ; i++)
	{
		//if ( mem[i] != init_mem[i] )
			frag=frag+mem[i];
	}
	printf("\nTotal memory: %d.", total);
	printf("\nTotal Internal Fragmentation is %d." , frag);	
	
}while(1);
		
	}	
