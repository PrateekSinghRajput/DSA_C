/* Doubly link list using pass by address approach 1.insertatend 2.deletefronend  3.display  */

#include <stdio.h>
#include <stdlib.h>

struct node{

	int data;
	struct node *next;
	struct node *prev;
	
	};


void insertAtEnd(struct node **head, int x);
void display(struct node *head);
	
int main(){

struct node *head = NULL;
struct node *next = NULL;
struct node *prev = NULL;

int choice , x;

	printf("1. Insert at end\n");
        printf("2. Delete from end\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

	while(1){

	switch(choice){
	
	case 1:
	    printf("Enter the element to insert in end \n ");
	    scanf("%d",&x);
	    insertAtEnd(&head, x);
	    break;
	
	case 2:
	    //deletefronend();
	    break;

	case 3:
	    display(head);
	    break;
	    
	case 4:
	    exit(0);
	    
	  }
	  
	  
	 }
 }
 

void insertAtEnd(struct node **head, int x) {

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (*head == NULL) {
        temp->prev = NULL;
        *head = temp;
        return;
    }
    struct node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = temp;
    temp->prev = last;

}
 
 
 
 void display(struct node *head) {

    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}
 
 
 
 
	  
	  
	  
	   
