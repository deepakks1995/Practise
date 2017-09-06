#include<iostream>
using namespace std;
int main()
{
    int t,i,j;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s[2][n];
        for(i=0;i<n;i++)
        {
            cin>>s[0][i];
            for(j=0;j<3;j++)
                s[1][i][j]=s[0][i][s[0][i].length()-1-j];
        }
        for(i=0;i<n;i++)
            cout<<s[1][i]<<" ";
    }
}
