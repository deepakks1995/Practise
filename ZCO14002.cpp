/*
input
3 
6 9 
3 5 
4 8
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmpf(pair<long, long>&p1, pair<long, long>&p2)
{
	return p1.second < p2.second;
}
int main()
{
	long N,i;
	cin>>N;
	pair<long, long> p[N];
	for(i=0;i<N;i++)
		cin>>p[i].first>>p[i].second;

	sort(p,p+N,cmpf);
	long j=1,count=0;
	for(i=0;i<N-1;i++)
	{	
		for(;j<N;)
		{
			if(p[i].second < p[j].first)
			{
				count++;
				i = j;
				j++;
			}
			else if(p[i].second == p[j].first)
				j++;
			else if(p[i].second > p[j].first)
			{
				if(p[i].second < p[j].second)
					j++;
				else 
				{
					i = j;
					j++;
				}
			}
		}
	}
	cout<<count+1<<endl;
}