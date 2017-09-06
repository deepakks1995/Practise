/*input
8
3 2 3 2 3 5 1 3
*/

#include <iostream>
using namespace std;

long N,i;

long long max1(long long a, long long b, long long c)
{
	if(a>b)
		if(a>c)
			return a;
		else return c;
	else
		if(b>c)
			return b;
		else 
			return c;
}

int main()
{
	cin>>N;
	long F[N];
	long long dp[3][N];

	for(i=0;i<N;i++)
		cin>>F[i];

	dp[0][N-1] = 0;
	dp[1][N-1] = F[N-1];
	dp[2][N-1] = 0;
	
	for(i=N-2;i>=0;i--)
	{
		dp[0][i] = max1(dp[0][i+1],dp[1][i+1],dp[2][i+1]);
		dp[1][i] = F[i] + dp[0][i+1];
		dp[2][i] = F[i] + dp[1][i+1];
	}
	cout<<max1(dp[0][0],dp[1][0],dp[2][0]);
	cout<<endl;
}