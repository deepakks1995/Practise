/*input
5
5 3 4 10
5 9 8 6
7 3 4 6
1 5 4 9
2 9 6 7
6 4 8
2 1 3 10
5 9 6
10 11
5 3 3 10
4 1 1 
1 1 1 
1 1 1 
1 1 1
1 0
4 2 3 10
7 7 7
4 6 10
7 10 9
9 9
5 4 3 10
0 0 0 
0 0 0
0 0 0 
0 0 0
0 0
1 1
*/
/*

1   30
2   40
3    21
4    28
5	20
*/
#include <iostream>
using namespace std;
#include <algorithm>
long long num[100000000];
bool cmpf(long long  a, long long b)
{
	return a > b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	long long t;
	cin>>t;
	long long N,K,E,M,total,n;
	while(t--)
	{
		total=n=0;
		for(long long i=0;i<100000000;i++)
			num[i]=0;
		cin>>N>>K>>E>>M;
		for(long long i=0;i<N-1;i++)
		{
			for(long long j=0;j<E;j++)
			{
				cin>>n;
				num[i]+=n;
			}
		}
		/*for(long long j=0;j<N-1;j++)
		{
			cout<<num[j]<<" ";
		}*/
		sort(num,num+N+1,cmpf);
		/*cout<<endl;
		for(long long j=0;j<N-1;j++)
		{
			cout<<num[j]<<" ";
		}
		cout<<endl;*/
		for(long long j=0;j<E-1;j++)
		{
			cin>>n;
			total+=n;
		}
		//cout<<"total "<<total<<endl;
		if(total>num[K-1])
			cout<<"0";
		else {
			if(num[K-1]-total>=M)
				cout<<"Impossible";
			else 
				cout<<num[K-1]-total+1;
		}
		cout<<endl;
	}
}