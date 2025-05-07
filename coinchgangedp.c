#include <stdio.h>
#include<limits.h>



void dpcc(int coins[],int n,int target)
{
    int dp[target+1];
    dp[0]=0;
    for(int i=1;i<=target;i++)
    {
        dp[i]=INT_MAX;

    }

    for(int i=1;i<=target;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coins[j]<=i && dp[i-coins[j]]!=INT_MAX)
            {
                if(dp[i]>dp[i-coins[j]]+1)
                {
                    dp[i]=dp[i-coins[j]]+1;
                }
            }
        }
    }
    if(dp[target]==INT_MAX)
    {
        printf("Soln Does not exists:");
    }
    else{
        printf("%d",dp[target]);
    }


    


}


int main()
{
    int n=3;
    int target=6;
    int coins[]={1,3,4};

    dpcc(coins,n,target);



    return 0;

}