/*input
4 5
1 2 10
1 3 24
2 3 2
2 4 15
3 4 7
*/
#include <iostream>
#define INF 9999999
using namespace std;

int C,F,x,y;
int graph[300][300],p,i,j,min_index;
int length,ans,dist[250];
bool set[250];

int find_minimum();
int Dijkstra(int );
void Floyd_Warshall();

int main()
{
	ios_base::sync_with_stdio(false);

	cin>>C>>F;
	for(i=0;i<=C;i++)
		for(j=0;j<=C;j++)
			graph[i][j] = INF;
	for(i=0;i<F;i++)
	{
		cin>>x>>y>>p;
		x--;
		y--;
		graph[x][y] = p;
		graph[y][x] = p;
	}
	for(i=0;i<C;i++)
		graph[i][i]=0;
	
	for(i=0;i<C;i++)
	{
		length = Dijkstra(i);
		if(ans<=length)
			ans = length;
	}
	//Floyd_Warshall();
	cout<<ans<<endl;
}

void Floyd_Warshall()
{
	ans = 0;
	for(x=0;x<C;x++)
		for(i=0;i<C;i++)
			for(j=0;j<=C;j++)
				if(graph[i][j] > graph[i][x] + graph[x][j])
					graph[i][j] = graph[i][x] + graph[x][j];
	for(i=0;i<C;i++)
		for(j=0;j<C;j++)
			if(ans<graph[i][j])
				ans = graph[i][j];
}

int find_minimum()
{
	int mini = INF,index=-1;
	for(x=0;x<C;x++)
		if(set[x]==false && dist[x]!=INF && dist[x]<=mini)
		{
			mini = dist[x];
			index = x;
		}
	return index;
}

int Dijkstra(int index)
{
	for(j=0;j<C;j++)
	{
		set[j]=false;
		dist[j] = INF;
	}
	dist[index] = 0;
	for(y=0;y<C-1;y++)
	{
		min_index = find_minimum();
		set[min_index] = true;
		for(int v=0;v<C;v++)
			if(set[v]==false && graph[min_index][v] && graph[min_index][v]!=INF && dist[min_index]!=INF && dist[min_index] + graph[min_index][v] < dist[v])
				dist[v] = dist[min_index] + graph[min_index][v];
	}
	int distance = 0;
	for(y=0;y<C;y++)
		if(dist[y]!=INF && distance < dist[y])
			distance = dist[y];
	return distance;
}