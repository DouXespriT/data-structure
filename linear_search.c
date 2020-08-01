#include<stdio.h>
void printa(int [], int);
void linear(int [], int, int);
void main()
{
	int n,num;
	printf("Enter size of aray : ");
	scanf("%d", &n);
	int a[n+1];
	for(int i=0;i<n;i++)
	{
		printf("Enter a[%d] value : ", i);
		scanf("%d", &a[i]);
	}
	printa(a,n);
	printf("\nLinear Search\n");
	printf("Enter value to search : ");
	scanf("%d", &num);
	linear(a,n,num);
}

void printa(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
}
void linear(int a[], int n, int num)
{
	int found=0;
	int found_loc=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==num)
		{
			found=1;
			found_loc=i;
			break;
		}
	}
	if(found==1)
		printf("Found at a[%d]\n", found_loc);
	else
		printf("Item Not Found...\n");
}