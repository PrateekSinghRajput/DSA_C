/*Q4. Write a C/C++ program to implement circular queue data
structure using array. Implement below metioned functions.
a) add b) delete c) peep d) displayQueue e)isQueueFull
f) isQueueEmpty*/

#include <stdio.h>
#include <stdlib.h>


#define size 5

void add(int *arr , int *front , int *rear, int element);
void display(int *arr);
void delete(int*arr , int *front);


int main(){

	int front = -1;
	int rear = -1;
	int choice;
	int element,ret;
	int arr[size];


	for(int i = 0 ;i<size;i++){
	arr[i] = -99;
	}



	while(1){

	printf("Enter your Choice \n 1.add\n 2.displayQueue \n 3.peep \n 4.delete  \n 5.queue_full\n 6.queue_empty \n 7.exit  ");
	scanf("%d",&choice);
	
	switch(choice){
	
		case 1:
		printf("Enter the element to add  \n");
		scanf("%d",&element);
		add(arr, &front, &rear, element);
		break;
		      
		 case 2:
		 display( *arr);
		 break;
		 
		 case 3:
		 break;
		 
		 
		 case 4:
		 printf("enter the element to delete \n");
		 scanf("%d",&element);
		 delete(*arr , *front);
		 break;
		 
		 case 5:
		 break;
		 
		 
		 case 6:
		 break;
		 
		 
		 case 7:
		 exit(0);
		 
     
		     }
		    }
	  }
		      
		      
	void add(int *arr , int *front , int *rear, int element){
	
	if((front == 0) && (rear == size-1) || (rear +1 == front)){
	printf("queue is full\n");
	return ;
	}
	
	if(*rear = size -1){
		*rear = 0;
	}else{
		(*rear)++;
		
	}
	
	arr[*rear] = element;
	if(*front == -1)
	*front =0;
	
	}
	
	void display(int *arr){
	
	for (int i =0;i<size;i++){
	printf("[%d]",arr[i]);
		}
		}
		
	void delete(int*arr , int *front){
		
	int temp = arr[*front];
	arr[*front] = -99;
	
	if(*front == (size -1))
	{
		*front=0;
	}
	else
	{
	(*front)++;
	}
	return temp;
	}
	}
		
	
	
	
	
	
	
	
	
	
	

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	
	
	
	
	
	
	
	
		      
		      
		      
		      
		      
		      
