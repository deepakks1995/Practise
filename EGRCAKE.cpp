#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int N,M,i,j=1,count=0;
        cin>>N>>M;
        long long int **A=(long long int**)calloc (N,sizeof(long long int *));
        for(i=0;i<N;i++)
            A[i]=(long long int*)calloc (2,sizeof(long long int ));
        for(i=0;i<N-M;i++)
        {
            A[i][0]=M+1+i;
        }
        for(;i<N;i++)
            A[i][0]=j++;
        int check=0;
        i=0;
        while(check!=1)
        {
            if(A[i][1])
                check=1;
            else {
                    A[i][1]=1;
                    i=A[i][0]-1;
                    count++;
            }
        }
        if(count==N)
            cout<<"Yes\n";
        else cout<<"No "<<count<<"\n";
    }
    return 0;
}
