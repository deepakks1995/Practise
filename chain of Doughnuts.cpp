#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
void countsort(long int A[],long int k,long int N)
{
    long int B[N],i;
    long int count[k];
    for(i=0;i<=k;i++)
        count[i]=0;
    for(i=1;i<=N;i++)
        count[A[i]]+=1;
    for(i=1;i<=k;i++)
        count[i]+=count[i-1];
    for(i=N;i>=1;i--)
    {
        B[count[A[i]]]=A[i];
        count[A[i]]-=1;
    }
    for(i=1;i<=N;i++)
        A[i]=B[i];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,j;
        long int N,M,k=0;
        scanf("%ld%ld",&N,&M);
        long int A[M];
        for(i=1;i<=M;i++)
            {
                scanf("%ld",&*(A+i));
                if(k<A[i])
                    k=A[i];
            }
        long int space=0,temp=0,count=0;
        space=M-1;
        countsort(A,k,M);
        i=1;
        while(space!=0)
        {
            if(A[i]<space)
            {
                space=space-(A[i]+1);
                count=count+A[i];
            }
            else if(A[i]==space)
            {
                count+=space;
                space=0;
            }
            else if(A[i]>space)
            {
                count+=space;
                space=0;
            }
            i++;
        }

        printf("%ld\n",count);
    }
    return 0;
}
