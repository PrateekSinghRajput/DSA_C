
/*   Q2. Write a C/C++ program to implement single linked list.
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode l) reverseList m)sortedList

*/

#include <stdio.h>
#include <stdlib.h>


struct node{ ///here we define the struct for new node and data 

	int data;
	struct node *next;
	
	
	};
	
	
	struct node *head = NULL;
	
void insertAtBeg(int x);
void insertAtEnd(int x);
void display(int x);
void Delete_End();
void Delete_beg();
void Insert_pos();
void Delete_pos();
	
int main(){
	
	int choice;
	int x;
	int pos;
	
	while(1){
	
	printf("Enter your Choice  \n1->Insert Beg \n2->Insert End \n3->Display \n4->DeleteFromEnd \n5->DeleteFromBeg  \n6->Insert_pos  \n7-> Exit \n");
	scanf("%d",&choice);
	
		switch(choice){
		
		case 1:
		   printf("Write the element to insert beg \n");
		   scanf("%d",&x);
		   insertAtBeg(x);
		   break;
		   
		case 2:
		  printf("write the element to insert in end \n");
		  scanf("%d",&x);
		  insertAtEnd(x);
		  break;
		  
		case 3:
		     display(x);
		     break;
		     
		case 4:
		     Delete_End();
		     break;
		     
		case 5:
		     Delete_beg();
		     break;

		     
		 case 6:
		 printf("enter the element to enter at position\n");
		 scanf("%d" ,&x);
		 printf("enter the Position to enter \n");
		 scanf("%d",&pos);
		 Insert_pos(x);
		 break;
		     
		 case 7:
		  printf("enter the position to delete \n");
		  scanf("%d" ,&pos);
		  
		 
		    	 
		case 8:
		exit(0);
		
		}
		}
	}
	
	
	void insertAtBeg(int x){
	
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = x;
	temp -> next = NULL;
	temp -> next = head;
	head = temp;
	
	}
	
	void insertAtEnd(int x){
	
	struct node *temp;
	struct node *t1;
	
	t1= head;
	
	temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = x;
	temp-> next =NULL;
	
	if(head == NULL){
	head =  temp;
	}
	else{
	while (t1 -> next != NULL){
	t1 = t1->next;
	}
	
	t1-> next = temp;
	
	}
	}
	
	void display(int x){
	
	struct node *t1;
	
	t1 = head;
	
	while(t1 != NULL){
	
	printf("-->[%d]",t1-> data);
	t1 = t1-> next;
	}
	printf("\n");
	}
	
	
	void Delete_End(){
	
	struct node *t1, *t2;
	t1 = head;
	t2 = NULL;        
	
	while(t1-> next != NULL){
	
	t2 = t1;
	t1 = t1 -> next;
	}
	
	free(t1);
	
	t2->next = NULL;
	
	}
	
	
	void Delete_beg(){
	
	struct node *t1;
	
	t1 = head;
	head = t1-> next;
	
	
	free(t1);
	
	}
	
	
	void Insert_pos(int x ,int pos ){
	struct node *temp;
	struct node *t1;
	t1 = head;
	
	temp =(struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->next=NULL;
	
	int count =1;
	
	while (count < pos-1){
	
	t1 = t1->next;
	count++;
	
}	
	temp -> next = t1 -> next;
	t1 -> next =  temp;
	

	}
	
void Delete_pos(int pos){
	struct node *t1 , *t2;
	
	t1 = head;
	t2 = NULL;
	
	int count = 1;
	while (count < pos ){
	t2 = t1;
	t1 = t1 ->next;
	count++;
	}
	t2-> next = t1-> next;
	free(t1);
	
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
