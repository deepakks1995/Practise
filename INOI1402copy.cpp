#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
struct edges
{
	long src,dest;
	long weight;
};
struct subset
{
	long parent;
	long rank;
};
long row,F;
int cmp(const void* a, const void* b)
{
    struct edges* a1 = (struct edges*)a;
    struct edges* b1 = (struct edges*)b;
    return a1->weight > b1->weight;
}
long find_element(struct subset subsets[],long i)
{
	if(subsets[i].parent!=i)
		subsets[i].parent=find_element(subsets,subsets[i].parent);
	return subsets[i].parent;
}
void add_element(struct subset subsets[],long x,long y)
{
	long xr=find_element(subsets,x);
	long yr=find_element(subsets,y);

	if (subsets[xr].rank < subsets[yr].rank)
        	subsets[xr].parent = yr;
	else if (subsets[xr].rank > subsets[yr].rank)
        	subsets[yr].parent = xr;
	    else
	    {
	        subsets[yr].parent = xr;
	        subsets[xr].rank++;
	    }
}
void print(struct edges edges)
{
	printf("The edge between node %d and node %d of weight %d \n",edges.src,edges.dest,edges.weight);
}

int main()
{
	cin>>row>>F;
	struct edges *edges=(struct edges * ) calloc (F, sizeof(struct edges));
	long x,y,P,i;
	for(i=0;i<F;i++)
	{
		cin>>x>>y>>P;
		edges[i].src=x;
		edges[i].dest=y;
		edges[i].weight=P;
	}
	qsort(edges,F,sizeof(struct edges),cmp);
	long e=0,v;
	struct subset *subsets=(struct subset *) calloc (row,sizeof(struct subset));
	for(v=0;v<F;v++)
	{
		subsets[v].parent=v;
		subsets[v].rank=0;
	}
	i=0;
	long long sum=0;
	while(e<row-1)
	{
		struct edges next=edges[i++];
		long x= find_element(subsets,next.src);
		long y = find_element(subsets,next.dest);
		if(x!=y)
		{
			sum+=next.weight;
			add_element(subsets,x,y);
			e++;
		}
	}
	cout<<sum<<endl;

	return 0;
}
