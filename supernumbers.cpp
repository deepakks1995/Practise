#include<iostream>
#include<cmath>
using namespace std;
int phi(long long int n)
{
    long long int result=n;
    long long int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            result-=result/i;
        }
    }
    if(n>1)
        result-=result/n;
    return result;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N,M,count=0,i;
        cin>>N>>M;
        for(i=N;i<=M;i++)
        {
            if(i%phi(i)==0)
            {
                count++;
            }
        }
        cout<<count<<"\n";
    }
}
