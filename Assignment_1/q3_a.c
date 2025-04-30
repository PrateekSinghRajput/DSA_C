/*Q3. Write C/C++ prgram which allocate and deallocate memory
dynamically.
(a) Allocating 1D array dynamically and access the elements
(b) Allocating 2D array dynamically
(1) contiguous rows with fixed no.of cols,
(2) Non contiguous rows with variable no.of columns
(c) Allocate memory for array of structure variables dynamically and
access members*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int ent_row ,ent_col;
	int row1=2 , col1=3;
	
	int(*arr1)[col1] = (int(*)[col1])malloc(row1*col1*sizeof(int));
	 
	 if(arr1 == NULL){
	 printf("Memory Allocation Failed.Exiting the Program\n");
	 exit(0);
}
	for(int i=0; i<row1; i++){
		for(int j=0; j<col1; j++){
			arr1[i][j]= i*row1+j;
			}
	 }
printf("Enter the row and coloumn index seprated by space ");
scanf("%d %d",&ent_row, &ent_col);

if(ent_row>row1-1 || ent_col>col1-1){
printf("entered indices are out of bounds \n");
}

printf("the value in %dth coloumn of %dth row is %d\n",ent_row,ent_col,arr1[ent_row][ent_col]);


free(arr1);
	}
