/*
*	UserName: jyotisharma12
*	ProblemCode MBMMAR
*
*/
#include <bits/stdc++.h>
using namespace std;
#define MaxSize 1000001


// Variable Declaration goes here...........
long long tree[MaxSize][26];
long long N = MaxSize-1;


//Function Declaration goes here.............
void update (long long , char );
long long query(long long , char );

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	for(long long i=0; i<MaxSize; ++i)
		for(long long j=0;j<26; ++j)
			tree[i][j] = 0;
	long long Q;
	long long type,left,right,m;
	char x;
	cin>>Q;
	while(Q--) {
		cin>>type;
		if(type==1) {
			cin>>m>>x;
			update(m,x);
		}
		else {
			cin>>left>>right>>x;
			--left;
			cout<<query(right,x) - query(left,x)<<endl;;
		}
	}
	return 0;
}

long long query(long long n, char x) {
	long long sum = 0;
	while(n>=1) {
		sum+= tree[n][x-'a'];
		n -= (n & (-n));
	}
	return sum;
}

void update (long long m, char x) {
	while(m<=N){
		tree[m][x-'a'] += 1;
		m += (m & (-m));
	}
}