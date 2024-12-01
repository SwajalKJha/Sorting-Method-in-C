#include <stdio.h>

#define MAX 100
#define PARENT(i) (i / 2)
#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)

void heapSort(int arr[], int size);

int main()
{
    int i, n, arr[MAX];
    
    printf("Enter no of element:");
    scanf("%d", &n);

    /*Get the array inputs from user*/
    for (i = 1; i <= n; i++)
    {
        printf("Enter Value of [%d] element:", i);
        scanf("%d", &arr[i]);
    }
    
    heapSort(arr,n);
    
    /*Array has been sorted using heap sort*/
    printf("SORTED: \n");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }   

    return 0;
}


void heapSort(int arr[], int size)
{
    // Build the heap
    for (int i = size / 2; i >= 1; i--) // travesal from last node to root node
    {
        for (int j = i; LEFT(j) <= size; ) 
        {
            int largest = j;
            if (LEFT(j) <= size && arr[LEFT(j)] > arr[largest]) 
            {
            	largest = LEFT(j);
            }
            if (RIGHT(j) <= size && arr[RIGHT(j)] > arr[largest]) 
            {
            	largest = RIGHT(j);
            }
            if (largest == j) 
            {
            	break;
            }
            
            // Swap
            int temp = arr[j]; 
            arr[j] = arr[largest]; 
            arr[largest] = temp;
            j = largest;  // Move down the tree
        }
    }

    // Sort the array
    for (int i = size; i > 1; i--)
    {
        // Swap the root with the last element
        int max = arr[1]; arr[1] = arr[i]; arr[i] = max;
        // Restore the heap property
        for (int j = 1; LEFT(j) <= i - 1; )
        {
            int largest = j;
            if (LEFT(j) <= i - 1 && arr[LEFT(j)] > arr[largest])
            {
            	 largest = LEFT(j);
            }
            if (RIGHT(j) <= i - 1 && arr[RIGHT(j)] > arr[largest])
            {
             	largest = RIGHT(j);
            }
            if (largest == j) 
            {
            	break;
            }
            	
            // Swap
            int temp = arr[j];
            arr[j] = arr[largest];
            arr[largest] = temp;
            j = largest;  // Move down the tree
        }
   }
}
