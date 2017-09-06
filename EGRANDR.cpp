/*input
2
5
3 5 4 4 3
5
3 4 4 4 5
*/
#include <iostream>
#include <cstdio>
using namespace std;

long long N,i,A;
double sum;
bool check1,check2;
int t;

int main()
{
	ios_base::sync_with_stdio(0);	
	cin>>t;
	scanf("%d",&t);
	while(t--)
	{	
		sum = check1 = check2 = 0;
		cin>>N;
		for(i=0;i<N;i++)
		{
			cin>>A;
			scanf("%lld",&A);
			sum+=A;
			if(A==2)
				check1=1;
			if(A==5)
				check2=1;
		}
		sum/=N;
		if((!check1) && check2 && (sum>=4))
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}
}