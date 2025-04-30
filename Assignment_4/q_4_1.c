/*Q4. Write a C/C++ program to implement circular queue data
structure using array. Implement below metioned functions.
a) add b) delete c) peep d) displayQueue e)isQueueFull
f) isQueueEmpty*/

#include <stdio.h>
#include <stdlib.h>


#define size 5

int main(){

	int front = -1;
	int rear = -1;
	int choice;
	int element,ret;q3_queue
	int arr[size];


	for(int i = 0 ;i<size;i++){
	arr[i] = -99;
	}



	while(1){

	printf("Enter your Choice \n 1.add\n 2.displayQueue \n 3.peep \n 4.delete  \n 5.queue_full\n 6.queue_empty \n 7.exit  ");
	scanf("%d",&choice);
	
	switch(choice){
	
		case 1:
		printf("Enter the value is Queue  \n");
		scanf("%d",&element);
		
		enqueue(arr, &front, &rear, element);
			break;
		      
