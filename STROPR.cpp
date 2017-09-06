#include <iostream>
#include <cstdio>
using namespace std;
#define max(a,b,c)  \
{   \
    a= (a>b)?(a>c?a:c) : ((b>c)?b:c);   \
}   \

long long MOD = 1e9+7;
long long fast_power(long long x,long long y)
{
    long long ans=1;
    while(y>0)
    {
        if(y&1)
            ans=(ans*x)%MOD;
        x=(x*x)%MOD;
        y/=2;
    }
    ans%=MOD;
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif // ONLINE_JUDGE

    long long A[111111],prev[111111];
    int t;
    cin>>t;
    unsigned long long i,N,x,M,ans,j,tmp,tmp2;
    while(t--)
    {
        ans=0;
        cin>>N>>x>>M;
        M%=MOD;
        for(i=0; i<N; i++)
        {
            cin>>A[i];
            A[i]%=MOD;
        }
        prev[0]=1;
        for(i=1; i<x; ++i)
        {
            if(i==1)
                prev[i]=M;
            else
            {
                prev[i]=prev[i-1];
                tmp = (prev[i-1]%MOD)*((M-1)%MOD);
                tmp%=MOD;
                tmp2 = (fast_power(i,MOD-2))%MOD;
                prev[i]+= (tmp*tmp2)%MOD;
                prev[i]%=MOD;
            }
        }
        j=x-1;
        for(i=0; i<x; i++,--j)
        {
            ans+=(prev[i]*A[j])%MOD;
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
