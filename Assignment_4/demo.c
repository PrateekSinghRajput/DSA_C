/*Q3. Write a C/C++ program to implement queue data structure using
array. Implement below metioned functions.
a) add b) delete c) peep d) displayQueue e)isQueueFull
f) isQueueEmpty*/

#include<stdio.h>
#include<stdlib.h>


#define SIZE 5

void enqueue(int *, int *, int *,  int);
int dequeue(int *, int *, int *);
void display(int *);



int main(){

	int arr[SIZE];
	int front=-1, rear=-1;
	int choice, ele;
	int ret;
	for(int i=0; i<SIZE; i++)
		arr[i]=-99;
	while(1){
	printf("enter 1-> enqueue, 2->dequeue, 3->display, 4->exit\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			printf("element to push\n");
			scanf("%d", &ele);
			enqueue(arr, &front,&rear , ele);
			break;
		case 2:
			ret=dequeue(arr, &front, &rear);
			if(ret!=-77)
				printf("popped item=%d\n", ret);
	
			break;
		case 3:
			printf("stack: ");
			display(arr);
			printf("\n");
			break;		
		case 4:
			exit(1);
	}}
}

void enqueue(int *arr, int *f,int *r, int ele){
	if(*r==SIZE-1 )// queue full cond
	{
		printf("queue full");
		return;
	}
	*r=*r+1;
	arr[*r]=ele;

	if(*f==-1)
		*f=0;
}
int dequeue(int *arr, int *f, int *r){
	if(*f==-1){
		printf("queue empty");
		return -77;
	}

	int temp=arr[*f];
	arr[*f]=-99;
	if(*f==*r){
		*f=*r=-1;
	}else {
		*f=*f+1;
	}
	return temp;
}
void display(int *arr){
	for(int i=0; i<SIZE; i++){
		printf("|%d|", arr[i]);
	}
}

