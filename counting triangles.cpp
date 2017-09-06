#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
         long long int ans, n;
        cin>>n;

         ans=(n*(n+2)*(2*n+1)/8);
         cout<<ans<<"\n";
    }
    return 0;
}
