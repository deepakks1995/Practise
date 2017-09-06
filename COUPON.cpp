/*input
1
*/
#include <iostream>//<bits/stdc++.h>
#define INF  99999999

long N,M,i,j,min,index,discount;
long cost[10000][10000];
long dis[100000];
long long sum;

int main()
{
	int t;
	std::cin>>t;
	while(t--)
	{
		ans = 0;
		std::cin>>N>>M;
		for(i=0;i<N;i++)
		{
			min=(long)INF;
			for(j=1;j<=M;j++)
			{
				std::cin>>cost[i][j];
				if(min > cost[i][j])
				{
					min = cost[i][j];
					index = j;
				}
			}
			cost[i][0] = index;
		}
		discount = 0;
		for(i=0;i<N;i++)
		{
			for(j=1;j<=M;j++)
				std::cin>>dis[j];
			if(i==0)
			{
				index = cost[i][0];
				sum += cost[i][index];
				discount = dis[index];
			}
			else
			{
				discount = cost[i][index] - discount;
				index = cost[i][0];
				sum += cost[i][index];
			}
		}

	}
}
