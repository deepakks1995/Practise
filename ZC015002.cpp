#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long N,K,i,j;
    cin>>N>>K;
    long A[N+1];
    for(i=0;i<N;i++)
        cin>>A[i];
    sort(A,A+N);
    long count=0;
    long total=N*N;
    for(i=0,j=N-1; i<j;)
    {
        if(A[i]>=K)
            break;
        if(abs(A[i]-A[j])<K)
        {
            count+=j-i;
            ++i;
        }
        else
            --j;
    }
    cout<<total-count;
}
