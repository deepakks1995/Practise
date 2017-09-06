#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define max(a,b,c)    \
{   \
    return (a>b)?(a>c?a:c) : ((b>c)?b:c);   \
}   \


int main()
{
    long long N,K,i,j;
    cin>>N>>K;
    long long A[N+1];
    for(i=0; i<N; i++)
        cin>>A[i];
    sort(A,A+N);
    long long count=0;
//    for(i=0;i<N;i++)
//        cout<<A[i]<<" ";
//    cout<<endl;
    for(i=0,j=N-1; i<j;)
    {
        if(A[i]>=K)
            break;
        if(A[i]+A[j]<K)
        {
            count+=j-i;
//            cout<<"i "<<i<<" j "<<j<<" j-i "<<j-i<<endl;;
            ++i;
        }
        else
            --j;
    }
    cout<<count<<endl;
    return 0;

}

//5 4 2 1 6 2 0 4 4 1
