#include <stdio.h>
#include <stdlib.h>


#define size 6

void enqueue( int * ,int *, int * , int );
int dequeue( int *,int *, int * ) ;
void display(int *, int * ,int *);

int main(){

int a[size] = {-99,-99,-99,-99,-99,-99};
int f = -1;
int r = -1;
int choice;
int element, x;


while(1){

 
	
	printf("1 >>enqueue \n 2>> dequeue\n 3> Display \n 4 >> EXIT \n");
	scanf("%d", &choice);
	

	switch(choice)
	{
	case 1:
		printf("Enter the Element \n");
		scanf("%d",&x);
		enqueue( a,&f, &r ,x);
		break;
		
 	case 2:
 		dequeue(a , &f, &r);
 		break;
 
 	case 3:
 	 	display(a , &f , &r);
 	 	break;
 	 	
 	case 4:
 		exit(0);
 		
 	}
 	
 }
 
 }
 
 
 void enqueue(int *a, int *f ,int *r,int x){
 
 
 	if(*r == size -1){
 	
 	printf(" Queue is Full \n");
 	
 	return ;
 	} void dequeue(int *a, int *f, int *r)
 	
 	(*r)++;
 	a[*r] = x;
 	
 	
 	if(*f == -1){
 	
 	*f = 0;
 	}
 	
 	}
 	
 	
 	
 void display(int *a, int *f ,int *r){
 
 	for(int i =0;i< size ;i++){
 	
 		printf("%d-->",a[i]) ;
 		
 		}
 		
 	printf("\nfront = %d \nrear = %d\n ", *f ,*r);
 	
 	printf("\n");
 	}
 	
int dequeue(int *a, int *f, int *r){
 
 	if(*f == 1){
 	
 	printf("Queue is Empty \n");
 	return -99;
 	
 	}
 	
 	
 	int temp;
 	
 	temp = a[*f];
 	
 	if(*f == *r){
 	
 	*f = *r = -1;
 	else(*f)++;
 	
 	return temp;
 	}
 	
 	a[*f] = -99;
 	
 	(*f)++;
 	
 	return temp;
 	
 	}
 
 
	     
