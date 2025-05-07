#include <stdio.h>


struct Item
{
    int profit;
    int weight;
    double ratio;

};


void fractionalKnapsack(int w, struct Item items[],int  n)
{
    double x[n];
    int maxprofit=0;
    for(int i=0;i<n;i++)
    {
        items[i].ratio=(double) items[i].profit / items[i].weight;
    }
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(items[j].ratio<items[j+1].ratio)
            {
                struct Item temp=items[j];
                items[j]=items[j+1];
                items[j+1]=temp;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(items[i].weight<=w)
        {
            x[i]=1;
            w-=items[i].weight;
            maxprofit+=items[i].profit;
        }
        else
        {
            x[i]=(double)w/items[i].weight;
            maxprofit+=x[i]*items[i].profit;
            break;
            }

       

        
    }
    printf("%d ",maxprofit);
    for(int i=0;i<n;i++)
    { printf("%f ",x[i]);}
   




}

int main()
{
   int w=50;//capacity of knap sack
   int n=3;

   struct Item items[]=
   {
    {60,10},{100,20},{120,30}
   };

   fractionalKnapsack(w, items, n);
   return 0;

}