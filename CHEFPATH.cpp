#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    long long N,M;
    while(t--)
    {
        cin>>N>>M;
        if(N%2==0 && M%2==0)
            cout<<"Yes\n";
        else if(N%2==1 && M%2==0)
        {
            if(N==1)
            {
                if(M==2)
                    cout<<"Yes\n";
                else cout<<"No\n";
            }
            else cout<<"Yes\n";
        }
        else if(N%2==0 && M%2==1)
        {
            if(M==1)
            {
                if(N==2)
                    cout<<"Yes\n";
                else cout<<"No\n";
            }
            else cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
    return 0;
}
