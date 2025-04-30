/*Q1. Write a C/C++ program to implement below mentioned Searching
and Sorting Techniques.
(a) Bubble Sort
(b) Selection Sort
(c) Insertion Sort */

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n);
void printArray(int arr[], int n);
void selction_sort(int arr[],int n );
void swap(int *a, int *b);

int main() {
    int choice, size;

    printf("Enter the size of the array: ");
    scanf("%d", &size); 

    int arr[size];  
    printf("Enter the elements of the array:\n");
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);  
    } 

    while (1) {
        printf("Enter your Choice:\n1. Bubble sort \n 2 selection_sort \n3. Exit\n");
        scanf("%d", &choice);  

        switch (choice) {
        
            case 1:
                printf("\nOriginal Array:\n");
                printArray(arr, size);
                bubble_sort(arr, size);
                printf("Sorted Array:\n");
                printArray(arr, size);  
                break;

            case 2:
                printf("\n Orignal araray:\n");
                printArray(arr,size);
                 selction_sort(arr,size );
                
             case 3:    
		exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void selction_sort(int arr[], int n ){
	int i , j, min_idx;
	for(i=0;i<n-1;i++){
	if(arr[j]< arr[min_idx])
	min_idx=j;
	}
	if(min_idx!=1);
	for(j=i+1; j<n; j++){
	if(arr[j] < arr[min_idx])
	min_idx=j;
	}
	if(min_idx!=1)
	swap(&arr[min_idx],&arr[i]);
	}
	
	
	















