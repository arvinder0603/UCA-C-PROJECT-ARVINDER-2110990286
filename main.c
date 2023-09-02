#include<stdio.h>
#include "header.h"

int main(){
          
	 printf("-----------------------------------------------Hello Sir, What do you want to learn?---------------------------------------------------------------\n");
	 printf("Here's the  List of topics we could do: \n");
       	 printf("1. Press 1 for merge sort. \n");

       	 printf("2. Press 2 for quick  sort. \n");
	
       	 printf("3. Press 3 for Binary search. \n");
	
       	 printf("4. Press 4  for bubble sort. \n");

      

           
        int choice;
        
	scanf("%d ",&choice);

	int n;
	printf("\nEnter size of array: \n");
        scanf("%d",&n);      

	int arr[n];

	printf("enter elements of array: \n");

	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

       
	switch(choice){
 		
	 case 1:
		 mergesort(arr,0,n-1);
		
		 break;
         case 2:
		 
		 quicksort(arr,0,n-1);
		printf("\n");
		printf("array after sorting: \n");
		printf("\n");
		for(int i=0;i<n;i++)
		{
			printf("%d  ",arr[i]);
		}
 		
		 
		 break;
	case 3:
	       int x;
	       printf("enter element to be searched \n");
	       scanf("%d",&x);
		binarysearch(arr,0,n-1,x);
         	break;

	case 4:
		bubblesort(arr,n);

		printf("\n");
		printf("array after sort:  \n");
		printf("\n");
		for(int i=0;i<n;i++)
		{
			printf("%d  ",arr[i]);
		}

	default:
		printf("enter valid number");
          }
      	
     
       
} 
