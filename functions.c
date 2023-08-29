#include <stdio.h>
#include "header.h"



// Function to merge two sorted subarrays
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    printf("we have build 2 pseudo  arrays \n");
    printf("first array of size %d \n",n1);
    printf("\n");
    printf("second array of size %d",n2);
    printf("\n");
    
    printf("------------------------------------------------\n");
    // Create temporary arrays
    int L[n1], R[n2];
    printf("\n");


    printf("Now we are assigning values to array1 and array2 from index 0 to mid to array 1 and mid to last index to array2  \n");
    for (i = 0; i < n1; i++)
           
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];
        
        printf("\n");
        printf("values have been assigned to arrays \n");
          printf("\n");
         printf("Array1 elements:\n");
    for (int z = 0; z < n1; z++) {
        printf("%d ", L[z]);
    }
   
          printf("\n");
    printf("Array2 elements:\n");
    for (int z = 0; z < n2; z++) {
        printf("%d ", R[z]);
    }
    printf("\n");
          printf("\n");

    // Merge the temporary arrays back into arr[left..right]
    i = 0;   // Initial index of first subarray
    j = 0;   // Initial index of second subarray
    k = left; // Initial index of merged subarray

    
    
    
          printf("Now we are comparing elements of array1 and  array2 using pointer putting it in our array  \n");
          
          
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] and R[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    printf("Merged array: ");
    for (int m = left; m <= right; m++)
        printf("%d ", arr[m]);
    printf("\n");
    
    
    printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% call completed%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n");
}

// Merge Sort function
void mergesort(int arr[], int left, int right) {
    if (left < right) {
        
      
        int middle = left + (right - left) / 2;
  
     
        // Recursively sort the left and right subarrays
        mergesort(arr, left, middle);
     
        mergesort(arr, middle + 1, right);
        
             printf("we have left point on index: %d",left);
        printf("\n");
         printf("we have middle point on index: %d",middle);
        printf("\n");
        printf("we have right point on index: %d",right);
        printf("\n");
        printf("--------------------------------------------------------------\n");

        // Merge the sorted subarrays
        merge(arr, left, middle, right);
        
        
        
    }
}

