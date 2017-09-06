#include <iostream>
#include <cstdio>
using namespace std;
long long MOD = 1e9+7;

long long power(long long a, long long b)
{
    long long temp;
    if( b==0 )
        return 1;
    temp = power(a,b/2);
    if( b%2==0 )
        return ( temp%MOD * temp%MOD ) %MOD;
    else
        return (temp%MOD  *  temp%MOD  * a%MOD ) %MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    long long N,K,ans;
    while(t--)
    {
        cin>>N>>K;
        ans = K;
        ans*=power(K-1,N-1);
        ans%=MOD;
        cout<<ans<<endl;
    }
}
