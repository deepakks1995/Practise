#include <cstdio>
#include<iostream>

using namespace std;
unsigned long long M = 1000000007LL;


int main(int argc, char const *argv[])
{
	long test;
	cin>>test;
	while(test--)
	{
		unsigned long long ans=0;
		long n;
		cin>>n;
		unsigned long long arr[n+1];
		unsigned long long mul[n+1];
		unsigned long long mul2[n+1];
		for (unsigned long long i = 0; i <=n; ++i)
		{
			cin>>arr[i];
			mul[i]=1;
			mul2[i]=1;

		}
		mul[n]=1;
		for (unsigned long long i = n-1; i >0; --i)
		{

			mul[i]=(mul[i+1]*2)%M;
		}

		mul2[0]=1;
		mul2[1]=1;
		for (unsigned long long i = 2; i <=n; ++i)
		{
			mul2[i]=(mul2[i-1]*2)%M;

		}
		unsigned long long seq=0;
		for (unsigned long long i = 1; i <=n; ++i)
		{

				seq=(seq+(arr[i-1]*mul2[i-1]))%M;
				unsigned long long tmp=(arr[i]*mul[i])%M;
				tmp=(tmp*seq)%M;
				ans = (ans + tmp)%M;
		}
		ans=(ans*2)%M;
		cout<<ans<<"\n";
	}
	return 0;
}
