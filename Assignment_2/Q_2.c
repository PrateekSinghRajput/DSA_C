/*Q2. Write a C/C++ program to implement Binary Search. We need to check for duplicate element
inputs, if found any should not insert into the input array. The array should manage in sorted order.
Apply a duplicacy check on the element while inserting the element, if found duplicate then discards
the input. The input element should insert in the array at the right position( index). Appropriate
shifting can be applied in the array in order to insert the input element at the right position. An
appropriate condition check needs to apply for element not found scenario.
(a) Binary Search ( iterative approach)
(b) Binary Search ( recursion approach ) */

#include <stdio.h>
#include <stdlib.h>

void insert(int*, int);
int bin_search_iter(int*, int, int);

int main() {
    int size, ch, element;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int *arr = (int*)malloc(sizeof(int) * size);
    if (arr == NULL) {
        printf("malloc failed\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        arr[i] = -22; // Initialize the array with -22
    }

    while (1) {
        printf("\nCurrent array:\n");
        for (int i = 0; i < size; i++) {
            printf("%d  ", arr[i]);
        }

        printf("\n\nWhat operation to perform?\n"
               "1. Insert element\n"
               "2. Search an element using iteration (binary search)\n"
               "3. Search an element using recursion (binary search)\n"
               "4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert(arr, size);
                break;
            case 2:
                printf("Enter the element you want to search\n");
                scanf("%d", &element);
                bin_search_iter(arr, size, element);
                break;
            case 3:
                exit(0);
                break;
            case 4:
                free(arr);
                exit(0);
        }
    }

    free(arr);
}

void insert(int* arr, int size) {
    int temp, i, empty_index = 1;

    for (i = 0; i < size; i++) {
        if (arr[i] == -22) {
            empty_index = i;
            break;
        }
    }

    if (empty_index != -1) {
        printf("Enter the element: ");
        scanf("%d", &temp);
        arr[empty_index] = temp; // Insert the element
    } else {
        printf("Array is full. Cannot insert new element.\n");
    }
}

int bin_search_iter(int* arr, int size, int element) {
    int start = 0, end = size - 1, mid;

    while (start <= end) {
        mid = (end + start) / 2;
        if (arr[mid] == element) {
            printf("Element found at index %d\n", mid);
            return mid;
        } else {
            if (element > arr[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    printf("Element not found in the array\n");
    return -1; // Element not found
}
int chck_duplicate(int *arr, int size, int element) {

    // Use binary search to check for duplicates

    return bin_search_iter(arr, size, element) != -1 ? 1 : 0;

}






















