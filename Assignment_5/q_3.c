/*
Q3. Write a C program to implement doubly circular linked list with below mentioned functionality.

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
    if (*head == NULL) {
        temp->next = temp;
        temp->prev = temp;
        *head = temp;
    } else {
        struct node *last = (*head)->prev;
        temp->next = *head;
        temp->prev = last;
        last->next = temp;
        (*head)->prev = temp;
    }
}

// Function to insert at the beginning
void insertAtBeg(struct node **head, int x) {
    insertAtEnd(head, x);
    *head = (*head)->prev; // Move head to the newly inserted node
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
        struct node *curr = *head;
        for (int i = 1; i < pos - 1; i++) {
            curr = curr->next;
        }
        temp->next = curr->next;
        temp->prev = curr;
        curr->next->prev = temp;
        curr->next = temp;
    }
}

// Function to display the list and verify doubly circularity
void display(struct node *p) {
    if (p == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Circular Linked List (Prev ↔ Current ↔ Next):\n");
    struct node *start = p;
    do {
        // Print previous node's data (or head's prev if at head)
        printf("[Prev:%d ", p->prev->data);
        // Print current node's data
        printf("Cur:%d ", p->data);
        // Print next node's data (or head's next if at tail)
        printf("Next:%d] <--> ", p->next->data);
        p = p->next;
    } while (p != start);
    printf("\n");

    // Verification print statements
    printf("Verification: head->prev->data = %d, tail->next->data = %d\n",
           start->prev->data, start->prev->next->data);
    if (start->prev->next == start && start->prev == p->prev)
        printf("List is circular and doubly linked!\n");
}

// Function to count nodes
int listNodeCount(struct node *head) {
    if (head == NULL) return 0;
    int count = 1;
    struct node *temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to delete from the end
void deleteFromEnd(struct node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *last = (*head)->prev;
    if (last == *head) { // Only one node
        free(last);
        *head = NULL;
    } else {
        last->prev->next = *head;
        (*head)->prev = last->prev;
        free(last);
    }
}

// Function to delete from the beginning
void deleteFromBeg(struct node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *first = *head;
    if (first->next == first) { // Only one node
        free(first);
        *head = NULL;
    } else {
        struct node *last = first->prev;
        *head = first->next;
        last->next = *head;
        (*head)->prev = last;
        free(first);
    }
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
        struct node *curr = *head;
        for (int i = 1; i < pos; i++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
    }
}

