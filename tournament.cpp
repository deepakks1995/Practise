#include<iostream>
#include<malloc.h>
#include<cstdio>
using namespace std;
long int READ()
{
    long int tmp = 0;
    register int ch = getchar_unlocked();
    while ( ch < 48 || ch > 57)
      ch = getchar_unlocked();
    while (48 <= ch && ch <= 57)
      {
	tmp = (tmp << 3) + (tmp << 1) + ch - 48;
	ch = getchar_unlocked();
      }
    return tmp;
}

int cmpf(const void *a, const void *b)
{
    return (*(long int *)a-*(long int *)b);
}
int main()
{
    long int N,i;
    long int *A;
    /*cin>>*/N=READ();
    A=(long int *)calloc(N,sizeof(long int));
    long long int sum=0,ans=0;
    for(i=0;i<N;i++)
    {
        /*cin>>*/A[i]=READ();
        sum+=A[i];
    }
    qsort(A,N,sizeof(int),cmpf);
    for(i=0;i<N-1;i++)
    {
        sum-=A[i];
        ans+=(sum-A[i]*(N-1-i));
    }
    cout<<ans;
    free(A);
    return 0;
}
