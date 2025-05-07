#include <stdio.h>

void merge(int arr[],int low,int mid ,int high)
{

    int n1=mid-low+1;
    int n2=high-mid;

    int lowarr[n1];
    int higharr[n2];

    for (int i=0;i<n1;i++)
    {
        lowarr[i]=arr[low+i];
    }
    for (int  j = 0; j < n2; j++)
    {
        higharr[j]=arr[mid+1+j];
    }

    int i=0;int j=0;
    int k=low;

    while(i<n1&&j<n2)
    {
        if(lowarr[i]<=higharr[j])
        {
        
               arr[k]=lowarr[i];
               i++;

        }
        else
        {
            arr[k]=higharr[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k]=lowarr[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k]=higharr[j];
        j++;
        k++;
    }
    
    
}


void mergesort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;

        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{

    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, arr_size);

    
    mergesort(arr, 0, arr_size - 1);

    printf("Sorted array: \n");
    printArray(arr, arr_size);


    return 0;

}