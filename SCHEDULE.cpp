/*input
2
4 1
0011
6 1
111111
1 1
0
2 0
00
3 1
101
20 4
11000011111100000000
7 0
0101010
4 1
0101
4 1
1010
15 6
111100000111111
9 2
110001111
4 1
1001
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		int N,K;
		cin>>N>>K;
		string s;
		cin>>s;
		int count = 0, zeros = 0;
		for (int i=0; i< s.length(); ++i) {
			if(i%2==0){
				if(s[i] == '1')
					++count;
			}else {
				if(s[i] == '0')
					++count;
			}
			if(s[i] == '0')
				++zeros;
		}
		if ( K >= min(count, N-count) )
			cout<<1;
		else {
			int prev = s[0];
			bool isGroup = false;
			int groupCount = 1;
			std::priority_queue<int> que;
			for (int i=1; i<N; ++i) {
				if(s[i] == prev){
					isGroup = true;
					++groupCount;
				}
				else {
					isGroup = false;
					que.push(groupCount);
					groupCount = 1;
					if(i == N-1)
						isGroup = true;
				}
				prev = s[i];
			}
			if(isGroup){
				isGroup = false;
				que.push(groupCount);
				groupCount = 0;
			}
			// cout<<"queue"<<endl;
			// while(!que.empty()) {
			// 	cout<<que.top();
			// 	que.pop();
			// }
			// cout<<"que ends" <<endl;
			int max = 0;
			bool flag = false;
			while(!que.empty() && K!=0) {
				max = que.top();
				que.pop();
				if(max == 2) {
					flag = true;
					break;
				}
				// cout<<max << " ";
				if(max%2 == 0) {
					int half = max/2;
					que.push(half);
					que.push(half - 1);
				}
				else {
					int half = max/2;
					que.push(half);
				}
				--K;
			}
			if(!flag)
				cout<<que.top();
			else cout<<max;

		} 
		cout<<endl;
	}
}