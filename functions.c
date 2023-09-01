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


void swap(int* a,int* b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void sortt(int arr[],int en)
{
	for(int i=0;i<=en;i++){
		for(int j=i+1;j<=en;j++)
		{
			if(arr[i] > arr[j])
			{
			    swap(&arr[i] ,&arr[j]);
			}
		}
}
}



int binarysearch(int arr[],int st , int en,int x)
{  
	int w=0;

	printf("first we need to sort the array to use binary search: \n");

         sortt(arr,en);

	printf("left pointer is on:  %d \n",st);
	printf("right  pointer is on:  %d \n",en);

         while(st <=en){   
	int mid=(st+en)/2;
         
	printf("middle element is at index: \n",mid);
	printf("Middle element:  %d\n",arr[mid]);

	if(arr[mid]==x)
	{
		w=1;
		printf("element is present at index: %d ",mid);
		break;	
	}
	

       else if(arr[mid] > x){
	      printf("as we could see middle element is greater than  target we would take right pointer to mid - 1, to cut the array which we don't require to search \n ");
             en=mid-1;
	     printf("now right pointer is at %d \n",en);
       }
	else{
		
	      printf("as we could see middle element is smaller  than  target we would take left  pointer to mid +  1, to cut the array which we don't require to search \n ");
	    
	      st=mid+1;

	      printf("now left pointer is at %d \n",st);


	}
	}

 	if(w==0){
	printf("as we could see target element is not present in array : ");
	}


	return -1;
}





// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the pivot as the last element
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two subarrays
        int pi = partition(arr, low, high);

        // Recursively sort the subarrays
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
