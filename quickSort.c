#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void quickSort(int arr[], int low, int up);

int main()
{
    int arr[MAX],n,i;
    printf("Number of element :");
    scanf("%d", &n);

    /*Get the array inputs from user*/
    for (i = 1; i <= n; i++)
    {
        printf("Enter Value of [%d] element:", i+1);
        scanf("%d", &arr[i]);
    }


    quickSort(arr,0,n); //arrray, lower bound, upper, bound.

    /*Array has been sorted using quick sort*/	
    printf("Sorted array: \n");
    for (i = 1; i <= n; i++)
    {
        printf("%d ",arr[i]);
    }
}


void quickSort(int arr[], int low, int up)
{
    if (low < up)
    {
        int pivot = arr[low], i = low + 1, j = up, temp; // create a pivot at starting index of array

        while (i <= j)
        {
            while (i <= up && arr[i] < pivot) i++; // check which value of i-th is less than pivot
            while (j > low && arr[j] >= pivot) j--; // check which value of j-th is more than pivot
            
            if (i < j)  // swaping location
            {
                temp = arr[i]; 
                arr[i++] = arr[j];
                arr[j--] = temp;
            }
        }

        arr[low] = arr[j]; // set lower bound of array to j-th value
        arr[j] = pivot;  // set pivot location to j-th place

        quickSort(arr, low, j - 1); // recursive call from low till pivot
        quickSort(arr, j + 1, up);  // recusive call from pivot + 1 till up 
    }
}
