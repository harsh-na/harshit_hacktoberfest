#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *top;

void create()
{
	top=NULL;
}
void push(int x)
{
	struct node*newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=x,
	newNode->next=top;
	top=newNode;
	printf("the item pushed into stack is : %d \n ",x);
}
void pop()
{
	struct node* temp;
	temp=top;
	if(top==NULL)
	printf("Stack underflow");
	else
	{
	
	printf("the item popped from stack is : %d \n",top->data);
	top=top->next;
	free(temp);
}
}

void display()
{
	struct node* temp;
	temp=top;
	if(top==NULL)
	printf("Stack is Empty");
	else
	{
		printf("the elements in stack are :\n");
		while(temp!=NULL)
		{
			printf(" %d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
int main()
{
	create();
	push(1);
	push(2);
	push(5);
	display();
	pop();
	display();
}