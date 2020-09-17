/*      reversing without temporary veriables  */

#include<stdio.h>
int n=4;
int a[5];
void printa(int [], int);
void reverse(int [], int);
int main()
{
	for (int i=0; i<n; i++)
	{
		printf("Enter a[%d] : ", i);
		scanf("%d", &a[i]);
	}
	printa(a,n);
	printf("\nReversing array........\n");
	reverse(a,n);
	printf("Reversed array\n");
	printa(a,n);

	return 0;
}
void printa(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
}
void reverse(int a[], int n)
{
	int i,j;
	for(i=0,j=n; i<=j; i++,j--)
	{
		a[j]=a[i];
		a[i]=a[j-1];
	}
	for(int k=0;k<n;k++)
	{
		if(k>=i-1)
		{
			a[k]=a[k+1];
		}
	}
}
