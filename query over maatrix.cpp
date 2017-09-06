#include<iostream>
using namespace std;

int main()
{
    long N;
    cin>>N;
    bool **N=(bool **)  calloc (N,sizeof(bool*));
    for(i=0;i<N;i++)
        N[i]=(bool *) calloc (N,sizeof(bool));
    for(i=0;i<N;i++)
    {
        cin>>x>>y;
        for(j=x-1;j<y;j++)
            N[i][j]=1;
    }
    cin>>Q;
    for(i=0;i<Q;i++)
    {
        cin>>x>>y;

    }
}
