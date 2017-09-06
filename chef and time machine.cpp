/*
input
2
4 2 2
5 7 9 1
3 3 1 1
1 3
6 4

4 2 3
9 6 2 7
3 4 1 3
//6 2 1 4
5 6
2 4 6

5 3 5
10 24 6 8 12
6 15 1 7 2
//4 9 5 1 10
3 6 8
10 15 2 6 6
*/
#include<iostream>
#include<stdlib.h>
#define fori(i,a,b)  for(i=a;i<b;i++)
using namespace std;
int cmp(const void *a,const void *b)
{
    return (*(long int *)b - *(long int *)a );
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        long int N,K,M,i,j;
        cin>>N>>K>>M;
        long A[N],B,C[K+M];
        long long int sum=0;
        fori(i,0,N)
            cin>>A[i];
        fori(i,0,N)
        {
            cin>>B;
            A[i]-=B;
            sum+=A[i];
        }
        qsort(A,N,sizeof(long int ),cmp);
        fori(i,0,(K+M))
            cin>>C[i];
        qsort(C,(K+M),sizeof(long int),cmp);
        j=0;
        fori(i,0,N)
        {
            for(;j<(K+M);j++)
            {
                if(A[i]>=C[j])
                {
                    sum-=C[j];
                    j++;
                    break;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
