/*    push and pop operation of stack  */

#include<stdio.h>

int top=-1;
int n=5;
int maxtop = 5;
int a[5];

int push(int num)
{
	printf("Push : %d\n", num);
	if(top==maxtop)
	{
		printf("Stack Overflow !!!!\n");
		return 0;
	}
	else
	{
		top+=1;
		a[top] = num;
	}
}

int pop()
{
	printf("Pop()\n");
	if(top==-1)
	{
		printf("Stack under flow !!!!\n");
		return 0;
	}
	else
	{
		top = top-1;
	}
}

int display()
{
	printf("Elements : ");
	for(int i=top;i>=0;i--)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

int main()
{
	display();
	push(1);
	display();
	push(2);
	display();
	push(3);
	display();
	push(4);
	display();
	push(5);
	display();
	push(6);
	display();
	push(7);
	display();
	push(8);
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();
	return 0;
}
