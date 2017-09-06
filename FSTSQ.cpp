#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<vector>
using namespace std;
const long long int mod = 1000000007;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int D;
        long long N,i,c=0,ans1=0;
        cin>>N>>D;
        vector <int> a;
        for(i=1;i<=N;i++)
            a.push_back(i*D*D);
        for(i=N-1;i;i--)
            a.push_back(i*D*D);
        for(i=0;i<a.size();i++)
        {
            a[i]+=c;
            c=a[i]/10;
            a[i]%=10;
        }
        while(c)
        {
            a.push_back(c%10);
            c/=10;
        }
        ans1=0;
        int p=23;
        for(i=0;i<a.size();i++)
        {
            ans1=(ans1*p+a[i])%mod;
        }
        cout<<ans1<<endl;
    }
}
