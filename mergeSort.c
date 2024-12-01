#include <stdio.h>

#define MAX 50

void mergeSort(int arr[], int size, int low, int up);

int main()
{
    int i, n, arr[MAX];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    /*Get the array inputs from user*/
    for (i = 1; i <= n; i++)
    {
        printf("Enter Value of [%d] element:", i);
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, n, 0, n); /*array, size, lower bound, upper bound*/
    

    /*Array has been sorted using merge sort*/
    printf("SORTED: \n");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }    
    return 0;
}



void mergeSort(int arr[], int size, int low, int up)
{
    if (low < up) 
    {
        int mid = (low + up) / 2; // Mid
        mergeSort(arr, size, low, mid);  // Call recursion for first half of array
        mergeSort(arr, size, mid + 1, up);  // Call recursion for second half of array

        int temp[size];
        int i = low, j = mid + 1, k = low;

        while(i <= mid && j <= up)  // i pointer from low to mid and j pointer from mid + 1 to up
        {
            if (arr[i] <= arr[j]) // check if i is greater or smaller than j
            {
                temp[k++] = arr[i++]; // add i to temporary array in k-th address
            } 
            else 
            {
                temp[k++] = arr[j++]; // add j to temporary array in k-th address
            }
        }

        while(i <= mid)  // add remaining array of first half if remaining
        {
            temp[k++] = arr[i++];
        }
        while(j <= up)  // add remaining array of second half if remaining
        {
            temp[k++] = arr[j++];
        }

        for(int i = low; i <= up; i++) // move all value from temporary arrary to main array
        {
            arr[i] = temp[i];
        }
    }
}
