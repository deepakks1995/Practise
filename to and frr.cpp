#include<iostream>
#include<string>
using namespace std;
int main()
{
    int col,row,pos,temp,i,n,j;
    string s;
    cin>>col;
    while(col!=0)
    {
    cin>>s;
    row=s.length();
    row=row/col;
    char a[row][col];
    for(i=0;i<row;i++)
    {
        pos=col*i;
        n=pos/col;
        if(n%2==0)
            {
                temp=pos;
                for(j=0;j<col;j++)
                {
                    a[i][j]=s[temp];
                    temp++;
                }
            }
            else if(n%2!=0)
            {
                temp=pos+col-1;
                for(j=0;j<col;j++)
                {
                   a[i][j]=s[temp];
                   temp--;
                }
            }
    }
    for(i=0;i<col;i++)
    {
        for(j=0;j<row;j++)
        {
            cout<<a[j][i];
        }
    }
    cout<<endl;
    cin>>col;
    }
    return 0;
}
