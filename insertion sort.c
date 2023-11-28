#include<stdio.h>
void InsertionSort(int arr[],int n){
	int i,key,j;
	for(i=0;i<n;i++)
	{ 
		key=arr[i];
		j=i-1;
		while(j<=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
int main()
{
	int i,n;
	printf("enter size: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	InsertionSort(a,n);
	printf("Sorted array..");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
}
