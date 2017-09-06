#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int k,ans;
        cin>>k;
        ans=192+(k-1)*250;
        cout<<ans;
        cout<<endl;

    }
    return 0;
}
