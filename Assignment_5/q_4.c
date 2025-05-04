/*
Q4. Write a C/C++ program to implement priority queue data structure using array.
*/

#include <stdio.h>
#define MAX 100

int pqVal[MAX];      // Array to store values
int pqPriority[MAX]; // Array to store priorities
int size = 0;


int main() {
    int choice, val, prio;
    while (1) {
        printf("\n1. Insert\n2. Delete Highest Priority\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &val, &prio);
                enqueue(val, prio);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}


// Function to insert an element into the priority queue
void enqueue(int value, int priority) {
    if (size == MAX) {
        printf("Priority Queue Overflow!\n");
        return;
    }
    int i = size - 1;
    // Move elements with lower priority forward
    while (i >= 0 && pqPriority[i] < priority) {
        pqVal[i + 1] = pqVal[i];
        pqPriority[i + 1] = pqPriority[i];
        i--;
    }
    // Insert the new element at correct position
    pqVal[i + 1] = value;
    pqPriority[i + 1] = priority;
    size++;
    printf("Inserted value %d with priority %d\n", value, priority);
}

// Function to remove the element with the highest priority
void dequeue() {
    if (size == 0) {
        printf("Priority Queue Underflow!\n");
        return;
    }
    printf("Deleted value %d with priority %d\n", pqVal[0], pqPriority[0]);
    // Shift all elements left
    for (int i = 1; i < size; i++) {
        pqVal[i - 1] = pqVal[i];
        pqPriority[i - 1] = pqPriority[i];
    }
    size--;
}

// Function to display the priority queue
void display() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("Priority Queue (value, priority):\n");
    for (int i = 0; i < size; i++) {
        printf("(%d, %d)\n", pqVal[i], pqPriority[i]);
    }
}

