#include <stdio.h>


void greedyKnapscak(int n, int p[],int w[],int m,int x[])
{
    float cc_of_ks=m;
    float cp=0.0;
    int i;

    for(i=0;i<n;i++)
    {
        if(w[i]>cc_of_ks)
        {break;}
        x[i]=1;
        cc_of_ks-=w[i];
        cp+=p[i];
    }
    if(i<n)
    {
        x[i]==cc_of_ks/w[i];
        cp+=p[i]*x[i];
    }
    printf("Max Profit :%f\n",cp);

    printf("Portions taken:\n");
    for(int i=0;i<n;i++)
    {
        printf()
    }

}


int main()
{

    int n, i;
    int m;

    printf("Enter number of items and knapsack capacity: ");
    scanf("%d %d", &n, &m);

    float p[n], w[n], x[n];

    printf("Enter profit and weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &p[i], &w[i]);
    }

    greedyKnapsack(n, p, w, m, x);

    return 0;

}