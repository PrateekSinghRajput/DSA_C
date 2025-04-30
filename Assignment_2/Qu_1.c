/*Q1. Write a C/C++ program to implement Linear Search. We need to check for duplicate inputs. If the
duplicate element is allowed then a linear search algo needs to implement accordingly. An
appropriate condition check needs to apply for element not found scenario.
(a) Search Element ( iterative approach )
(b) Search Element ( recursion approach )
(c) Print Input array ( iterative approach )
(d) Print Input array ( recursion approach )
(e) Print Input array reverse order ( iterative approach )
(f) Print Input array reverse order ( recursion approach ) */

#include <stdio.h>
#include <stdlib.h>

int search_element(int arr[],int size);
int check_duplicate(int* arr,int size,int n);
int reverse_element(int arr[],int size);

int main(){

int arr[10] = {10,20,-11,40,50,60,70,80,90,100};
int size = 10;
int element;


int choice;
printf("\n Enter Your Choice \n 1.Search Element \n 2.Print Input array \n 3.Print Input array reverse order \n 4.EXIT \n");
scanf("%d",&choice);

while(1){
switch(choice){
	 case 1:
	 printf("\n Search Element ( iterative approach ) \n");
	 search_element(arr,size);
	 break;
	 
	 case 2:
	 printf("\n Print Input array ( iterative approach ) \n");
	 
	 break;
	 
	 case 3:
	 printf(" \n Print Input array reverse order ( iterative approach )  \n");
	 reverse_element(arr,size);
	 break;
	 
	 case 4:
	 exit(0);
	 
	 }
	 }

printf("Current Array Elements \n");
for(int i=0;i<size;i++){
printf(" %d", arr[i]);

}

printf("\n Enter the Number what you want \n");
scanf("%d",&element);
check_duplicate(arr,size,element);
printf("\n Current Array Element \n");

	for(int i=0;i<size;i++){
	printf(" %d",arr[i]);
	}

	printf("\n");

search_element(arr,size);
reverse_element(arr,size);

}



int check_duplicate(int* arr,int size,int n){

int empty = -11;
char ch;

	for(int i=0;i<size;i++){

		if(arr[i] == -11){
		empty = i;
}

	else if(arr[i] == n){

printf("\nThe Element you enter is all reday exist at index %d do you want add or not y/n\n",i);
getchar();

scanf("%c",&ch);

	if (ch == 'n'){
		return 0;
}

	else if(ch == 'y'){
		continue;
}

	else{
		printf("Invaild Input \n");
	return 1;
}
}
}
	if(empty != -11){
	arr[empty] = n;
}
	else{
	printf("No Empty space \n");
}

}

int search_element(int arr[],int size){

int element;	

int flag=0;

	printf("\n Enter the array element to search \n");
	scanf("%d",&element);
	
 	for(int i=0;i<size;i++)
 	{ 
 	
 		if(arr[i] == element){
 		printf("\n your element is at index %d \n", i);
 		flag = 1;	
 	}
 	
 	else
 	{
 	printf("\n Arrar Element not found \n");
 	}
 	
 	
 
 		
 



int reverse_element(int arr[],int size){

printf("\n  Reverse Array Element is \n ");

	for(int i = size -1 ; i >= 0 ; i--){
	
	printf(" %d",arr[i]);
	 
	
	}
	
	
}







