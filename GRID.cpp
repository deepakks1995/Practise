#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    scanf("%d",&t);
   //cin>>t;
    long long MOD = 1e9+7;
    long long N,M,H,K,i,j;
    while(t--)
    {
        scanf("%ld",&N);
        scanf("%ld",&M);
        scanf("%ld",&H);
        scanf("%ld",&K);
        // cin>>N>>M>>H>>K;
        long long arr[N][M];
        for(i=0; i<M; i++)
            arr[0][i] = 1;
        for(i=0; i<N; i++)
            arr[i][0] = 1;
//        for(i=H-1;i<N;i++)
//            for(j=K-1;i<M;i++)
//                arr[i][j] = -1;
        for(i=1; i<H-1; i++)
        {
            for(j=1; j<=K-1; j++)
            {
                arr[i][j]= (arr[i-1][j]%MOD + arr[i][j-1]%MOD)%MOD;
                arr[i][j]%=MOD;
            }
        }
        for(i=1; i<N; i++)
        {
            for(j=K; j<M; j++)
            {
                if(i<H-1)
                {
                    arr[i][j] = (arr[i-1][j]%MOD + arr[i][j-1]%MOD)%MOD;
                    arr[i][j]%=MOD;
                }
                else
                {
                    if(j==K)
                    {
                        arr[i][j] = arr[i-1][j]%MOD;
                    }
                    else
                    {
                        arr[i][j] = (arr[i-1][j]%MOD + arr[i][j-1]%MOD)%MOD;
                        arr[i][j]%=MOD;
                    }
                }
            }
        }
        cout<<arr[N-1][M-1]%MOD<<endl;
    }
}
