#include<stdio.h>
void printa(int [], int);
void binary(int [], int, int);
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
	printf("\nBinary Search\n");
	printf("Enter value to search : ");
	scanf("%d", &num);
	binary(a,n,num);
}

void printa(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
}
void binary(int a[], int n, int num)
{
	int lb=0;
	int ub=n-1;
	int pos;
	int mid;

	mid=(lb+ub)/2;
	while(lb!=ub)
	{
		if(lb>ub)
			break;
		if(a[mid]==num)
			break;
		else
		{
			if(num<a[mid])
			{
				ub=mid-1;
			}
			else
			{
				lb=mid+1;
			}	
		}
		mid=(lb+ub)/2;
	}
	if(a[mid]==num)
		printf("Found at a[%d]\n", mid);
	else
		printf("Item not found !\n");
}