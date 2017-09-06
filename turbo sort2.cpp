#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
//#define k 10000001;
using namespace std;
int main()
{
    long int N,i,k=0;
    cin>>N;
    long int A[N+1],B[N+1];
    for(i=1;i<N+1;i++)
        {
            cin>>A[i];
            if(k<A[i])
                k=A[i];
        }
    // count sort
    long int count[k];
    for(i=1;i<k;i++)
        count[i]=0;
    for(i=1;i<N+1;i++)
        count[A[i]]+=1;
    for(i=2;i<k+1;i++)
        count[i]+=count[i-1];
    for(i=N;i>=1;i--)
    {
        B[count[A[i]]]=A[i];
        count[A[i]]-=1;
    }
    for(i=1;i<N+1;i++)
        cout<<B[i]<<"\n";
}
