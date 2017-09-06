#include<iostream>
using namespace std;

int main()
{
    int t;
    long int A[50001];
    cin>>t;
    while(t--)
    {
        long int N,i,max=0;
        long long int ans=0;
        cin>>N;
        for(i=0;i<N;i++)
        {
            cin>>A[i];
            if(max<A[i])
                max=A[i];
        }
        for(i=0;i<N;i++)
        {
            if(A[i]<max)
                ans+=(max-A[i]);
        }
        cout<<ans<<endl;
    }
}
