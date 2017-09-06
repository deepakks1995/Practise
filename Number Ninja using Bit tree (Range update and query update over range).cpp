/*
*	UserName: jyotisharma12
*	ProblemCode: NNINJA
*	link: https://www.codechef.com/CDMR2016/problems/NNINJA
*/
#include <bits/stdc++.h>
using namespace std;
#define MaxSize 100001

int N,Q,L,R;
long long binaryIndexedTree1[MaxSize],binaryIndexedTree2[MaxSize];
long long X, S, totalSum;


/*Function declaration goes here
**************************************/
bool binarySearch(long long ,int , int );
void update(int , long long , bool ) ;
void updateRange(int , int , long long );
long long query(bool ,int );
long long query(int );
long long ReadLong();
int ReadInt();

int main()
{
	//Fast Input/output
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	for(int i=0; i<MaxSize; ++i)
		binaryIndexedTree2[i] = binaryIndexedTree1[i] = 0;
	N = ReadInt();
	Q = ReadInt();
	for(int i=1; i<=N; ++i) {
		X = ReadLong();
		updateRange(i,i,X);
	}

	//Querying..............
	int type;
	while(Q--) {
		
		type = ReadInt();
		if(type==1){
			L = ReadInt();
			R = ReadInt();
			X= ReadLong();
			updateRange(L,R,X);
		}
		else {
			bool check = false;	
			S= ReadLong();
			totalSum = query(N);
			int lo = 1,hi = N,mid;
			if(S!=totalSum) {
				while(lo < hi) {
					int mid = (lo + hi ) / 2;
					if(S > totalSum - query(mid)) 					hi = mid;
					else if (S < totalSum - query(mid)) 			lo = mid+1;	
					else 									{		cout<<"Found "<<mid + 1<<endl;		check = true; 	break;	}
				}
			}
			else {
				cout<<"Found 1"<<endl;
				check = true;
			}
			if(!check) cout<<"Not Found"<<endl;
		}
	}
}

bool binarySearch(long long totalSum,int lo, int hi) {
	while(lo < hi) {
		int mid = (lo + hi ) / 2;
		if(S > totalSum - query(mid)) 					hi = mid;
		else if (S < totalSum - query(mid)) 			lo = mid+1;	
		else 									{		cout<<"Found "<<mid + 1<<endl;		return true;	}
	}
	return false;
}

void update(int i, long long X, bool flag) {
	for(; i<=N; i += (i & -i)){
		if(!flag)	binaryIndexedTree1[i] += X;
		else 		binaryIndexedTree2[i] += X;
	}
}

void updateRange(int L, int R, long long X) {
	update(L, X,0);
	update(R+1,-X,0);
	update(L,X*(L-1),1);
	update(R+1, -X*R, 1);
}


long long query(bool flag,int i) {
	long long sum = 0;
	for(; i> 0; i -= i & -i){
		if(!flag)	sum += binaryIndexedTree1[i];
		else 		sum+= binaryIndexedTree2[i];
	}
	return sum;
}

long long query(int b) {
	return query(0,b)*b - query(1,b);
}


/*Functions for fast Input 
********************************************/
long long ReadLong() {
	register int ch = getchar_unlocked();
	long long temp = 0;
	while(ch<'0' || ch>'9')			ch = getchar_unlocked();
	while(ch>='0' && ch<='9') 	{	temp = (temp<<3) + (temp<<1) + ch-48;	ch = getchar_unlocked();	}
	return temp;
}


int ReadInt() {
	register int ch = getchar_unlocked();
	int temp = 0;
	while(ch<'0' || ch>'9')			ch = getchar_unlocked();
	while(ch>='0' && ch<='9') 	{	temp = (temp<<3) + (temp<<1) + ch-48;	ch = getchar_unlocked();	}
	return temp;
}