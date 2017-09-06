#include<iostream>
using namespace std;
int main()
{
    long int n=0;
    cin>>n;
    while(n!=0)
    {
        int A[n],B[n];
        int i=0,j,k=0;;
        for(i=0;i<n;i++)
        {
            cin>>A[i];
        }
        for(i=0;i<n;i++)
        {
            j=A[i];
            B[j-1]=i+1;
        }
        for(i=0;i<n;i++)
        {
            if(B[i]!=A[i])
                k=1;
        }
        if(k!=1)
        {
            cout<<"ambiguous\n";
        }
        else if(k==1)
            cout<<"not ambiguous\n";
        cin>>n;
    }
}
