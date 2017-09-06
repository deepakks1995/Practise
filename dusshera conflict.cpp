#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int c,n;
    cin>>c>>n;
    while(c && n)
    {
        int A[n];
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            sum+=A[i];
        }
        //qsort(A,n,sizeof(int),cmp);
        bool flag=0;
        if(sum%c==0)
            flag=1;
        else
    }
}
