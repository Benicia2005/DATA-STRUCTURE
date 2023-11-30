#include <stdio.h>
int main()
{
    int fib1=0,fib2=1,fib3,n,c;
    printf("Enter the number to stop: ");
    scanf("%d",&n);
    printf("First %d fibonacci series are: ",n);
    printf("\n%d",fib1);
    if(n>=2)
    printf("\n%d",fib2);
    c=2;
    while(c<n)
    {
        fib3=fib1+fib2;
        c++;
        printf("\n%d",fib3);
        fib1=fib2;
        fib2=fib3;
    }
    return 0;
}
