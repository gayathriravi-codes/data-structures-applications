#include <stdio.h>
#include <stdlib.h>
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return(b,a%b);
}
int main()
{
    int a,b;
    printf("\nRead the values for a & b: ");
    scanf("%d%d",&a,&b);
    printf("\nThe GCD of %d and %d is %d",a,b,gcd(a,b));
    return 0;
}
