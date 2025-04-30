/*Q2. Write a C/C++ program to implement doubly linked list with below
metioned functions functionality.
a) insertAtEnd b) insertAtBeg c) insertAtPos
d) display e) listNodeCount f) deleteFromEnd
g) deleteFromBeg h) deleteFromPos */

#include<stdio.h>
#include<stdlib.h>

struct node{
	
	struct node* next;
	struct node* prev;
	int data;
};

void display(struct node *head);
void insertAtEnd(struct node** head,int ele);
void insertAtPos(struct node** head,int ele,int pos);
void deleteAtEnd(struct node** head);
void deleteAtBeg(struct node** head);
int main()
{
	struct node *head=NULL;
	int ch;
	int ele,pos;

	while(1)
	{
		printf("choose the operation\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("Enter the ele\n");
				scanf("%d",&ele);
				insertAtEnd(&head,ele);
				break;
			case 2:
				display(head);
				break;
			case 3:
				printf("Enter the ele\n");
				scanf("%d",&ele);
				printf("Enter the position\n");
				scanf("%d",&pos);
				insertAtPos(&head,ele,pos);
				break;
			case 4:
				deleteAtEnd(&head);
				break;
			case 5:
				deleteAtBeg(&head);
				break;
		}
	}
}
void insertAtEnd(struct node** head,int ele)
{
	struct node* temp;
	struct node* t1,*t2;
	temp=(struct node*)malloc(sizeof(struct node));
	
	t1=*head;
	t2=*head;
	temp->next=temp;
	temp->prev=temp;
	temp->data=ele;

	if(*head==NULL)
	{
		*head=temp;
		return;
	}

	do
	{

		t1=t1->next;
	}
	while(t1->next!=*head);

	t1->next=temp;
	temp->prev=t1;
	temp->next=t2;
	t2->prev=temp;
}
void display(struct node* head)
{
	struct node *t1;
	t1=head;

	if(head==NULL)
	{
		printf("Link list is not available\n");
		return;
	}

	do
	{	
		printf("-->[%d]<--",t1->data);
		t1=t1->next;
	}while(t1!=head);
	printf("\n");
	printf("reverse\n");

	do
	{	


//		printf("<--[%d]",t1->data);
		t1=t1->prev;
		printf("<--[%d]",t1->data);

	}while(t1!=head);
	printf("\n");

}

void insertAtPos(struct node** head,int ele,int pos)
{	
	struct node *temp;
	struct node *t1,*t2;
	t1=*head;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=temp->prev=temp;

	int count=0;
	if(*head==NULL)
	{
		*head=temp;
		return;
	}
	do
	{	
		
		++count;
		printf("count==%d\n",count);
		if(count==pos-1)
		{

			t2=t1->next;
			t2->prev=temp;
			temp->next=t1->next;
			t1->next=temp;
			temp->prev=t1;
		
			
		}
		t1=t1->next;
	}while(t1->next!=*head);



}
void deleteAtEnd(struct node** head)
{
	struct node *t1,*t2;
	t1=*head;

	do
	{	
		t2=t1;
		t1=t1->next;
		
	}while(t1->next!=*head);
	
	free(t1);
	t2->next=*head;
	(*head)->prev=t2;


}
void deleteAtBeg(struct node** head)
{
	struct node *t1,*t2,*t3;
	t1=*head;
	t3=*head;
	t2=t1->next;

	do
	{
		t1=t1->next;
	}while(t1->next!=*head);

	*head=t2;
	free(t3);
	t2->prev=t1;
	t1->next=t2;



}
