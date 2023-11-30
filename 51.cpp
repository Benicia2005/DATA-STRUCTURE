#include <stdio.h>
int fibonacci(int num)
{
    int first = 0, second = 1; 
    int result; 
    if (num == 0)
    {
        return first; 
    }
    else if (num == 1)
    {
        return second; 
    }
    for (int i = 1; i < num; i++)
    {
        result = first + second; 
        first = second; 
        second = result; 
    }
    return second;
}

int main()
{
    int num; 
    printf("Enter the number of elements to be in the series : ");
    scanf("%d", &num); 

    for (int i = 0; i < num; i++)
    {
        printf("%d, ", fibonacci(i)); 
    }

    return 0;
}
