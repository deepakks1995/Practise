/*input
9 2
4 1 2 3 5
4 0 10 100 2000
5 2 5 3 9 10
5 15 25 30 2 3
4 9 10 7 8
4 7 8 3 5
4 25 30 35 40
4 35 40 41 42
5 1 100 9 30 42
*/
#include <iostream>
#include <queue>
using namespace std;

int _ch;
int _i;
int _tmp;
char _str[10];

#define READ_INT(_x)					\
{							\
    _tmp = 0;					\
    _ch = getchar_unlocked();		\
    while (_ch < 48 || _ch > 57)			\
      _ch = getchar_unlocked();				\
    while (48 <= _ch && _ch <= 57)			\
      {							\
	_tmp = (_tmp << 3) + (_tmp << 1) + _ch - 48;	\
	_ch = getchar_unlocked();			\
      }							\
    (_x) = _tmp;					\
}							\

#define WRITE_INT(_x)				\
{						\
    _i = 0;			\
    _tmp = (_x);				\
    do						\
      {						\
	*(_str + _i++) = _tmp % 10 + 48;	\
	_tmp /= 10;				\
      } while (_tmp != 0);			\
    for (_i--; _i >= 0; _i--)			\
      putchar_unlocked(*(_str + _i));		\
}

int N,K,i,j;
int count,k,l,m;
int ID[301][301],map[301][301];
bool set[301];

void BFS();
void solve();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	count = 0;
	//cin>>N>>K;
	READ_INT(N);
	READ_INT(K);
	for(i=0;i<N;i++)
	{
		READ_INT(ID[i][0]);
		for(j=1;j<=ID[i][0];j++)
			READ_INT(ID[i][j]);
	}
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			map[i][j] = -1;
	solve();
}

void solve()
{
	int itr=0;
	for(i=0;i<N;i++)
	{
		itr = 0;
		for(j=0;j<N;j++)
		{
			k=0;
			if(j!=i)
			{
				for( l = 1;l<=ID[i][0];l++)
				{
					for( m = 1; m<=ID[j][0];m++)
					{
						if(ID[i][l] == ID[j][m])
						{
							k++;
							if(k>=K)
								break;
						}
					}
					if(k>=K)
						break;
				}
			}
			if(k>=K)
			{
				k=0;
				map[i][itr++] = j;
			}
		}
	}/*
	for(i=0;i<N;i++)
	{
		cout<<i<<"   ";
		for(j=0;j<N;j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}*/
	count = 0;
	BFS();
	WRITE_INT(count);
	//cout<<count<<endl;
}

void BFS()
{
	queue<int> q;
	q.push(0);
	set[0]=1;
	count++;
	int itr;
	while(!q.empty())
	{	
		i = q.front();
		q.pop();
		itr=0;
		while(map[i][itr]!=-1)
		{
			if(!set[map[i][itr]])
			{
				set[map[i][itr]] = 1;
				q.push(map[i][itr]);
				count++;
			}
			itr++;
		}
	}
}