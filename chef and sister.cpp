/*input
2
2
0 0
1 1
3
0 0
1 1
2 2
*/
#include <bits/stdc++.h>
#define SIZE 99999999
using namespace std;
bool prime[SIZE];
void SieveOfEratosthenes()
{
    memset(prime, true, SIZE);
 
    for (int p=2; p*p<=SIZE; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=SIZE; i += p)
                prime[i] = false;
        }
    }
}

int factor[SIZE];

void update(int n) {
	for(int i=1;;++i) {
		if(n*i >= SIZE)
			break;
		factor[n*i] = n;
	}
}

void doSomething() {
	for(int i=2; i<SIZE; ++i)
		if(prime[i])
			update(i);
}


int main()
{
	SieveOfEratosthenes();
	int t;
	long long A,K,N;
	doSomething();
	cin>>t;
	while(t--) {
		cin>>A>>K>>N;
		for(int )
	}
}