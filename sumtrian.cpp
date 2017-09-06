/*input
2
3
1
2 1
1 2 3
4 
1 
1 2 
4 1 2
2 3 1 1
*/
#include <iostream>
#include <cmath>
#include <malloc.h>
#include <string.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	long max;
	cin>>t;
	int A[100][100]={0},sum[100][100];
	while(t--)
	{
		max=0;
		memset(sum,0,sizeof(sum));
		int n,i,j;
		cin>>n;
		cin>>A[0][0];
		sum[0][0] = A[0][0];
		for(i=1;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				cin>>A[i][j];
				if(j==0)
					sum[i][j]=sum[i-1][j]+A[i][j];
				else if(i==j)
					sum[i][j] = A[i][j] + sum[i-1][j-1];
				else
				{
					if(sum[i-1][j]>sum[i-1][j-1])
						sum[i][j] = A[i][j] + sum[i-1][j];
					else
						sum[i][j] = A[i][j] + sum[i-1][j-1];
				}
			}
		}
		for(i=n-1,j=0;j<=i;j++)
		{
			if(max<sum[i][j])
				max=sum[i][j];
		}		
		cout<<max<<endl;
	}
}