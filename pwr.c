#include <stdio.h>

int pwr(int base ,int exponent)
{

    if(exponent==0)
    {
        return 1;
    }

    int halfpower=pwr(base,exponent/2);

    if(exponent%2==0)
    {
        return halfpower*halfpower;
    }
    else
    {
        return base*halfpower*halfpower;
    }
}

int main()
{
    int base=5;
    int exponent=4;
     
    int result=pwr(base,exponent);

    printf("%d ^ %d = %d\n",base,exponent,result);

    return 0;

}