#include<iostream>
#include<malloc.h>
using namespace std;
long long int read()
{
    register int ch=getchar_unlocked();
    long long int temp=0;
    while(ch<'0' || ch >'9')
        ch=getchar_unlocked();
    while(ch>'0' && ch<'9')
    {
        temp=(temp<<3)+(temp<<1)+ch-'0';
        ch=getchar_unlocked();
    }
    return temp;
}
int main()
{
    long long int t;
    /*cin>>*/t=read();
    while(t--)
    {
        long long int n,i;
        /*cin>>*/n=read();
        long long int *A=(long long int *)calloc (n,sizeof(long long int));
        long long int sum=0,min,check=0;
            for(i=0; i<n; i++)
            {
                /*cin>>*/A[i]=read();
                if(i==0)
                    min=A[i];
                if(min>A[i])
                    min=A[i];
            }
            while(check!=n)
            {
            for(i=0; i<n; i++)
            {
                if(A[i]%min==0)
                {
                    A[i]=min;
                    check++;
                }
                else
                    A[i]=(A[i]%min);
            }
            for(i=0;i<n;i++)
            {
                if(A[i]>min)
                min=A[i];
            }
            }
            for(i=0;i<n;i++)
                sum+=A[i];
            cout<<sum<<endl;
            free(A);
        }
        return 0;
    }
