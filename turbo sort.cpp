#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
void countsort(int A[],int k,int N)
{
    int B[N+1],C[k+1],i=0;
    for(i=0;i<=k;i++)
        C[i]=0;
    for(i=1;i<=N;i++)
        C[A[i]]++;
    for(i=1;i<=k;i++)
        C[i]+=C[i-1];
    for(i=N;i>=1;i--)
    {
        B[C[A[i]]]=A[i];
        C[A[i]]--;
    }
    for(i=1;i<=N;i++)
        A[i]=B[i];
}
int main()
{
      int t,i,k=0;
    scanf("%d",&t);
         int A[t+1];
        for(i=1;i<=t;i++)
        {
            scanf("%d",&A[i]);
            if(k<A[i])
                k=A[i];
        }
        countsort(A,k,t);
        for(i=1;i<=t;i++)
            printf("%d\n",A[i]);


}
