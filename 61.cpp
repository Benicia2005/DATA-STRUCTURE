#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n],i;
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            printf("\n%d is an even.",a[i]);
        }
        else
        {
            printf("\n%d is an odd.",a[i]);
        }
    }
}
