/*input
6
5 5 5 5 9 10
6
3 1 8 2 6 4
*/
#include <iostream>
using namespace std;

long N,i;
long long sum,sum2;

int minimum(long a, long b)
{
	if(a>b)
		return -1;
	else if(b>a)
		return 1;
	else return 0;
}

int main()
{
	sum2 = sum = 0;
	cin>>N;
	long cost[N];
	bool arr[N];
	int l;

	for(i=0;i<N;i++) { cin>>cost[i]; arr[i] = 0; }

	for(i=0;i<N-1;)
	{
		l = minimum(cost[i] , cost[i+1]);
		if(l==-1)
		{
			arr[i+1] = 1;
			sum += cost[i+1];
			i+=2;
		}
		else if(l==1)
		{
			arr[i] = 1;
			sum += cost[i];
			i++;
		}
		else
		{
			if(i==0 || arr[i-1]==1)
			{
				arr[i+1] = 1;
				sum += cost[i+1];
				i+=2;
			}
			else
			{
				arr[i] = 1;
				sum += cost[i];
				i++;
			}
		}
	}
	
	if(arr[N-1]==0 && arr[0]==0)
		sum += ( cost[N-1] >= cost[0] ? cost[0] : cost[N-1] ) ;
	for(i=0;i<N;i++)
		arr[i] = 0;


	for(i=0;i<N-1;)
	{
		l = minimum(cost[i] , cost[i+1]);
		if(l==-1)
		{
			arr[i+1] = 1;
			sum2 += cost[i+1];
			i+=2;
		}
		else if(l==1)
		{
			arr[i] = 1;
			sum2 += cost[i];
			i++;
		}
		else
		{
			if(i>0 && arr[i-1]==1)
			{
				arr[i+1] = 1;
				sum2 += cost[i+1];
				i+=2;
			}
			else
			{
				arr[i] = 1;
				sum2 += cost[i];
				i++;
			}
		}
	}

	if(arr[N-1]==0 && arr[0]==0)
		sum2 += ( cost[N-1] >= cost[0] ? cost[0] : cost[N-1] ) ;
	
	cout<<( sum > sum2 ? sum : sum2 )<<endl;;
}