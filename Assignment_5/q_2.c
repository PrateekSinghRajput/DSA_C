/*
Q2. Write a C program to implement doubly linked list with below mentioned functions functionality.

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

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Function prototypes
void insertAtEnd(struct node **head, int x);
void insertAtBeg(struct node **head, int x);
void insertAtPos(struct node **head, int x, int pos);
void display(struct node *p);
int listNodeCount(struct node *head);
void deleteFromEnd(struct node **head);
void deleteFromBeg(struct node **head);
void deleteFromPos(struct node **head, int pos);

int main() {
    struct node *head = NULL;
    int ch, ele, pos, cnt = 0;

    while (1) {
        printf("\n------------Menu------------\n");
        printf("1. insertAtEnd\n");
        printf("2. insertAtBeg\n");
        printf("3. insertAtPos\n");
        printf("4. displayList\n");
        printf("5. listNodeCount\n");
        printf("6. deleteFromEnd\n");
        printf("7. deleteFromBeg\n");
        printf("8. deleteFromPos\n");
        printf("9. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                insertAtEnd(&head, ele);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &ele);
                insertAtBeg(&head, ele);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d", &ele);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPos(&head, ele, pos);
                break;
            case 4:
                display(head);
                break;
            case 5:
                cnt = listNodeCount(head);
                printf("Node count = %d\n", cnt);
                break;
            case 6:
                deleteFromEnd(&head);
                break;
            case 7:
                deleteFromBeg(&head);
                break;
            case 8:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteFromPos(&head, pos);
                break;
            case 9:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to insert at the end
void insertAtEnd(struct node **head, int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (*head == NULL) {
        temp->prev = NULL;
        *head = temp;
    } else {
        struct node *t1 = *head;
        while (t1->next != NULL) {
            t1 = t1->next;
        }
        t1->next = temp;
        temp->prev = t1;
    }
}

// Function to insert at the beginning
void insertAtBeg(struct node **head, int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = *head;

    if (*head != NULL) {
        (*head)->prev = temp;
    }
    *head = temp;
}

// Function to insert at a specific position
void insertAtPos(struct node **head, int x, int pos) {
    int count = listNodeCount(*head);
    if (pos < 1 || pos > count + 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtBeg(head, x);
    } else if (pos == count + 1) {
        insertAtEnd(head, x);
    } else {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        struct node *t1 = *head;
        for (int i = 1; i < pos - 1; i++) {
            t1 = t1->next;
        }
        temp->next = t1->next;
        temp->prev = t1;
        t1->next->prev = temp;
        t1->next = temp;
    }
}

// Function to display the list
void display(struct node *p) {
    if (p == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List (Prev ↔ Current ↔ Next):\n");
    while (p != NULL) {
        // Print previous node's data (or NULL)
        if (p->prev) 
            printf("[%d ↔ ", p->prev->data);
        else
            printf("[NULL ↔ ");

        // Print current node's data
        printf("%d ↔ ", p->data);

        // Print next node's data (or NULL)
        if (p->next) 
            printf("%d] <--> ", p->next->data);
        else
            printf("NULL]");
        
        p = p->next;
    }
    printf("\n");
}


// Function to count nodes
int listNodeCount(struct node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to delete from the end
void deleteFromEnd(struct node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}

// Function to delete from the beginning
void deleteFromBeg(struct node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete from a specific position
void deleteFromPos(struct node **head, int pos) {
    int count = listNodeCount(*head);
    if (pos < 1 || pos > count) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        deleteFromBeg(head);
    } else if (pos == count) {
        deleteFromEnd(head);
    } else {
        struct node *temp = *head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

