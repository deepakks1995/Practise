#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
using namespace std;
const long long int mod = 1000000007;

int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int D;
        long long int N,i,j=0,ans1=0,c=0;
        cin>>N>>D;
        long long int *sq=(long long int *)calloc (2*N,sizeof(long long int));
        for(i=1; i<=N; i++)
            sq[j++]=(i*D*D);
        for(i=N-1; i; i--)
            sq[j++]=i*D*D;
        for(i=0; i<j; i++)
        {
            sq[i]+=c;
            c=sq[i]/10;
            sq[i]%=10;
        }
        while(c)
        {
            sq[i++]+=c%10;
            c/=10;
        }
        ans1=0;
        int p=23;
        for(j=0; j<i; j++)
        {
            ans1=(ans1*p+sq[j])%mod;
        }
        cout<<ans1<<endl;
        free(sq);
    }
}
