#include <iostream>
using namespace std;
long long power(long long a, long long b)
{
    long long temp;
    if( b==0 )
        return 1;
    temp = power(a,b/2);
    if( b%2==0 )
        return ( temp%8388608 * temp%8388608 ) %8388608;
    else
        return (temp%8388608  *  temp%8388608  * a%8388608 ) %8388608;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long N,i,ans=0;
        cin>>N;
        for(i=1;i<=N;i++)
        {
            ans = (ans + (i*(i+1)/2)*power(2,i-1))%8388608;
            ans%=8388608;
        }
        cout<<ans<<endl;
    }
}
