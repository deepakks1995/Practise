#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
int cmpf(const void *a, const void *b)
{
    return (*(long long int *)a-*(long long int *)b);
}

long long int READ()
{
    long long int tmp = 0;
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
int main()
{
    ios_base::sync_with_stdio(0);
    long long int N,i;
    N=READ();
    long long int *A=(long long int *) calloc (N, sizeof(long long int));
    for(i=0;i<N;i++)
    {
        A[i]=READ();
    }
    qsort(A,N,sizeof(long long int),cmpf);
    long long int revenue,max=0;
    for(i=0;i<N;i++)
    {
        revenue=A[i]*(N-i);
        if(max<revenue)
            max=revenue;
    }
    cout<<max<<endl;
    free(A);
}
