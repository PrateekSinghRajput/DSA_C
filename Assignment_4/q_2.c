/*Q2. Write a C/C++ program to implement stack data structure using
array. Implement below metioned functions.
a) push b) pop c) peep d) displayStack e)isStackFull
f) isStackEmpty  */

#include <stdio.h>
#include <stdlib.h>


#define size 5

void push(int *, int *, int);
int pop(int * , int* );
void display(int *, int *);

int main(){

int arr[size];
int top = -1;
int ele,ret;
int choice;


for(int i = 0; i<size; i++){

	arr[i] = -99;
}	


while(1){
	printf("1.-> Push \n2.-> POP \n3.-> Display \n4.-> exit  \n");
	
	scanf("%d",&choice);
	
	switch(choice){
	
	case 1:
	  printf("Enter element: ");
                scanf("%d", &ele);
		push(arr , &top,ele);
		break;
	case 2:
		pop(arr,&top);q3_queue
		break;

	case 3:
		printf("Stack items:\n");
               display(arr, &top);
		break;
	case 4:
		exit(0);
		
	}
	}
	
	}

	void push(int *a, int *t, int x){


	if(*t == size -1){
	
	printf("Stack is full \n");
	
	return;
	
	}
	
	(*t)++;
	
	a[*t] = x;
	}
	
	
	void display(int *a, int *t) {
	
	    for(int i = 0; i < size; i++) {
	    
	        printf("[%d] ", a[i]);
	        
	    }
	    
	    printf("\nTop = %d\n", *t);
	}
	
	
	
	int pop(int *a, int *t){
	
	if(*t == -1){
	
	printf("Stack is empty \n");
	return -77;
	}
	
	int temp;
	temp = a[*t];
	a[*t] = -99;
	(*t)--;
	
	return temp;
	
	}
	
	
