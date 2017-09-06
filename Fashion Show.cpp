#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        int n,sum=0;
        cin>>n;
        int m[n],f[n];
        for(i=0;i<n;i++)
        {
            cin>>m[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>f[i];
        }
        sort(m,m+n);
        sort(f,f+n);
        for(i=0;i<n;i++)
        {
            sum=sum+(m[i]*f[i]);
        }
        cout<<sum<<endl;
    }

}
