/*write the code for single linklist for student data insert the student data delete the student data and display the student data write all features in c lan */


#include <stdio.h>
#include <stdlib.h>

	struct student{

	char name[10];
	int prn;
	int mob_num;
	
	};
	
 	struct node {

	struct student data;
	struct node *next;
	
	};
	
	
	struct node *head = NULL;
	
	 void Insert_data();
	 void display();

int main(){


	int choice;
	int data;
	int x;
	
	
	while(1){
	
	
	printf("Enter your Choice \n1.Insert_data \n2.Display_data \n3.Delete_data \n4.Exit \n");
	scanf("%d",&choice);
	
	
	switch(choice){
	
	
		case 1:
		       Insert_data();
		       break;
		       
		       
		case 2:
		       display();
		       break;
		       
		case 3: 
		
		      printf("Enter the PRN which one you delete \n");
		      scanf("%d",&x);
		      break;
		      
		case 4:
		      exit(1);
		      
		      
		      }
           }
           
       }
       
       
       void Insert_data(){
       
       struct node *newnode = (struct node *)malloc(sizeof(struct node));
       
       
       printf("***********************************************\n");
       printf("Enter the Student Name \n");
       scanf("%s", newnode->data.name);
       printf("Enter the student PRN Number \n");
       scanf("%d",&newnode->data.prn);
       printf("Enter the student Mobile Number \n");
       scanf("%d",&newnode->data.mob_num);
       printf("***********************************************\n");
       
       
       newnode ->next = NULL;
       
       if(head == NULL){
       head = newnode;
       }
       
       else{
       
       struct node *temp = head;
       while(temp -> next != NULL){
       temp = temp -> next;
       }
       
       temp -> next = newnode;
       }
       
       }
       
       void display(){
       
       if (head == NULL){
       printf("Student data will Empty \n");
       return ;
       
       }
       
       
       struct node *temp = head;
       
       
       while(temp != NULL){
       
       
       printf("***********************************************\n");
       printf("Student Name:- %s \n",temp->data.name);
       printf("Student PRN Number:- %d \n",temp->data.prn);
       printf("Student Mobile Number:- %d \n",temp -> data.mob_num); 
       printf("***********************************************\n");
       
       temp = temp -> next;
       }
       
       }
       
       
       void delete_data(int prn){
       
       struct node *temp = head;
       struct node *prev = NULL;
       
       
       if(temp != NULL && temp -> data.prn == prn){
       
       head = temp -> next;
       
       free(temp);
       printf("Enter student Prn %d Was deleted \n");
       
       return ;
       
       }
       }
       
       
       
       
       
       
	
	
