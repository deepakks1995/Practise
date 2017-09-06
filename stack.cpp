#include <iostream>
#include <malloc.h>
using namespace std;
struct stack
{
	unsigned length;
	int index;
	int *A;
};
struct stack* create_stack(unsigned n)
{
	struct stack *stack = (struct stack *) calloc (1,sizeof(struct stack));
	stack->length=n;
	stack->index=-1;
	stack->A= (int *) calloc (n,sizeof(int));
	return stack;
}
int is_empty(struct stack *stack)
{
	if(stack->index==-1)
		return 1;
	else
		return 0;
}
int is_full(struct stack *stack)
{
	if(stack->index==stack->length)
		return 1;
	else
		return 0;
}
int push(struct stack *stack,int val)
{
	if(is_full(stack))
		return -1;
	else
	{
		stack->index++;
		stack->A[stack->index]=val;
	}
}
int pop(struct stack *stack)
{
	if(is_empty(stack))
		return -1;
	else
	{
		stack->index--;
		return	stack->A[stack->index];
	}

}
int main()
{
		struct stack *stack;
	stack = create_stack(10);
	for(int i=0;i<10;i++)
		push(stack,i);
	for(int i=0;i<10;i++)
	{
		cout<<pop(stack)<<" ";
	}

}
