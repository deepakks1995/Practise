
/*
*	UserId: deepakks1995
*	link: https://www.codechef.com/APRIL17/problems/CLIQUED
*	Description: Optimized Dijkstra implemented using sets
*/
#include <bits/stdc++.h>
using namespace std;

const long long Max = 9999999999999;
typedef set<pair<long long, long long > > myset;
long long N, K, X, M, S;
void applyDijkstra();
long long ReadInt();
int mycmpf(std::vector<long long> &, std::vector<long long> &);
myset v[100000];

int main() {
	int t = ReadInt();
	ios_base::sync_with_stdio(false);
	while (t--) {
		N = ReadInt();
		K = ReadInt();
		X = ReadInt();
		M = ReadInt();
		S = ReadInt();
		--S;
		long long a, b, c;
		for (long long i = 0; i < M; ++i) {
			a = ReadInt();
			b = ReadInt();
			c = ReadInt();
			--a;
			--b;
			v[a].insert(make_pair(c, b));
			v[b].insert(make_pair(c, a));
		}
		applyDijkstra();
		for (int i = 0; i < 100000; ++i)
			v[i].clear();
	}
}


void applyDijkstra() {
	long long dist[N];
	myset sets;
	for (long long i = 0; i < N; ++i)  dist[i] = Max;
	bool firstTime = true;
	if (S < K) {
		firstTime = false;
		for (long long i = 0; i < K; ++i) {
			if (i == S)
				continue;
			dist[i] = X;
			sets.insert(make_pair(dist[i], i));
		}
	}
	dist[S] = 0;
	sets.insert(make_pair(0, S));
	long long min = Max, u;

	while (!sets.empty()) {
		pair<long long, long long> temp = *(sets.begin());
		sets.erase(sets.begin());
		u = temp.second;
		if (v[u].size() != 0) {
			for (myset::iterator i = v[u].begin(); i != v[u].end() ; ++i ) {
				
				if (dist[u] + (*i).first < dist[(*i).second]) {
					if (dist[(*i).second] != Max)
						sets.erase(sets.find(make_pair(dist[(*i).second], (*i).second)));
					dist[(*i).second] = dist[u] + (*i).first;
					sets.insert(make_pair(dist[(*i).second], (*i).second));

					if (firstTime && (*i).second < K) {
						firstTime = false;
						for (long long it = 0; it < K; ++it) {
							if (it == (*i).second)
								continue;
							dist[it] = X + dist[(*i).second];
							sets.insert(make_pair(dist[it], it));
						}
					}
				}
			}
		}
	}
	min = Max;
	for (int i = 0; i < K; ++i)
		if (dist[i] < min)
			min = dist[i];
	for (int i = 0; i < K; ++i) {
		if (dist[i] > min + X)
			dist[i] = min + X;
	}
	for (long long i = 0; i < N; ++i)
		cout << dist[i] << " ";
	cout << endl;
}

long long ReadInt() {
	register int ch = getchar_unlocked();
	long long temp = 0;
	while (ch < '0' || ch > '9')			ch = getchar_unlocked();
	while (ch >= '0' && ch <= '9') 	{	temp = (temp << 3) + (temp << 1) + ch - 48;	ch = getchar_unlocked();	}
	return temp;
}

int mycmpf(std::vector<long long> &a, std::vector<long long> &b) {
	return a[0] < b[0];
}