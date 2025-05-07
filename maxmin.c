#include<stdio.h>

struct Pair
{
    int min;
    int max;

};

struct Pair findminmax(int arr[],int low,int high)
{
    struct Pair result;
    struct Pair left;
    struct Pair right;

    //for only one element
    if(low==high)
    {
        result.min=result.max=arr[low];//arr[high]
        return result;
    }

    //if there are two elements
    if(high==low+1)
    {
        if(arr[low]<arr[high])
        {
            result.min=arr[low];
            result.max=arr[high];
        }
        else
        {
            result.max=arr[low];
            result.min=arr[high];
        }
        return result;

    }

    //if more than 2 elements
    int mid=(low+high)/2;

    left=findminmax(arr,low,mid);           //iss se left part ka max aur min milega
    right=findminmax(arr,mid+1,high);       //iss se right part ka max aur min milega

    //compare min from both left and right part and minimum of them as result ka min
    result.min=(left.min<right.min)?left.min:right.min;

   //compare max from both left and right part and minimum of them as result ka max
   result.max=(left.max<right.max)?right.max:left.max;

   return result;



}
int main()
{
    
    int arr[]={100, 11, 445, 1111, 330, 3};
    int n=sizeof(arr)/sizeof(arr[0]);

    struct Pair result=findminmax(arr,0,n-1);

    printf("MAX: %d\n",result.max);
    printf("MIN: %d\n",result.min);
 
    return 0;
}