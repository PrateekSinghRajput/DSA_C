#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node  *next;
};


struct node *head = NULL;

void insert_end(int);
void display();
void Delete_End();

int main(){

int x,choice;

while(1){
	
	printf("Enter your Choice  \n1->Insert End \n2->Display \n3->DeleteFromEnd \n4-> Exit \n");
	scanf("%d",&choice);
	
		switch(choice){
		
		
		case 1:
		  printf("write the element to insert in end \n");
		  scanf("%d",&x);
		  insert_end(x);
		  break;

		case 2:
		     display(x);
		     break;
		     
		case 3:
		     Delete_End();
		     break;
		     
		     
		case 4:
		exit(0);
		
		}
		}
	}

void insert_end(int x){

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



void display(){

struct node *t1;
t1=head;
	while(t1!=NULL){
	printf("---->[%d]", t1->data);
	t1=t1->next;
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
