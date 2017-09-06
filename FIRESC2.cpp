/*
*	User_Id	@deepakks1995
*	Problem_Code @FIRESC
*	Solution_Type_2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MOD	1000000007
#define max_size 100005
using namespace std;

int N,M,i,x,y,j;
std::vector<std::vector<int> > v;
int visited[max_size],t;
long long set,ans,count1;


inline int read();
void DFS(int );
void copy(int , int );
void solve();

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);

	v.reserve(max_size);
	t = read();
	while(t--)
	{
		ans = 1;
		set = count1 = 0;
		N = read();
		M = read();
		v.resize(N+3);
		for(i=0;i<=N;++i)		visited[i] = 0;
		for(i=1;i<=N;++i)	{	v[i].push_back(0);	v[i].push_back(2);	}
		for(i=0;i<M;++i)	{	x = read();		y = read();		v[x].push_back(y);		v[y].push_back(x);	}
		for(i=1;i<=N;++i)		v[i][0] = v[i].size();
		DFS(1);
		solve();
		cout<<set<<" "<<ans;
		cout<<endl;
		for(i=0;i<=N;i++)	{	v[i].clear();	v[i].shrink_to_fit();	} 
	}
}

inline int read()			// Function to read input faster
{
    int temp=0;
    register int ch = getchar_unlocked();
    while(ch<'0' || ch>'9')     {   ch = getchar_unlocked();    }
    while(ch>='0' && ch<='9')   {   temp = (temp<<3) + (temp<<1) + ch -'0';     ch = getchar_unlocked();    }
    return temp;
}

void DFS(int src)
{
	int index;
	i = src;
	while(i<=N)
	{
		if(!visited[i])
		{
			visited[i] = 1;
			while(v[i][1]<v[i][0])
			{
				index = v[i][1];
				if(!visited[v[i][index]])
				{
					visited[v[i][index]] = 1;
					copy(i,v[i][index]);
				}
				++v[i][1];
			}
		}
		++i;
	}
}

void copy(int to, int from)
{
	for(int k = 2; k<v[from].size(); ++k)		v[to].push_back(v[from][k]);
	v[from].clear();
	v[from].resize(0);
	v[to][0] = v[to].size();
}

void solve()
{
	for(i=1;i<=N;i++)
		{
			if(v[i].size()>2)
			{
				count1 = 0;
				set++;
				sort(v[i].begin()+2,v[i].end());
				for(j=2;j<v[i].size();++j)
				{
					if(j!=2)
					{
						if(v[i][j]!=v[i][j-1])
							count1++;
					}
					else
						count1++;
				}
				v[i].push_back(count1);
				ans = (ans%MOD * count1%MOD)%MOD;
			}
			else if(v[i].size()==2)
				set++;
			else continue;
		}
}