#include<iostream>
#include<cmath>
#include<malloc.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    long long int t,i;

    long long int fib[1000000];
    fib[0]=1;
    fib[1]=1;
    for(i=2;i<1000000;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }

    long long int *nfib= (long long int *) calloc(1000000000,sizeof(long long int));
    for(i=0;i<1000000000;i++)
    {
        nfib[fib[i]]=1;
    }

    cin>>t;
    while(t--)
    {
        i=0;
        long long int x,c=0;
        cin>>x;
        while(c!=x)
        {
            if(nfib[i]==0)
            {
                c++;
                i++;
            }
            else i++;
        }
        cout<<nfib[i]<<endl;
    }
    return 0;
}
