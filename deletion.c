#include<stdio.h>

void printa(int [], int);
void delete(int [], int, int);

void main()
{
	int a[10];
	int n;
	printf("Enter size of aray : ");
	scanf("%d", &n);
	int loc;
	for(int i=0;i<n;i++)
	{
		printf("Enter a[%d] value : ", i);
		scanf("%d", &a[i]);
	}

	printf("Start\nPrinting array....\n");
	printa(a,n);
	printf("\nDeletion\n");
	printf("Enter location : ");
	scanf("%d", &loc);
	printf("Deleting....\n");
	delete(a,n,loc);
	n-=1;
	printf("Updating array...\n");
	printa(a,n);
}

void printa(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
}

void delete(int a[], int n, int loc)
{
	for(int i=loc;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
}