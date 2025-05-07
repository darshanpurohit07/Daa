#include <stdio.h>

void sortt(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                int temp;
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }

}



void ccgreedy(int coins[], int n,int target)
{

sortt(coins,n);
  for(int i=0;i<n;i++)
  {
    while(target>=coins[i])
    {
        target-=coins[i];
        printf("%d ",coins[i]);
    }
  }
  if (target > 0)
  printf("\nCannot reach exact target with given denominations.\n");

}
int main()
{
 int n;
 printf("Enter The no of coin denominations:");
 scanf("%d",&n);
    int coins[n];

    printf("Enter The Coin denominations:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&coins[i]);
    }

    int target;
    printf("Enter The Target Sum: ");
    scanf("%d",&target);

    // ccgreedy(coins,n,target);

  // print(coins,n);

  ccgreedy(coins,n,target);



    return 0;
}