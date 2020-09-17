// convert infix to post fix  //

#include <stdio.h>

int temp_top=-1, pe_top=-1;
int n=20;
int maxtop = 20;
char temp[20],pe[20];

int precedence(char operator)
{
	if(operator=='+' || operator=='-')
		return 1;
	if(operator=='*' || operator=='/')
		return 2;
	if(operator=='^')
		return 3;
	else
		return 0;
}

int temp_push(char alpha)
{
	printf("Push in temp : %c\n", alpha);
	if(temp_top==maxtop)
	{
		printf("Stack Overflow !!!!\n");
		return 0;
	}
	else
	{
		temp_top+=1;
		temp[temp_top] = alpha;
	}
}

int pe_push(char alpha)
{
	printf("Push in pe : %c\n", alpha);
	if(pe_top==maxtop)
	{
		printf("Stack Overflow !!!!\n");
		return 0;
	}
	else
	{
		pe_top+=1;
		pe[pe_top] = alpha;
	}
}

int temp_pop()
{
	printf("temp_Pop()\n");
	if(temp_top==-1)
	{
		printf("Stack under flow !!!!\n");
		return 0;
	}
	else
	{
		temp_top = temp_top-1;
	}
}

int pe_pop()
{
	printf("pe_Pop()\n");
	if(pe_top==-1)
	{
		printf("Stack under flow !!!!\n");
		return 0;
	}
	else
	{
		pe_top = pe_top-1;
	}
}

int temp_display()
{
	printf("temp_Elements : ");
	for(int i=0;i<=temp_top;i++)
	{
		printf("%c ", temp[i]);
	}
	printf("\n");
	return 0;
}

int pe_display()
{
	printf("pe_Elements : ");
	for(int i=0;i<=pe_top;i++)
	{
		printf("%c ", pe[i]);
	}
	printf("\n");
	return 0;
}

int main()
{
	char ie[20];
	printf("Enter infix expression : ");
	scanf("%s", ie);

	temp_push('(');

	int i=0;
	while(ie[i]!='\0')
	{
		if(ie[i]=='(')
			temp_push(ie[i]);
		if((ie[i]>='a' && ie[i]<='z') || (ie[i]>='A' && ie[i]<='Z'))
			{
				pe_push(ie[i]);
			}
		if(ie[i]=='+' || ie[i]=='-' || ie[i]=='*' || ie[i]=='/' ||ie[i]=='^')
		{
			if(precedence(ie[i]) > precedence(temp[temp_top]))
			{
				temp_push(ie[i]);
			}
			else
			{
				if(precedence(ie[i])<=precedence(temp[temp_top]))
				{
					while(temp[temp_top]!='(')
					{
						if(temp_top>0)
						{	
							pe_push(temp[temp_top]);
							temp_pop();
						}
						else
						{
							break;
						}
						temp_display();
						pe_display();
					}
					if(temp_top>0)
						temp_pop();
					temp_push(ie[i]);
				}
			}
		}
		if(ie[i]==')')
		{
			while(temp[temp_top]!='(')
			{
				if(temp_top==-1)
					break;
				pe_push(temp[temp_top]);
				temp_pop();
			}
			if(temp_top>=0)
				temp_pop();
		}


		i++;
		temp_display();
		pe_display();
	}


	return 0;
}
