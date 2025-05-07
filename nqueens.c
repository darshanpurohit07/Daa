#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 20
int x[MAX];



void printsoln(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
        // printf("%d",x[i]);
    }
    printf("-------------------\n");
}

int issafe(int k,int col)
{
    for(int i=1;i<k;i++)
    {
        if(x[i]==col || abs(x[i]-col)==abs(i-k))
        return 0;

    }
    return 1;

}

void nqueens(int k,int n)
{
    for(int col=1;col<=n;col++)
    {
        if(issafe(k,col))
        {
         x[k]=col;

         if(k==n)
         {printsoln(n);}
         else
         {nqueens(k+1,n);}
        }
    

    }
}

int main()
{

    int n=4;
    printf("Enter the no. of queens");
    scanf("%d",&n);
    nqueens(1,n);

    return 0;
}