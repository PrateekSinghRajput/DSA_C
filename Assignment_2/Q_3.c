/**********************************************************************************************************
Determine the factors of a number (i.e., all positive integer values that evenly divide into a number) and then
return the p

th element of the list, sorted ascending. If there is no p

th element, return 0.

Example: n = 20 and p = 3
The factors of 20 in ascending order are {1, 2, 4, 5, 10, 20}. Using 1-based indexing, if p = 3, then 4 is
returned. If p > 6, 0 would be returned.
Function Description
Complete the function pthFactor in the editor below.
pthFactor has the following parameter(s):
int n: the integer whose factors are to be found
int p: the index of the factor to be returned
Returns:
int: the long integer value of the p

th integer factor of n or, if there is no factor at that index, then 0 is returned

***************************************************************************************************************/



#include <stdio.h>

int ptfactor(int n , int p);

int main(){

int n;
int p;

printf("Enter the value of n \n");
scanf("%d",&n);

printf("Enter the value of p \n");
scanf("%d", &p);

printf("The %d factor of %d is %d \n", p, n ,ptfactor(n , p));

}

int ptfactor(int n , int p){

int count=0;

for(int i=1;i<=n;i++){

if(n%i==0){

count ++;

if(count ==p){

return i;
}
}
}

return 0;
}
