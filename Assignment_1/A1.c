/*Q1. Write a C/C++ program that declares an array of length N
containing integers between 1 and N. Implement menu driven
program using switch case for below mentioned functionalities.
(a) insert element at index
(b) delete element at index
(c) find min val
(d) find max val
(e) display array element
(f) reverse display array element
(g) search element in array
(h) array element count
(i) avg of all array element
(j) determine if array contains any duplicates.
(k) reverse array element  */

#include <stdio.h>
#include <stdlib.h>


void menu();
void insert_element(int* arr, int size);
void delete_element(int* arr, int size);
void find_min(int* arr, int size);
void find_max(int* arr, int size);
void display_array(int* arr, int size);
void reverse_display_array(int* arr, int size);
void search_element(int* arr, int size);
void count_elements(int* arr, int size);
void average_elements(int* arr, int size);
void check_duplicates(int* arr, int size);
void reverse_array(int* arr, int size);

int main() {
    int N;
    printf("Enter the size of the array (N): ");
    scanf("%d", &N);
    
    int *arr = (int*)malloc(sizeof(int) * N);
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit if memory allocation fails
    }

    for (int i = 0; i < N; i++) {
        arr[i] = 0; 
    }

    int choice;
    do {
        menu();
        scanf("%d", &choice);
     switch (choice) {
      case 1: insert_element(arr, N); break;
     case 2: delete_element(arr, N); break;
      case 3: find_min(arr, N); break;
      case 4: find_max(arr, N); break;
      case 5: display_array(arr, N); break;
      case 6: reverse_display_array(arr, N); break;
      case 7: search_element(arr, N); break;
       case 8: count_elements(arr, N); break;
       case 9: average_elements(arr, N); break;
        case 10: check_duplicates(arr, N); break;
         case 11: reverse_array(arr, N); break;
        case 12: free(arr); exit(0);
       default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 12);

    free(arr);
    return 0;
}
void menu() {
    printf("\nMenu:\n");
    printf("1. Insert element at index\n");
    printf("2. Delete element at index\n");
    printf("3. Find minimum value\n");
    printf("4. Find maximum value\n");
    printf("5. Display array elements\n");
    printf("6. Reverse display array elements\n");
    printf("7. Search for an element\n");
    printf("8. Count valid elements\n");
    printf("9. Average of all elements\n");
    printf("10. Check for duplicates\n");
    printf("11. Reverse the array\n");
    printf("12. Exit\n");
    printf("Enter your choice: ");
}

void insert_element(int* arr, int size) {
    int index, value;
    printf("Enter index to insert (0 to %d): ", size - 1);
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &value);
    arr[index] = value; 
    printf("Inserted %d at index %d.\n", value, index);
}

void delete_element(int* arr, int size) {
    int index;
    printf("Enter index to delete (0 to %d): ", size - 1);
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
        return;
    }
    arr[index] = 0; 
    printf("Deleted element at index %d.\n", index);
}

void find_min(int* arr, int size) {
    int min = INT_MAX; 
    int found = 0; 
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) { 
            if (arr[i] < min) {
                min = arr[i];
                found = 1;
            }
        }
    }
    if (found) {
        printf("Minimum value: %d\n", min);
    } else {
        printf("No valid elements in the array.\n");
    }
}

void find_max(int* arr, int size) {
    int max = INT_MIN; 
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) { 
            if (arr[i] > max) {
                max = arr[i];
                found = 1;
            }
        }
    }
    if (found) {
        printf("Maximum value: %d\n", max);
    } else {
        printf("No valid elements in the array.\n");
    }
}

void display_array(int* arr, int size) {
    printf("Array elements: ");
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) { 
            printf("%d ", arr[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No valid elements to display.");
    }
    printf("\n");
}

void reverse_display_array(int* arr, int size) {
    printf("Array elements in reverse order: ");
    int found = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] != 0) { 
            printf("%d ", arr[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No valid elements to display.");
    }
    printf("\n");
}

void search_element(int* arr, int size) {
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Element %d found at index %d.\n", value, i);
            return;
        }
    }
    printf("Element %d not found in the array.\n", value);
}

void count_elements(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) { 
            count++;
        }
    }
    printf("Count of valid elements: %d\n", count);
}

void average_elements(int* arr, int size) {
    int sum = 0, count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) { 
            sum += arr[i];
            count++;
        }
    }
    if (count > 0) {
        printf("Average of valid elements: %.2f\n", (float)sum / count);
    } else {
        printf("No valid elements to calculate average.\n");
    }
}

void check_duplicates(int* arr, int size) {
    int found_duplicate = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) { 
            for (int j = i + 1; j < size; j++) {
                if (arr[j] == arr[i]) {
                    printf("Duplicate found: %d at indices %d and %d\n", arr[i], i, j);
                    found_duplicate = 1;
                }
            }
        }
    }
    if (!found_duplicate) {
        printf("No duplicates found in the array.\n");
    }
}

void reverse_array(int* arr, int size) {

    for (int i = 0; i < size / 2; i++) {

        int temp = arr[i];

        arr[i] = arr[size - 1 - i];
                arr[size - 1 - i] = temp;
    }
    printf("Array reversed successfully.\n");
}


        
