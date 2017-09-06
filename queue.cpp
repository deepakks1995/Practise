#include <iostream>
#include <malloc.h>
using namespace std;
struct queue 
{
	unsigned length;
	int index,index2;
	int *A;
};
struct queue* create_queue(unsigned n)
{
	struct queue *queue = (struct queue *) calloc (1,sizeof(struct queue));
	queue->length=n;
	queue->index=-1;
	queue->index2=-1;
	queue->A = (int *) calloc (n,sizeof(int));
	return queue;
}
int is_full(struct queue *queue)
{
	if(queue->index==queue->length)
		return 1;
	else
		return 0;
}
int is_empty(struct queue *queue)
{
	if(queue->index2==queue->length)
		return 1;
	else return 0;
}
int push(struct queue *queue,int val)
{
	if(is_full)
		return -1;
	else
	{
		queue->index++;
		queue->A[queue->index]=val;
	}	
}
int pop(struct queue *queue)
{
	if(is_empty)
		return -1;
	else
	{
		queue->index2++;
		return queue->A[queue->index2];
	}
}
int main()
{
	struct queue *queue;
	queue = create_queue(10);
	for(int i=0;i<10;i++)
		push(queue,i);
	for(int i=0;i<10;i++)
	{
		cout<<pop(queue)<<" ";
	}
}

