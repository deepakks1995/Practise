/*
*	User_Id	@deepakks1995
*	Problem_Code @FIRESC
*	Solution_Type_1
*/

#include <iostream>
#include <vector>
#define MOD 1000000007
#define max_size 100005
using namespace std;

int N,M,i,x,y,t;
std::vector<std::vector<int> > v(max_size);
int visited[max_size];
int count,set;
long long ans;
bool flag;

void DFS();
void DFS_VISIT(int );
inline int read();

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	t = read();
	v.reserve(max_size);
	while(t--)
	{
		N = read();
		M = read();
		v.resize(N+3);
		ans  = 1;
		set = count = 0;
		for(i=0;i<=N;++i)		visited[i] = 0;
		for(i=0;i<M;++i)	{	x = read();		y = read();		v[x].push_back(y);		v[y].push_back(x);		}
		for(i=1;i<=N;++i)	v[i].push_back(v[i].size()-1);
		flag = 0;
		DFS();
		cout<<set<<" "<<ans<<endl;
		for(i=0;i<=N;i++)	{	v[i].clear();	v[i].shrink_to_fit();	}
	}
}

inline int read()
{
    int temp=0;
    register int ch = getchar_unlocked();
    while(ch<'0' || ch>'9')     {   ch = getchar_unlocked();    }
    while(ch>='0' && ch<='9')   {   temp = (temp<<3) + (temp<<1) + ch -'0';     ch = getchar_unlocked();    }
    return temp;
}

void DFS()
{
	for(i=1;i<=N;++i)
	{
		if(flag && count)						ans = ( ans%MOD * count%MOD )%MOD;
		flag = 1;
		ans%=MOD;
		count = 0;
		if(v[i].size()==1 && !visited[i])	{	set++;	continue;	}
		if(!visited[i])						{	set++;	DFS_VISIT(i);	}
	}
}

void DFS_VISIT(int i)
{
	visited[i] = 1;
	if(v[i].size()!=1)
	{
		while(v[i][v[i].size()-1]>=0)
		{
			x = v[i].size();
			--x;
			y = v[i][x];
			v[i][x] = y-1;
			if(visited[v[i][y]]==0)
				DFS_VISIT(v[i][y]);
		}
	}
	count++;
	visited[i] = 2;
}