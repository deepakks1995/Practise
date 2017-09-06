/*
*	User_ID	@deepakks1995
*	Problem_Code @INOI1302
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N,K,i,j;
int k,l,m,ans;
int ID[301][301];
bool set[301],flag;
int low,mid,high;

void BFS();
inline int read();
bool binary_search(int& , int& , int& );

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ans = 0;
	//Reading the input 
	N = read();
	K = read();
	for(i=0;i<N;i++)	{	ID[i][0] = read();	for(j=1;j<=ID[i][0];j++)	ID[i][j] = read();	sort(ID[i]+1,ID[i]+ID[i][0]+1);		}
	BFS();
	cout<<ans<<endl;
}

inline int read()			// Function to read input faster
{
    int temp=0;
    register int ch = getchar_unlocked();
    while(ch<'0' || ch>'9')     {   ch = getchar_unlocked();    }
    while(ch>='0' && ch<='9')   {   temp = (temp<<3) + (temp<<1) + ch -'0';     ch = getchar_unlocked();    }
    return temp;
}

bool binary_search(int& j , int& num , int& size )		// Function to execute Binary Search 
{
	low = 1;
	high = size;
	while(low<=high)				{	mid = ((low + high)/2);
		if(ID[j][mid]==num)				return 1;
		else if(ID[j][mid] > num)		high = mid-1;
		else if(ID[j][mid] < num)		low = mid + 1;	}
	return 0;
}

void BFS()	// Breadth-First-Search to iterate through all relatives one by one
{
	queue<int> q;
	q.push(0);
	set[0]=1;
	ans++;
	while(!q.empty())				{	k=0;	i = q.front();		q.pop();
		for(j=0;j<N;j++)			{
		if(!set[j])					{	k=0;
		for( l = 1;l<=ID[i][0];l++)	{	flag = binary_search(j,ID[i][l],ID[j][0]);
		if(flag)						k++;
		if(k>=K)						break;	}	}
		if(k>=K)					{	set[j]=1;	k=0;	q.push(j);	ans++;	}	}	}
}