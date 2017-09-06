#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<cmath>
using namespace std;
/*long long int READ()
{
    long long int tmp=0;
    register int ch=getchar_unlocked();
    while(ch<'0' || ch>'9')
        ch=getchar_unlocked();
    while(ch>='0' || ch<='9')
    {
        tmp=(tmp << 3)+ (tmp << 1)+ ch-48;
        ch=getchar_unlocked();
    }
    return tmp;
}*/
int main()
{
    long long int N, K,i,j,count=0;
    cin>>N;//=READ();
    cin>>K;//=READ();
    long long int *A=(long long int *) calloc (N,sizeof(long long int));
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<N-1;i++)
    {
        for(j=i+i;j<N;j++)
        {
            if(abs(A[i]-A[j])>=K)
                count++;
        }
    }
    cout<<count;
    return 0;
}
