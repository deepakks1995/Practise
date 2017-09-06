#include<iostream>
using namespace std;

int main()
{
    int r,c,i,j;
    cin>>r>>c;
    long long int A[r+1][c+1],ans;
    for(i=0;i<=c;i++)
        A[0][i]=0;
    for(i=0;i<=r;i++)
        A[i][0]=99999999;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            cin>>A[i][j];
            if(A[i][j]>A[0][j])
                A[0][j]=A[i][j];
            if(A[i][j]<A[i][0])
                A[i][0]=A[i][j];
        }
    }
    bool flag=0;
    /*for(i=0;i<=r;i++)
    {
        for(j=0;j<=c;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }*/
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(A[i][j]==A[i][0])
            {
                if(A[i][j]==A[0][j])
                {
                    flag=1;
                    ans=A[i][j];
                }
            }
            if(flag)
                break;
        }
        if(flag)
            break;
    }
    if(flag)
        cout<<ans<<endl;
    else
        cout<<"GUESS"<<endl;
    return 0;
}
