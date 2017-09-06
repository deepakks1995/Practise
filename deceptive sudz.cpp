#include <iostream>
using namespace std;
int comp(const void *a, const void *b)
{
	return (*(long long int *)a-*(long long int *)b);
}
int main() {
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int A[n],sum=0,i,check=0;
		for(i=0;i<n;i++)
		{
			cin>>A[i];
			sum+=A[i];
		}
		qsort(A,n,sizeof(long long int),comp);
		sum/=2;
		i=0;
		while(check<=sum)
		{
			check+=A[i++];
		}
		cout<<i-1<<endl;
	}
	return 0;
}
