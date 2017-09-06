
#include <iostream>
#define max1_size 1000001
#ifndef	fastread
#define gc getchar_unlocked
#endif
using namespace std;

int t;
int N,arr[max1_size];
long long sum[max1_size],ans,i,j,max1;

int solve();
inline int read();

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	t = read();
	while(t--)
	{
		max1 = ans = 0;
		N = read();
		for(i=0;i<N;++i)
		{
			arr[i] = read();
			if(i!=0)
				sum[i] = arr[i] + sum[i-1];
			else 
				sum[i] = arr[i];
		}
		solve();
		cout<<max1<<endl;
	}
}

inline int read()
{
    int temp=0;
    register int ch = gc();
    while(ch<'0' || ch>'9')     {   ch = gc();    }
    while(ch>='0' && ch<='9')   {   temp = (temp<<3) + (temp<<1) + ch -'0';     ch = gc();    }
    return temp;
}

int solve()
{
	for(i=0;i<N;++i)
		{
			if(i!=0)
				ans	= sum[N-1] - sum[i-1];
			else ans = sum[N-1];
			if(ans%2==0)
			{
				if(max1<N-i)
					max1 = N - i;
			}
			else
			{
				j=N-1;
				while(j>=i && ans>=0)
				{
					ans-=arr[j];
					if(ans%2==0)
					{
						if(max1<j-i)
							max1 = j - i;
						break;
					}
					--j;
				}
			}
		}
		return 0;
}