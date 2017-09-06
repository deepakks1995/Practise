#include <iostream>
#define size 102
using namespace std;

int N,M,K1,K2,i,j,k,l,dir;
long arr[size][size];

int find_dir(int i, int j)
{
	int A1[4],A[4];
	A1[0] = arr[i-1][j];
	A1[1] = arr[i][j-1];
	A1[2] = arr[i][j+1];
	A1[3] = arr[i+1][j];
	A[0] = 1;
	A[1] = 2;
	A[2] = 3;
	A[3] = 4;
	for(int x=0;x<4;x++)
		for(int y=x+1;y<4;y++)
		{
			if(A1[x]>A1[y])
			{
				swap(A1[x],A1[y]);
				swap(A[x],A[y]);
			}
		}	
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	
	int t;
	cin>>t;
	bool left, right;
	while(t--)
	{
		left = right = 0;
		cin>>N>>M>>K1>>K2;
		for(i=1;i<=N;i++)
			for(j=1;j<=M;j++)
			{
				cin>>arr[i][j];
				if(arr[i][j])
					arr[i][j]=-1;
			}
		for(i=1;i<=N,j<=N;)
		{
			if(k==M+1 || j==M+1)
			{
				left = right = k = j = 0;
				i++;
			}
			if(arr[i][k]==-1)
				left = 1;
			if(arr[i][j]==-1)
				right = 1;
			if(!left && k<=M)
			{
				dir = find_dir(i,k);
			}
		}
	}
}