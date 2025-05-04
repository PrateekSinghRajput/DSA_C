/*
Q1. Write a C program to implement single circular linked list with below mentioned functionality.
a) insertAtEnd 
b) insertAtBeg 
c) insertAtPos
d) display 
e) listNodeCount
f) deleteFromEnd
g) deleteFromBeg 
h) deleteFromPos
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};


//function prototypes
void insertAtEnd(struct node **p, int x);
void insertAtBeg(struct node **head, int x);
void insertAtPos(struct node **head, int x, int pos);
void display(struct node* p);
int listNodeCount(struct node *head);
void deleteFromEnd(struct node **head);
void deleteFromBeg(struct node **head);
void deleteFromPos(struct node **head, int pos);

int main()
{
	//pass by reference approach
	//declaring head a local var to main()
	struct node *head = NULL;
	
	int ch, ele, pos, cnt=0;;
	
	while(1)
	{
		printf("------------Menu------------");
		printf("\n1. insertAtEnd\n");
		printf("2. insertAtBeg\n");
		printf("3. insertAtPos\n");
		printf("4. displayList\n");
		printf("5. listNodeCount\n");
		printf("6. deleteFromEnd\n");
		printf("7. deleteFromBeg\n");
		printf("8. deleteFromPos\n");
		printf("9. EXIT\n");
		
		
		printf("Enter your choice: \n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter element: \n");
				scanf("%d",&ele);
				insertAtEnd(&head,ele);
				printf("Element inserted at the end!\n");
				break;
			case 2:
				printf("Enter element: \n");
				scanf("%d",&ele);
				insertAtBeg(&head,ele);
				printf("Element inserted at the beginning!\n");
				break;
			case 3:
				printf("Enter element: \n");
				scanf("%d",&ele);
				printf("Enter position: \n");
				scanf("%d",&pos);
				insertAtPos(&head,ele,pos);
				printf("Element inserted at position %d!\n",pos);
				break;
			case 4:
				display(head);
				break;
			case 5:
				cnt = listNodeCount(head);
				printf("Node count = %d\n",cnt);
				break;
			case 6:
				deleteFromEnd(&head);
				printf("Element deleted from the end!\n");
				break;
			case 7:
				deleteFromBeg(&head);
				printf("Element deleted from the beginning!\n");
				break;
			case 8:
				printf("Enter position: \n");
				scanf("%d",&pos);			
				deleteFromPos(&head,pos);
				printf("Element deleted from position %d!\n",pos);				
				break;
			case 9:
				printf("Exiting...");
				exit(-1);
				break;
			default:
				printf("Invalid choice! Enter a valid choice");							
		}
	}
	return 0;
}


//function to insert element at the end of linked list
void insertAtEnd(struct node **head, int x)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node)); //DMA for temp node
	
	temp -> data=x; // assign the val of temp node to data
	temp -> next = NULL; //make the next ptr of temp node as NULL
	
	
	//check if head ptr is NULL
	if (*head == NULL) 
	{
		*head = temp;
		temp->next = temp;  // Circular link to itself
   	 } else {
        // Traverse to the last node (whose next points to head)
        struct node *t1 = *head;
        
        while (t1->next != *head) 
        {
            t1 = t1->next; //to jump node by node. Access
        }
        // Insert new node at the end and maintain circular link
        t1->next = temp; //linking the node
        temp->next = *head;
	}
}


void insertAtBeg(struct node **head, int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node)); // DMA for temp node
    
    temp->data = x;
    temp->next = NULL;

    if (*head == NULL) {
        // If list is empty, new node points to itself
        *head = temp;
        temp->next = temp;
    } else {
        // Find the last node to update its next pointer
        struct node *t1 = *head;
        while (t1->next != *head) {
            t1 = t1->next;
        }
        // Insert new node at beginning
        temp->next = *head;
        t1->next = temp;
        *head = temp;  // Update head to new node
    }
}

void insertAtPos(struct node **head, int x, int pos)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node)); // DMA for temp node
    temp->data = x;
    temp->next = NULL;

    if (*head == NULL) {
        // If list is empty, only valid position is 1
        if (pos != 1) {
            printf("Position out of range\n");
            free(temp);
            return;
        }
        *head = temp;
        temp->next = temp;
        return;
    }

    if (pos == 1) {
        // Insert at beginning (reuse insertAtBeg logic)
        insertAtBeg(head,x);
        return;
    }

    // Insert at position > 1
    struct node *current = *head;
    int count = 1;

    // Traverse to the node just before the position
    while (count < pos - 1 && current->next != *head) 
    {
        current = current->next;
        count++;
    }

    // If position is beyond the length + 1, invalid
    if (count != pos - 1) {
        printf("Position out of range\n");
        free(temp);
        return;
    }

    // Insert the new node
    temp->next = current->next;
    current->next = temp;
}



// Function to display the list
void display(struct node* p) 
{
    if (p == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    struct node* t1 = NULL;
    t1 = p;
    
    printf("Circular Linked List: \n");
    printf("-->[%d]", t1->data);
    t1 = t1->next;
    
    while (t1 != p)
    {
        printf("-->[%d]", t1->data);
        t1 = t1->next;
    } 
    printf("\n");
}

// function to count the no of nodes
//head is passed as arg to this fun
int listNodeCount(struct node *head)
{
    if (head == NULL)
        return 0;

    int count = 1;
    struct node *temp = head->next;

    while (temp != head) {
        count++;
        temp = temp->next;
    }

    return count;
}


// Function to delete from end from the list
void deleteFromEnd(struct node **head)
{
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If only one node is present
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    struct node *temp = *head;
    struct node *t1 = NULL;

    // Traverse to the last node
    while (temp->next != *head) {
        t1 = temp;
        temp = temp->next;
    }

    // t1 now points to second last node
    t1->next = *head; // Remove last node by linking second last to head
    free(temp);
}


// Function to delete from beginning from the list
void deleteFromBeg(struct node **head)
{
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If only one node is present
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    struct node *temp = *head;
    struct node *last = *head;

    // Find the last node to update its next pointer
    while (last->next != *head) 
    {
        last = last->next;
    }

    last->next = temp->next; // Point last node to new head
    *head = temp->next;      // Update head to next node
    free(temp);              // Free old head
}


// Function to delete from a given position from the list
void deleteFromPos(struct node **head, int pos)
{
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    int count = 1;
    struct node *temp = *head;
    // Count the number of nodes
    while (temp->next != *head) {
        count++;
        temp = temp->next;
    }

    // Check if position is valid
    if (pos < 1 || pos > count) {
        printf("Invalid position.\n");
        return;
    }

    // Deleting the first node
    if (pos == 1) {
        // If only one node is present
        if ((*head)->next == *head) {
            free(*head);
            *head = NULL;
            return;
        }
        // Find the last node to update its next pointer
        struct node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        temp = *head;
        last->next = temp->next;
        *head = temp->next;
        free(temp);
        return;
    }

    // Deleting node at position > 1
    struct node *prev = *head;
    for (int i = 1; i < pos - 1; i++) {
        prev = prev->next;
    }
    temp = prev->next;
    prev->next = temp->next;
    free(temp);
}
