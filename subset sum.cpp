#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
int read()
{
    register int ch=getchar_unlocked();
    int temp=0;
    while(ch<'0' || ch>'9')  ch=getchar_unlocked();
    while(ch>='0' && ch<='9')
    {
        temp = (temp << 3) + (temp << 1) + ch-'0';
        ch=getchar_unlocked();
    }
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    t=read();
    while(t--)
    {
        int N,K,i,j;
        N=read();
        K=read();
        int *A = (int *) calloc (N,sizeof(int));
        for(i=0;i<N;i++)
            A[i]=read();
        bool sub[K+1][N+1];
        for(i=0; i<=N; i++)
            sub[0][i]=1;
        for(i=1; i<=K; i++)
            sub[i][0]=0;
        for(i=1; i<=K; i++)
        {
            for(j=1; j<=N; j++)
            {
                sub[i][j]=sub[i][j-1];
                if(i>=A[j-1])
                    sub[i][j]=sub[i][j] || sub[i-A[j-1]][j-1];
            }
        }
        cout<<sub[K][N]<<endl;
        free(A);
    }
    return 0;
}

