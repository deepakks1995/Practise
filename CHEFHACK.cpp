/*
*	User_ID	@deepakks1995
*	Problem_Code @CHEFHACk
*/
#include <iostream>
#include <stack>
#define max_size 10000007
#ifndef	fastread
#define gc getchar_unlocked
#endif
using namespace std;

short int t,N;
int pass[355][355],i,j,x,y;
bool prime[max_size];
int prime_before[max_size];
long long unsucc_count;

inline int read();
void sieve();
void solve();
void GridHackingMechanism(const int& , const int& , const short int& );
void print();

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	t = read();
	sieve();
	while(t--)
	{
		unsucc_count = 0;
		N = read();
		for(i=0;i<N;++i)
			for(j=0;j<N;++j)
				pass[i][j] = read();
		solve();
		cout<<unsucc_count<<endl;
	}
}

void print()
{
	for(i=0;i<N;++i)	{		cout<<endl;
		for(j=0;j<N;++j)		cout<<pass[i][j]<<" ";	}
}

inline int read()
{
    int temp=0;
    register int ch = gc();
    while(ch<'0' || ch>'9')     {   ch = gc();    }
    while(ch>='0' && ch<='9')   {   temp = (temp<<3) + (temp<<1) + ch -'0';     ch = gc();    }
    return temp;
}


void GridHackingMechanism(const int& i, const int& j, const short int& l)
{
	stack<pair<int,int> > st;
	pair<int, int> p;
	st.push(make_pair(i,j));
	while(!st.empty())
	{
		p = st.top();
		st.pop();
		x = p.first;
		y = p.second;
		if(x>0 && pass[x-1][y]%2==l && prime[pass[x-1][y]])		{	pass[x-1][y] = -1;	st.push(make_pair(x-1,y));	}
		if(y>0 && pass[x][y-1]%2==l && prime[pass[x][y-1]])		{	pass[x][y-1] = -1;	st.push(make_pair(x,y-1));	}
		if(y<N-1 && pass[x][y+1]%2==l && prime[pass[x][y+1]])	{	pass[x][y+1] = -1;	st.push(make_pair(x,y+1));	}
		if(x<N-1 && pass[x+1][y]%2==l && prime[pass[x+1][y]])	{	pass[x+1][y] = -1;	st.push(make_pair(x+1,y));	}
	}
}

void solve()
{
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
		{
			if(pass[i][j]==-1)					continue;
			else if(prime[pass[i][j]]==0)		unsucc_count += prime_before[pass[i][j]] - 1;
			else if(pass[i][j]%2==0)		{	unsucc_count += pass[i][j]/2;	GridHackingMechanism(i,j,0);	}
			else 							{	unsucc_count += (pass[i][j]+1)/2 + 1;	GridHackingMechanism(i,j,1);	}
		}
}

void sieve()
{
	for(i=0;i<max_size;++i)
		prime[i] = 0;
	prime[0]=1;
	prime[1]=1;
	for(i=2;i*i<=max_size-1;++i)
	{
		if(!prime[i])			{	j = i*i;	
			while(j<max_size)	{	prime[j]=1;		j+=i;	}	}
	}
	int prime_count = 0;
	for(i=0;i<max_size;++i)
	{
		if(!prime[i])		++prime_count;
		prime_before[i] = prime_count;
	}
}