#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j,carry=0;
        cin>>n;
        int A[200]={1},k=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=k;j++)
            {
                A[j]=A[j]*i+carry;
                carry=A[j]/10;
                A[j]=A[j]%10;
            }
            while(carry)
            {
                k++;
                A[k]=carry%10;
                carry/=10;
            }

        }

            for(j=k;j>=0;j--)
            {
                cout<<A[j];
            }
            cout<<"\n";
    }
return 0;
}
