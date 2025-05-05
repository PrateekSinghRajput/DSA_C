#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int prn;
    long mob_num;
};

struct node {
    struct student data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insert_data();
void display_forward();
void display_backward();
void delete_data();
void search_data();

int main() {
    int choice;
    
    while(1) {
        printf("\nStudent Data Management System (Doubly Linked List)\n");
        printf("1. Insert Student Data\n");
        printf("2. Display Data (Forward)\n");
        printf("3. Display Data (Backward)\n");
        printf("4. Delete Student Data\n");
        printf("5. Search Student Data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                insert_data();
                break;
            case 2:
                display_forward();
                break;
            case 3:
                display_backward();
                break;
            case 4:
                delete_data();
                break;
            case 5:
                search_data();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void insert_data() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    
    printf("\nEnter Student Details:\n");
    printf("Name: ");
    scanf("%s", newnode->data.name);
    printf("PRN: ");
    scanf("%d", &newnode->data.prn);
    printf("Mobile Number: ");
    scanf("%ld", &newnode->data.mob_num);
    
    newnode->prev = NULL;
    newnode->next = NULL;
    
    if(head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    
    printf("Student data inserted successfully!\n");
}

void display_forward() {
    if(head == NULL) {
        printf("\nStudent database is empty!\n");
        return;
    }
    
    struct node *temp = head;
    printf("\nStudent Data (Forward):\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-10s %-15s\n", "Name", "PRN", "Mobile Number");
    printf("--------------------------------------------------\n");
    
    while(temp != NULL) {
        printf("%-20s %-10d %-15ld\n", temp->data.name, temp->data.prn, temp->data.mob_num);
        temp = temp->next;
    }
    printf("--------------------------------------------------\n");
}

void display_backward() {
    if(tail == NULL) {
        printf("\nStudent database is empty!\n");
        return;
    }
    
    struct node *temp = tail;
    printf("\nStudent Data (Backward):\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-10s %-15s\n", "Name", "PRN", "Mobile Number");
    printf("--------------------------------------------------\n");
    
    while(temp != NULL) {
        printf("%-20s %-10d %-15ld\n", temp->data.name, temp->data.prn, temp->data.mob_num);
        temp = temp->prev;
    }
    printf("--------------------------------------------------\n");
}

void delete_data() {
    if(head == NULL) {
        printf("\nStudent database is empty!\n");
        return;
    }
    
    int prn;
    printf("\nEnter PRN of student to delete: ");
    scanf("%d", &prn);
    
    struct node *temp = head;
    
    // Search for the node to delete
    while(temp != NULL && temp->data.prn != prn) {
        temp = temp->next;
    }
    
    if(temp == NULL) {
        printf("\nStudent with PRN %d not found!\n", prn);
        return;
    }
    
    // Adjust pointers based on node position
    if(temp == head && temp == tail) {
        // Only one node in list
        head = tail = NULL;
    } else if(temp == head) {
        // Delete from head
        head = head->next;
        head->prev = NULL;
    } else if(temp == tail) {
        // Delete from tail
        tail = tail->prev;
        tail->next = NULL;
    } else {
        // Delete from middle
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    
    printf("\nDeleted student data:\n");
    printf("Name: %s\nPRN: %d\nMobile: %ld\n", 
           temp->data.name, temp->data.prn, temp->data.mob_num);
    
    free(temp);
}

void search_data() {
    if(head == NULL) {
        printf("\nStudent database is empty!\n");
        return;
    }
    
    int prn;
    printf("\nEnter PRN of student to search: ");
    scanf("%d", &prn);
    
    struct node *temp = head;
    int found = 0;
    
    while(temp != NULL) {
        if(temp->data.prn == prn) {
            printf("\nStudent Found:\n");
            printf("--------------------------------------------------\n");
            printf("%-20s %-10s %-15s\n", "Name", "PRN", "Mobile Number");
            printf("--------------------------------------------------\n");
            printf("%-20s %-10d %-15ld\n", temp->data.name, temp->data.prn, temp->data.mob_num);
            printf("--------------------------------------------------\n");
            found = 1;
            break;
        }
        temp = temp->next;
    }
    
    if(!found) {
        printf("\nStudent with PRN %d not found!\n", prn);
    }
}
