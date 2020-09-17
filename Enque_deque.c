//  enque and deque //

#include<stdio.h>

int n=6;
int front=-1,rear=-1;
int a[6];

int enqueue(int item)
{
	printf("Enqueue %d\n", item);
	if( (front==0 && rear==n-1) || front==rear+1 )
	{
		printf("Queue Overflow  !!!\n");
		return 0;
	}
	if(front==-1)
	{
		front+=1;
	}
	if(rear==n-1)
	{
		rear = 0;
	}
	else
	{
		rear+=1;
	}

	a[rear] = item;
	return 0;
}

int dequeue()
{
	printf("Dequeue !!!\n");
	if(front==-1)
	{
		printf("Queue underflow  !!!\n");
		return 0;
	}
	if(front==rear)
	{
		front = -1;
		rear = -1;
	}
	if(front==n-1)
	{
		front = 0;
	}
	else
	{
		front+=1;
	}
	return 0;
}

void display()
{	printf("\nElements of Queue : \n");
	for(int i=0;i<n;i++)
	{
		printf("a[%d] = %d ", i, a[i]);
		if(i==front)
			printf(" (front) ");
		if(i==rear)
			printf(" (rear) ");
		printf("\n");
	}
	
}

int main()
{
	display();
	enqueue(1);
	display();
	enqueue(1);
	display();
	enqueue(1);
	display();
	enqueue(1);
	display();
	enqueue(1);
	display();
	enqueue(1);
	display();
	dequeue();
	display();
	dequeue();
	display();
	enqueue(2);
	display();
	enqueue(3);
	display();
	enqueue(4);
	display();
	enqueue(5);
	display();
	dequeue();
	display();
	dequeue();
	display();
	enqueue(5);
	display();
	enqueue(5);
	display();
	enqueue(5);
	display();


	return 0;
}
