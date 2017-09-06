#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int N,i,j;
    long long max=-1000;
    cin>>N;
    int A[N][N],row,diag=0;
    int col[N];
    for(i=0;i<N;i++)
        col[i]=0;
    for(i=0;i<N;i++)
    {
        row=0;
        for(j=0;j<N;j++)
        {
            cin>>A[i][j];
            if(i==j)
                diag+=A[i][j];
            row+=A[i][j];
            col[j]+=A[i][j];

        }
        if(row>max)
            max=row;
        //cout<<"Row: "<<row<<endl;
    }
    if(diag>max)
        max=diag;
            //cout<<"Diag1: "<<diag<<endl;
    diag=0;
    for(i=0,j=N-1;i<N;i++,j--)
        diag+=A[i][j];
            //cout<<"Diag2: "<<diag<<endl;
    if(diag>max)
        max=diag;
    for(i=0;i<N;i++)
    {
               // cout<<"col: "<<col[i]<<endl;
        if(col[i]>max)
            max=col[i];
    }
    cout<<max<<endl;
}
