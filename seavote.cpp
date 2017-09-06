#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,i;
        cin>>N;
        int m,sum=0,count=0;
        for(i=0;i<N;i++)
        {
            cin>>m;
            sum+=m;
            if(m!=0)
                count++;
        }
        if(sum>=100)
        {
            if((sum-count)<100)
                cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}
