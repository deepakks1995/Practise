#include<iostream>
using namespace std;
inline int max(long long int a,long long int b)
{
    return (a>b)?a:b;
}
int main()
{
    long long int n,k,i,j;
    cin>>n;
    long long int A[n];
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cin>>k;
    long long int max1=0;
    for(i=0;i<n-k+1;i++)
    {
        max1=A[i];
        for(j=0;j<k;j++)
        {
            max1=max(count,A[i+j]);
        }
        cout<<max1;
    }
    return 0;

}
