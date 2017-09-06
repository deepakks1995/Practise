#include<iostream>
#include <cstdio>
#include <string.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif // ONLINE_JUDGE
    int t;
    cin>>t;
    long A[100][100],count[10000]={0};
    long N,M,maximum,max,i,j,k;
    while(t--)
    {
        maximum=0;
        max=0;
        cin>>N>>M;
        for(i=0; i<N; i++)
            for(j=0; j<M; j++)
                cin>>A[i][j];
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                memset(count,0,sizeof(count));
                for(k=0;k<N;k++)
                {
                    count[A[k][j]]++;
                    if(max<count[A[k][j]])
                        max=count[A[k][j]];
                }
                for(k=0;k<j;k++)
                {
                    count[A[i][k]]++;
                    if(max<count[A[i][k]])
                        max=count[A[i][k]];
                }
                for(k=j+1;k<M;k++)
                {
                    count[A[i][k]]++;
                    if(max<count[A[i][k]])
                        max=count[A[i][k]];
                }
                if(maximum<max)
                    maximum=max;
            }
        }
        cout<<maximum<<endl;
    }
}
