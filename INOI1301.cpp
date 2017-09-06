/*input
5 2
5 3 -2 1 1
*/
#include <iostream>
#include <vector>
#define MAX_SIZE (int)1000001
#define MIN_SIZE(int)(-10000)
using namespace std;

std::vector<int> v(MAX_SIZE);

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	int N,k;
	cin>>N>>k;
	for (int i = 0; i < N; ++i){
		cin>>v[i];
	}
	int dp[N];
	dp[0] = 0;
	dp[1] = v[0];
	for(int i=2; i<N; ++i) {
		dp[i] = max(dp[i-1] + v[i-1], dp[i-2] + v[i-2]);
	}
	--k;
	dp[N-2] = max(dp[N-2], v[N-1] + dp[N-1]);
	for(int i=N-3; i>=k; --i) {
		dp[i] = max(max(dp[i], dp[i+1] + v[i+1]), dp[i+2] + v[i+2]);
	}
	cout<<dp[k]<<endl;
}
