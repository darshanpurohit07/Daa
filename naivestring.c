#include<stdio.h>
#include<string.h>
void naive(char text[],char pattern[])
{
    int n=strlen(text);
    int m=strlen(pattern);

    for (int  i = 0; i <= n-m; i++)
    { int j;
        for ( j = 0; j < m; j++)
        {
          if(text[i+j]!=pattern[j] )
          {break;} 
        }

        if (j==m)
        {
            printf("Pattern Found at index %d",i);
        }
        
        
    }
    
}


int main()
{
    char text[]="ABABDABACDABABCABAB";
    char pattern[]="AB";

    naive(text,pattern);
    return 0;
}