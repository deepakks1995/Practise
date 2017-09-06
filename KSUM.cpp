/*input
6 21
1 6 5 4 3 2
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	long N, K, i,j;
	cin>>N>>K;
	long arr[N];
	long long sum;
	for( i=0 ; i<N; i++ )
		cin>>arr[i];
	std::vector<long > v;
	for(i=0;i<N;i++)
	{
		sum = 0;
		for(j=i;j<N;j++)
		{
			sum+=arr[j];
			v.push_back(sum);
		}
	}
	sort (v.rbegin(), v.rend());
	for(i=0;i<K;i++)
		cout<<v[i]<<" ";
	cout<<endl;
}