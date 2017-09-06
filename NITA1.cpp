#include<iostream>
using namespace std;
int cal(char s[101][101],int i,int j,int N)
{
    if(i<0 || j<0 || i==N || j==N)
        return 0;
    if(s[i][j]=='S')
    {
        s[i][j]='.';
        cal(s,i,j,N);
    }
    if(s[i+1][j]=='S')
    {
        s[i+1][j]='.';
        cal(s,i+1,j,N);
    }
    if(s[i][j+1]=='S')
    {
        s[i][j+1]='.';
        cal(s,i,j+1,N);
    }
    if(s[i-1][j]=='S')
    {
        s[i-1][j]='.';
        cal(s,i-1,j,N);
    }
    if(s[i][j-1]=='S')
    {
        s[i][j-1]='.';
        cal(s,i,j-1,N);
    }
    if(s[i-1][j-1]=='S')
    {
        s[i-1][j-1]='.';
        cal(s,i-1,j-1,N);
    }
    if(s[i-1][j+1]=='S')
    {
        s[i-1][j+1]='.';
        cal(s,i-1,j+1,N);
    }
    if(s[i+1][j-1]=='S')
    {
        s[i+1][j-1]='.';
        cal(s,i+1,j-1,N);
    }
    if(s[i+1][j+1]=='S')
    {
        s[i+1][j+1]='.';
        cal(s,i+1,j+1,N);
    }
    return 0;
}
int main()
{
    int t,i,j;
        char s[101][101];
    cin>>t;
    while(t--)
    {
        static int N;
        static int count;
        count=0;
        cin>>N;
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                cin>>s[i][j];
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
            {
                if(s[i][j]=='S')
                {
                    count++;
                    cal(s,i,j,N);
                }
            }
        if(count%2)
            cout<<"Alice\n";
        else
            cout<<"Bob\n";
    }
}
