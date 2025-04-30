/*Q3. Write C/C++ prgram which allocate and deallocate memory
dynamically.
(a) Allocating 1D array dynamically and access the elements
(b) Allocating 2D array dynamically
(1) contiguous rows with fixed no.of cols,
(2) Non contiguous rows with variable no.of columns
(c) Allocate memory for array of structure variables dynamically and
access members of each element*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int r,c;
	int i,j;
	int **p;
	printf("Enter no of rows and columns\n");
	scanf("%d %d",&r,&c);
	p=(int **)malloc((r*c)*sizeof(int));
	if(p==NULL)
	{
		printf("Memory allocation failed\n");
		return 0;
	}
	for(i=0;i<r;i++)
	{
		p[i]=(int *)malloc(c*sizeof(int));
		{
			if(p[i]==NULL)
			{
				printf("Memory allocation failed\n");
				return 0;
		}	}
	}
	for(i=0;i<r;i++)
	{
	printf("Enter array elements for sub array no.%d\n",i+1);
	for(j=0;j<c;j++)
	{
		scanf("%d",&p[i][j]);
	}
	}

	printf("Array elements are:\n");
	for(i=0;i<r;i++)
	{
	//printf("array elements for sub array no.%d are:\n",i+1);
	for(j=0;j<c;j++)
	{
		printf("%d ",p[i][j]);
	}
	printf("\n");
	}
}

.

