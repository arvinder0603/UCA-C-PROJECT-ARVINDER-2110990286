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
	int t=*a;
	*a=*b;
	*b=t;

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





// function to find the partition position
int partition(int array[], int low, int high) {
    
	printf("Lets take pivot as last element of array: %d \n",array[high]);

  // select the rightmost element as pivot
  int pivot = array[high];
       
      printf("\n");

      printf("take a  pointer at index  i: %d \n",low -1);
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  
   printf("\n");
   printf("traverse from left if any element greater than pivot \n ");
   printf("increment left pointer and swap values of indx i and j \n");
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      
	    printf("\n");
	    printf("as array[j] is smaller than pivot: %d  %d  \n",array[j],pivot);
	    printf("\n");
	    printf("we will swap values of both, \n");
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }
  	printf("\n");
	printf("swap pivot element with greater elememt ar index i \n");
  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
       

   printf("\n");
   printf("return partition index: %d \n",i+1);
  // return the partition point
  return (i + 1);
}

void quicksort(int array[], int low, int high) {
  if (low  < high) {
	
	  printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% New Call %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");		
	printf("\n");  
     printf("we have a left pointer on index: \n %d",low);
     printf("\n");
     printf("we have right pointer on index: \n%d",high);
     printf("\n");
	printf("elements in array between left to right\n");
     printf("\n");
	for(int i=low;i<high;i++){
	 printf("%d ",array[i]);
	}

	printf("\n");
     printf("now we need a pivot lets call partition function: \n");
       printf("\n");
     printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% We are now in partion function to get partiton of array:  \n");
     printf("\n");
    int pi = partition(array, low, high);
       
    printf("\n");

    printf("recursively call for left to partition and partition to right ");
    printf("\n");
    // recursive call on the left of pivot
    quicksort(array, low, pi - 1);

    // recursive call on the right of pivot
    quicksort(array, pi + 1, high);
  }
}


void bubblesort(int arr[], int n) {
    int swapped; // A flag to check if any swaps were made in a pass

    // We start by assuming that swaps will be needed
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;

        // In each pass, we compare adjacent elements and swap them if they are in the wrong order
        for (int j = 0; j < n - i - 1; j++) {
            printf("Comparing elements at indices %d and %d\n", j, j + 1);
            printf("Elements to compare: %d and %d\n", arr[j], arr[j + 1]);

            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                printf("Swapping elements %d and %d\n", arr[j], arr[j + 1]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set the flag to indicate that a swap occurred
            }
        }

        // If no swaps were made in this pass, the array is already sorted
        if (!swapped) {
            printf("No swaps were made in this pass; the array is already sorted.\n");
            break;
        }
    }
}

