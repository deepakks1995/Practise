#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <stdlib.h>
//#define ONLINE_JUDGE
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE

    long long t,i,N,Q,count;
    double K;
    double A[1000000];
    cin>>t;
    while(t--)
    {
        cin>>N>>Q;
        for(i=0;i<N;i++)
            cin>>A[i];
       /* for(i=0;i<N;i++)
            cout<<A[i]<<" ";
        cout<<endl;*/
        sort(A,A+N);
        /*for(i=0;i<N;i++)
            cout<<A[i]<<" ";
        cout<<endl;*/
        while(Q--)
        {
            cin>>K;
            double *p = upper_bound(A,A+N,K);
            i = p-A;
        //cout<<K<<endl;
                   // cout<<"i: "<<i<<endl;
            cout<<N-i<<"\n";
        }
    }
    return 0;
}
