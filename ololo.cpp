#include<iostream>
#include<malloc.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *A=NULL;
    A=(int*)malloc(sizeof(int)*n);
    int check=0;
    int ans1=0,i,j,l=n/2,r=(n-l);
    int B[l],C[r];
    for(i=0;i<n;i++)
        cin>>A[i];
    for(i=0;i<l;i++)
        B[i]=A[i];
    for(j=0;j<r;j++,i++)
        C[j]=A[i];

      for(i=0;i<l;i++)
    {
        for(int j=i+1;j<l;j++)
        {
            if(B[i]!=B[j])
            {
                check=1;
                ans1=i;
            }
            else check=0;
        }
    }
    check=0;
    int ans2=0;
      for(i=0;i<r;i++)
    {
        for(int j=i+1;j<r;j++)
        {
            if(C[i]!=C[j])
            {
                check=1;
                ans2=i;
            }
            else check=0;
        }
    }
    cout<<ans1<<ans2;
}
