/*Q4. Write a C/C++ program to implement single linked list to store
Student Information ( StudentName and StudentPRN).
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode  

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


	struct student{ //the struct sotre the student name and prn number

	char name[10]; //here we take char size 10
	int prn;  // 
	
	};
	
	struct node{ //the struct define for new student 

	struct student data;
	struct node *next;

};
\

void insertAtEnd();  //the function used for insert the new student data for at the end
void displayList();  //the function used for display the all store student data
void insertAtbeg();
void insertAtpos();
void deletefromfront();
void deletefromend();
void deletefrompos();
int listNodeCount();
void freeAllNodes();


struct node *head = NULL; //start the head pointer is NULL
	
	
int main(){
	
	int choice;
	int x;
	
	while(1){
	
	printf("enter your choice \n1->Insert_AT_End \n");
	printf("\n2 ->Insert_AT_Beg \n");
	printf("\n3 ->Insert_AT_Pos \n");
	printf("\n4 ->Display_List \n");
	printf("\n5->Delete_from_front \n");
	printf("\n6->Delete_from_end\n");
	printf("\n7->Delete_from_pos\n");
	printf("\n8->List_Node_count\n");
	printf("\n9->free_all_node\n");
	
	
	scanf("%d",&choice);
	
	
	switch(choice){
		
		case 1:
		    insertAtEnd();
		    break;
		    
		    
		case 2:
		    insertAtbeg();
		    break;
		    
		case 3:
		    insertAtpos();

		    break;
		    
	        case 4:
	            displayList();
	            break;
	            
	         case 5:
	            deletefromfront();
	            break;
	            
	            case 6:
	            deletefromend();
	            break;
	            
	            
	           case 7:
	            deletefrompos();
	           	break;
	           	
	            case 8:
	            listNodeCount();
	           	break;
	            	
	            
	           case 9: 
	           freeAllNodes();
	           break;
	            
	            
	        case 10:
	            exit(0);
	            
	            
	  }
	  
 }
	  
}


	void insertAtEnd(){
	 
	 	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	 	
	 	//malloc the newnode to take new size for new struct
	 	
	 	printf("Enter the student name \n");
	 	scanf("%s",newnode -> data.name); 
	 	
	 	printf("Enter the student PRN Number \n");
	 	scanf("%d",&newnode -> data.prn);
	 	
	 	newnode -> next = NULL;
	 	
	 	
	 	if(head == NULL){
	 	
	 		head = newnode;
	 		
	 		}
	 		
	 	else {
	 	
	 		struct node *temp = head;
	 		
	 		while(temp -> next != NULL){
	 		
	 		 	temp = temp -> next;
	 		 }
	 		 
	 		 temp -> next = newnode;
	 		 
	 	}
	 	
	 }
	 
	 
	 
	 void insertAtbeg(){
	 
	 	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	 	
	 	printf("Enter Student Name \n ");
	 	scanf("%s",newnode -> data.name);
	 	
	 	printf("Enter Student PRN Number \n");
	 	scanf("%d",&newnode -> data.prn);
	 	
	 	
	 	newnode -> next = head;
	 	
	 	head = newnode;
	 	
	 	}
	 
	
	 void insertAtpos(){
	 
	 	int pos;
	 	int count = 1;
	 	
	 	
	 	printf("Enter postionto insert \n");
	 	scanf("%d",&pos);
	 	
	 	
	 	
	 	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	 	
	 	printf("Enter Student Name \n");
	 	scanf("%s",newnode -> data.name);
	 	
	 	printf("Enter student PRN Number \n");
	 	scanf("%d", &newnode -> data.prn);
	 	
	 	if(pos == 1){
	 	
	 	newnode -> next = head;
	 	head = newnode;
	 	
	 	}
	 	
	 	else{
	 	
	 	struct node *temp = head;
	 	while(count < pos -1){
	 	temp = temp -> next;
	 	count ++;
	 	}
	 	
	 	
	 	newnode -> next  = temp -> next;
	 	temp -> next = newnode;
	 	}
	 	}
	 
	 void displayList(){
	 
	 	if (head == NULL){
	 	
	 		printf("List is empty != \n");
	 		return ;
	 		
	 	}
	 	
	 	struct node *temp = head;
	 	
	 	while(temp != NULL){
	 	
	 	printf("Name %s, PRN %d \n",temp-> data.name , temp -> data.prn);
	 	
	 	temp = temp -> next;
	 	
	 	}
	 	
	 }
	 
	 
	 
	 
	 
	void deletefromfront(){
	 	int pos;
	 	
	 	
	 	printf("Enter postion to delete \n");
	 	scanf("%d",&pos);
	 	
	 	struct node *temp;
	 	temp = head;
	 	
	 	head = temp -> next;
	 	free (temp);
	 	
	 	}
	 	
	 void deletefromend(){
	 
	 
	 struct node *temp ,*t2;
	 temp = head;
	 
	 while(temp-> next != NULL){
	  	t2 = temp;
	  	temp = t2->next;
	  	}
	  	free(temp);
	  	 t2-> next = NULL;
	
	  	}
	  	
	  
	    void deletefrompos(){
	     int pos;
	     int count = 1 ;
	     
	     printf("enter the pos to delete ");
	     scanf("%d", &pos);
	     
	     struct node *temp , *t2;
	     
	     temp = head;
	     t2 = NULL;


	     
	     while(count < pos ){
	     
	     t2 = temp;
	     temp = temp-> next;
	     count++;
	     }
	     t2-> next = temp->next;
	     free(temp);
	     
	     } 
	     
	    
		int listNodeCount() {
    		int count = 0;
    	
    	struct node *temp = head;
    	
    	while (temp != NULL) {
        	count++;
       	 temp = temp->next;
   	 }
    	return count;
}
	     
	void freeAllNodes() {
    	struct node *temp = head;
    	
    	while (temp != NULL) {
        	struct node *nextNode = temp->next;
        	
        	free(temp);
        	
        	temp = nextNode;
   	 }
    	head = NULL;
    	
    	printf("All nodes have been freed.\n");
	
	}
	     
	     
	     
	     
	     
	     
	     
	     
	     
	     
	     
	    
	     
	     
	  	
	  	
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	   	
	 
	 	

		    
