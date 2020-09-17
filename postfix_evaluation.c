// evaluate postfix  //

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int temp_top=-1;
int n=20;
int maxtop = 20;
int temp[20];

void temp_push(int alpha)
{
	printf("Push in temp : %d\n", alpha);
	if(temp_top==maxtop)
	{
		printf("Stack Overflow !!!!\n");
	}
	else
	{
		temp_top+=1;
		temp[temp_top] = alpha;
	}
}

void temp_pop()
{
	printf("temp_Pop()\n");
	if(temp_top==-1)
	{
		printf("Stack under flow !!!!\n");
	}
	else
	{
		temp_top = temp_top-1;
	}
}

void temp_display()
{
	printf("temp_Elements : ");
	for(int i=0;i<=temp_top;i++)
	{
		printf("%d ", temp[i]);
	}
	printf("\n");
}

void operation(char ch)
{
	int temp_var;
	if(ch=='+')
	{
		temp_var = temp[temp_top-1] + temp[temp_top];
	}
	if(ch=='-')
	{
		temp_var = temp[temp_top-1] - temp[temp_top];
	}
	if(ch=='*')
	{
		temp_var = temp[temp_top-1] * temp[temp_top];
	}
	if(ch=='/')
	{
		temp_var = temp[temp_top-1] / temp[temp_top];
	}
	temp_pop();
	temp_pop();
	temp_push(temp_var);
	printf("operation ended\n");
}

int main()
{
	char pe[20];
	printf("Enter prefix expression : ");
	// this is ubuntu based syntex for gets
	fgets(pe, 20, stdin);
	// change to gets(pe); for windows

	int i=0;
	int j=0;
	char temp_var1[10];
	while(pe[i]!='\0')
	{
		printf("Again\n");
		printf("%c\n", pe[i]);
		if(pe[i]==' ')
		{
			printf("Space found\n");
			printf("temp_var1 = %s\n", temp_var1);
			if(j>0)
			{
				int x = atoi(temp_var1);
				temp_push(x);
				j=0;
			}
			else
			{
				printf("Space found but j < = 0\n");
			}
		}
		else
		{
			printf("Space not found\n");
			if(pe[i]=='+' || pe[i]=='-' || pe[i]=='*' || pe[i]=='/')
			{
				operation(pe[i]);
				j=0;
			}
			else
			{
				temp_var1[j] = pe[i];
				j = j + 1;
				printf("j = %d\n", j);
			}
		}
		
		i++;
		printf("i = %d\n", i);
		temp_display();
	}

	return 0;
}
