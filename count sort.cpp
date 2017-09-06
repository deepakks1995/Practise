#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
void countsort(long int A[],long int k,long int N)
{
    long int B[N],i;
    long int count[k];
    for(i=0;i<=k;i++)
        count[i]=0;
    for(i=1;i<=N;i++)
        count[A[i]]+=1;
    for(i=1;i<=k;i++)
        count[i]+=count[i-1];
    for(i=N;i>=1;i--)
    {
        B[count[A[i]]]=A[i];
        count[A[i]]-=1;
    }
    for(i=1;i<=N;i++)
        A[i]=B[i];
}
int main()
{
    long int N,i,k=0;
    cin>>N;
    long int A[N],B[N];
    for(i=1;i<=N;i++)
        {
            cin>>A[i];
            if(k<A[i])
                k=A[i];
        }
    // count sort
    countsort(A,k,N);
    for(i=1;i<=N;i++)
        cout<<A[i]<<"\n";
}
