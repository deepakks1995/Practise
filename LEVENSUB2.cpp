
#include <iostream>
#define max1_size 1000001
#ifndef	fastread
#define gc getchar_unlocked
#endif
using namespace std;

int t;
int N,temp,c,max1,last_one;
int i,ans,counter[max1_size];
bool arr[max1_size];

inline int read();
void solve();

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	t = read();
	while(t--)
	{
		last_one = max1 = c = 0;
		N = read();
		for(i=0;i<N;++i)
		{
			ans = read();
			arr[i] = ans%2;
			if(arr[i]==1)		{		++c;		last_one = i;	}
			counter[i] = c;
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

void solve()
{
	for(i=0;i<N;++i)					{
		if(i!=0)							temp = counter[N-1] - counter[i-1];
		else								temp = counter[N-1];
		if(temp%2==0)					{
			if(max1<N-i)					max1 = N - i;		}
		else							{
			if(i<=last_one)				{
				if(max1<last_one)			max1 = last_one - i ;		}
			else
				break;												}	}
}