#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t,N,M,K,count1,count2;
    cin>>t;
    int A[200],B[200],C[200],x;
    while(t--)
    {
        count1=0;
        count2=0;
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        memset(C,0,sizeof(C));
        cin>>N>>M>>K;
        for(int i=0;i<M;i++)
        {
            cin>>x;
            A[x]=1;
            C[x]=1;
        }
        for(int i=0;i<K;i++)
        {
            cin>>x;
            B[x]=1;
            if(C[x])
                C[x]=2;
        }
        for(int i=1;i<=N;i++)
            if(C[i]==2)
                count1++;
        memset(C,0,sizeof(C));
        for(int i=1;i<=N;i++)
            if(A[i]==0)
                C[i]=1;
        for(int i=1;i<=N;i++)
            if(B[i]==0)
                if(C[i]==1)
                    C[i]=2;
        for(int i=1;i<=N;i++)
            if(C[i]==2)
                count2++;
        cout<<count1<<" "<<count2<<endl;
    }
    return 0;
}
