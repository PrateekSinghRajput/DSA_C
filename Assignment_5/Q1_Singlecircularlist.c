/*Q1. Write a C/C++ program to implement single circular linked list
with below metioned functionality.
a) insertAtEnd b) insertAtBeg c) insertAtPos
d) display e) listNodeCount f) deleteFromEnd
g) deleteFromBeg h) deleteFromPos */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *next;
	int data;

};
void insertAtEnd(struct node** head,int ele);
void insertAtBeg(struct node** head,int ele);
void insertAtPos(struct node** head,int ele,int pos);
void deleteFromEnd(struct node** head);
void display(struct node* head);
int main()
{	
	struct node *head=NULL;
	int ch,ele,pos;

	while(1)
	{
		printf("Choose the operation\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("Enter the element\n");
				scanf("%d",&ele);
				insertAtEnd(&head,ele);
				break;
			case 2:
				display(head);
				printf("\n");
				break;
			case 3:
				printf("Enter the element\n");
				scanf("%d",&ele);
				insertAtBeg(&head,ele);
				break;
			case 4:
				printf("Enter the position\n");
				scanf("%d",&pos);
				printf("Enter the element\n");
				scanf("%d",&ele);
				insertAtPos(&head,ele,pos);
				break;
			case 5:
				deleteFromEnd(&head);
				break;
		}
	}
}
void insertAtEnd(struct node** head,int ele)
{
	struct node *t1;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	t1=*head;
	temp->data=ele;
	temp->next=temp;

	if(*head==NULL)
	{
		*head=temp;
		return;
	}

	while(t1->next!=*head)
	{
		t1=t1->next;
	}

	t1->next=temp;
	temp->next=*head;
}
void display(struct node* head)
{
	struct node *t1;
	t1=head;
	if(head==NULL)
	{
		printf("Link list is empty\n");
		return;
	}
	
	
	while(t1->next!=head)
	{
		printf("--[%d]",t1->data);
		t1=t1->next;

	}
	printf("-->[%d]",t1->data);
}
void insertAtBeg(struct node** head,int ele)
{
	struct node *t1,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	t1=*head;
	temp->data=ele;
	temp->next=NULL;

	if(*head==NULL)
	{
		*head=temp;
		return;
	}

	while(t1->next!=*head)
	{
		t1=t1->next;
	}

	temp->next=*head;
	*head=temp;
	t1->next=*head;

}
void insertAtPos(struct node** head,int ele,int pos)
{	
	int count=1;
	struct node *temp;
	struct node *t1,*t2;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=temp;
	t1=*head;
	if(*head==NULL)
	{
		*head=temp;
		return;
	}

	if(pos==1)
	{
		insertAtBeg(head,ele);
		return;
	}
	while(t1->next!=*head&&count<pos)
	{
		++count;
		if(count==pos)
		{
			//t1->next=temp;
			temp->next=t1->next->next;
			t1->next=temp;
			return;
		}
		t1=t1->next;
	}

	insertAtEnd(head,ele);
	printf("you entered position is not available. then element is add to the last of the Link List\n");

}
void deleteFromEnd(struct node** head)
{
	struct node *t1,*t2;
	t1=*head;

	if(*head==NULL)
	{
		printf("LIST IS EMPTY\n");
		return;
	}

	while(t1->next!=*head)
	{
		t2=t1;
		t1=t1->next;
	}

	//t2->next=*head;
//	free(t1);
	//t2->next=*head;
	if(*head==t1)
	{
		*head=NULL;
		return;
	}
	t2->next=*head;
	free(t1);


}
