//  tower of hanoi problem using stack  //

#include<stdio.h>

int a_top=-1, b_top=-1, c_top=-1;
int n=100;
int maxtop = 100;
int a[100], b[100], c[100];

void a_push(int num)
{
	printf("Push ini A : %d\n", num);
	if(a_top==maxtop)
	{
		printf("Stack Overflow in A !!!!\n");
	}
	else
	{
		a_top+=1;
		a[a_top] = num;
	}
}

void b_push(int num)
{
	printf("Push ini B : %d\n", num);
	if(b_top==maxtop)
	{
		printf("Stack Overflow in B !!!!\n");
	}
	else
	{
		b_top+=1;
		b[b_top] = num;
	}
}

void c_push(int num)
{
	printf("Push ini C : %d\n", num);
	if(c_top==maxtop)
	{
		printf("Stack Overflow in C !!!!\n");
	}
	else
	{
		c_top+=1;
		c[c_top] = num;
	}
}

void a_pop()
{
	printf("a_Pop()\n");
	if(a_top==-1)
	{
		printf("Stack a under flow !!!!\n");
	}
	else
	{
		a_top = a_top-1;
	}
}

void b_pop()
{
	printf("b_Pop()\n");
	if(b_top==-1)
	{
		printf("Stack b under flow !!!!\n");
	}
	else
	{
		b_top = b_top-1;
	}
}

void c_pop()
{
	printf("c_Pop()\n");
	if(c_top==-1)
	{
		printf("Stack c under flow !!!!\n");
	}
	else
	{
		c_top = c_top-1;
	}
}

void display()
{
	printf("Elements of A : ");
	for(int i=0;i<=a_top;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("Elements of B : ");
	for(int i=0;i<=b_top;i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	printf("Elements of C : ");
	for(int i=0;i<=c_top;i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n");
	printf("\n");
}

void hanoi(int n, char a1, char b1, char c1)
{
	if(n==1)
	{
		printf("%c => %c\n", a1, c1);

		if(a1=='A' && c1=='B')
		{
			b_push(a[a_top]);
			a_pop();
			display();
		}
		if(a1=='A' && c1=='C')
		{
			c_push(a[a_top]);
			a_pop();
			display();
		}
		if(a1=='B' && c1=='A')
		{
			a_push(b[b_top]);
			b_pop();
			display();
		}
		if(a1=='B' && c1=='C')
		{
			c_push(b[b_top]);
			b_pop();
			display();
		}
		if(a1=='C' && c1=='A')
		{
			a_push(c[c_top]);
			c_pop();
			display();
		}
		if(a1=='C' && c1=='B')
		{
			b_push(c[c_top]);
			c_pop();
			display();
		}

		// c_push(a[a_top]);
		// a_pop();
		// display();
	}
	else
	{
		hanoi(n-1, a1, c1, b1);
		printf("%c => %c\n", a1, c1);
		if(a1=='A' && c1=='B')
		{
			b_push(a[a_top]);
			a_pop();
			display();
		}
		if(a1=='A' && c1=='C')
		{
			c_push(a[a_top]);
			a_pop();
			display();
		}
		if(a1=='B' && c1=='A')
		{
			a_push(b[b_top]);
			b_pop();
			display();
		}
		if(a1=='B' && c1=='C')
		{
			c_push(b[b_top]);
			b_pop();
			display();
		}
		if(a1=='C' && c1=='A')
		{
			a_push(c[c_top]);
			c_pop();
			display();
		}
		if(a1=='C' && c1=='B')
		{
			b_push(c[c_top]);
			c_pop();
			display();
		}
		hanoi(n-1, b1, a1, c1);
	}
}

int main()
{
	char a1='A', b1='B', c1='C';
	int n;
	printf("Enter n : ");
	scanf("%d", &n);

	for(int i=n;i>0;i--)
	{
		a_push(i);
	}
	display();
	hanoi(n, a1, b1, c1);
	display();

	return 0;
}
