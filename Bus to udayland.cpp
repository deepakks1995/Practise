/*input
3
3 8 1
2 4 6
7 0 5
*/
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	//cout<<"n: "<<n<<endl;
	if(n==1) {
		cin >> n;
		if(n==0) {
			cout<<"1\n";
			return 0;
		}
	}
	int row,col;
	int flag2 = 0;
	long long A[n+10][n+10],diag1=0,diag2=0;
	for(int i=0;i<=n;++i)
		A[i][0] = A[0][i] = 0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>A[i][j];
			A[i][0]+=A[i][j];
			A[0][j]+=A[i][j];
			if(A[i][j]==0)
			{
				++flag2;
				row = i;
				col = j;
			}
		}
	}
	for(int i=1,j=n; i<=n ;++i,--j)
	{
		diag1+=A[i][i];
		diag2+=A[i][j];
	}
	if(flag2!=1){
		cout<<"-1";
		return 0;
	}
	/*cout<<"Matrix:\n";
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=n;++j)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;*/
	bool check=0;
	long long ans = 0,sum;
	if(row==col && row!=n-col+1)
	{
		ans = diag2-diag1;
	}
	else if(row==n-col+1 && row!=col)
	{
		ans = diag1 - diag2;
	}
	else if (row == col && row == n-col +1 )
	{
		ans = A[row-1][0] - A[row][0];
		if(ans!=A[row+1][0] - A[row][0])
			check = 1;
	}
	else
	{
		ans = diag1 - A[row][0];
		if(diag1!=diag2)
			check = 1;
	}
	sum = ans + A[row][0];
	if(sum!=ans+A[0][col])
		check = 1;
	for(int i=1;i<=n;++i)
	{
		if(A[i][0]!=sum && i!=row)
		{
			check = 1;
			break;
		}
		if(A[0][i]!=sum && i!=col)
		{
			check = 1;
			break;
		}
		if(i==row)
		{
			if(sum!=ans+A[row][0])
				check = 1;
		}
		if(i==col)
		{
			if(sum!=ans+A[0][col])
				check= 1;
		}
	}
	if(!check && ans)
		cout<<ans;
	else
		cout<<"-1";
}