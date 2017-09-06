#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long A[100000],B[100000],i,C[2][100000],j;
    long long sum,index;
    while(t--)
    {
        sum=0;
        long long N,K;
        cin>>N>>K;
        for(i=0; i<N; i++)
            cin>>A[i];
        for(i=0; i<N; i++)
        {
            cin>>B[i];
            C[0][i]=A[i]*B[i];
            C[1][i]=i;
        }
        for(i=0;i<N-1;i++)
            for(j=i+1;j<N;j++)
                if(C[0][i]>C[0][j])
                {
                    swap(C[1][i],C[1][j]);
                    swap(C[0][i],C[0][j]);
                }
            for(i=0;i<N-1;i++)
                sum+=C[0][i];
        if(abs(C[0][0])<=abs(C[0][N-1]))
        {
            index=C[1][N-1];
            if((A[index]>0 && B[index]>0))
                A[index]+=K;
            else if(A[index]<0 && B[index]<0)
                A[index]-=K;
            else if(A[index]>0 && B[index]<0)
                A[index]-=K;
            else if(A[index]<0 && B[index]>0)
                A[index]+=K;
            sum-=C[0][index];
            sum+=A[index]*B[index];
        }
        else
        {
            index=C[1][0];
            if((A[index]>0 && B[index]>0))
                A[index]+=K;
            else if(A[index]<0 && B[index]<0)
                A[index]-=K;
            else if(A[index]>0 && B[index]<0)
                A[index]-=K;
            else if(A[index]<0 && B[index]>0)
                A[index]+=K;
                        sum-=C[0][index];
            sum+=A[index]*B[index];
        }
        cout<<sum<<endl;
    }
    return 0;
}
