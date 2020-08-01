#include<stdio.h>

void printa(int [], int);
void insert(int [], int, int, int);

void main()
{
	int a[10];
	int n;
	printf("Enter size of aray : ");
	scanf("%d", &n);
	int loc,num;
	for(int i=0;i<n;i++)
	{
		printf("Enter a[%d] value : ", i);
		scanf("%d", &a[i]);
	}

	printf("Start\nPrinting array....\n");
	printa(a,n);
	printf("\nInsertion\n");
	printf("Enter location : ");
	scanf("%d", &loc);
	printf("Enter value : ");
	scanf("%d", &num);
	printf("Inserting....\n");
	insert(a,n,loc,num);
	n+=1;
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

void insert(int a[], int n, int loc, int val)
{
	int temp,temp1;
	for(int i=n+1;i>=loc;i--)
	{
		if(i==loc)
		{
			a[i]=val;
		}
		else
		{
			a[i]=a[i-1];
		}
	}
}