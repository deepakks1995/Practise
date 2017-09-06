
#include <bits/stdc++.h>
#define MAXSize 16389
using namespace std;

int N;
int arr[MAXSize];
long long sumLeft,sumRight;

int doSomething(int lo, int hi);

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) {
		cin>>N;
		bool flag = 0;
		for(int i=0; i<N; ++i) {
			cin>>arr[i];
			if(arr[i])	flag = 1;
		}
		if(flag)
			cout<<doSomething(0,N-1)<<endl;
		else cout<<N-1<<endl;
	}
}

int doSomething(int lo, int hi) {
	sumRight = sumLeft = 0;
	int i = lo,j = hi,previ = -1, prevj = -1;
	while(i<=hi && i<=j) {
		if(i!=j && sumLeft  == sumRight)	 	{		sumLeft += arr[i];	sumRight += arr[j];	previ = i;	prevj = j;	++i,--j;	}
		else if(sumLeft > sumRight) 			{		sumRight += arr[j];	prevj = j;	--j;	}
		else if(sumLeft < sumRight) 			{		sumLeft += arr[i]; 	previ = i;	++i;	}
		else if(i==j && sumLeft  == sumRight)	{		sumLeft += arr[i];	previ = i;	++i;	}
	}
	if(sumLeft==sumRight && previ<prevj) 	return 1 + max(doSomething(lo,previ), doSomething(prevj,hi));
	else return 0;
}