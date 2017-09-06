#include<iostream>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MOD 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    int M,N,x,y,i,j;
    long P;
    cin>>M>>N>>P;
    long **ans = (long **) calloc (M,sizeof(long *));
    int **block = (int **) calloc (M,sizeof(int *));
    for(i=0;i<M;i++)
    {
        ans[i] = (long *) calloc (N,sizeof(long ));
        block[i] = (int *) calloc (N,sizeof(int));
    }

    for(i=0;i<P;i++)
    {
        cin>>x>>y;
        *(*(block + x-1) + y-1) = 1;

    }
    *(*(ans + 0) + 0) = *(*(block + 0) + 0) ? 0:1 ;
    for(i=1;i<M;i++)
    {
        *(*(ans + i) + 0)= *(*(block + i) + 0) ? 0:*(*(ans + i-1) + 0);
    }
    for(i=1;i<N;i++)
    {
        *(*(ans + 0) + i) = *(*(block + 0) + i) ? 0 : *(*(ans + 0) + i-1) ;
    }
    for(i=1;i<M;i++)
        for(j=1;j<N;j++)
            {
                *(*(ans + i) + j) = *(*(block + i) + j) ? 0: (*(*(ans + i-1) + j) + *(*(ans + i) + j-1))%MOD;
            }
    cout<<*(*(ans + M-1) + N-1)<<endl;
    free(block);
    free(ans);
}
