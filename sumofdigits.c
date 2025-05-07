#include<stdio.h>
#include<math.h>
int sod(int n)
{
    if(n<10)
    {
        return n;
    }

    int x=n;
    int digits=0;
    while(x!=0)
    {
       digits++;
       x=x/10;
    }

    int half=digits/2;
    int power=pow(10,half);

    int lefthalf=n/power;  //number ke aage ka part
    int righthalf=n%power;  //number ke piche ka part

    return sod(lefthalf)+sod(righthalf);

}

int main()
{
    int n=8236;
     printf("Sum of digits of %d is %d ",n,sod(n));

    return 0;

}