#include<iostream>
#include<string>
using namespace std;
int func(int n, int &q, int &r)
{
    q=n/10;
    r=n%10;
}
int fun(int n,int d,int &q,int &r)
{
    q=n/d;
    r=n%d;
}
int main()
{
    int t=1;
    long int n;
    int a[250]={0};
    int i,j,l;
    cin>>n;
    string s[n];
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    l=s[0].length();
    for(i=0,j=l-1;i<l;i++,j--)
    {
        a[i]=s[0][j]-48;
    }
    cout<<endl;
    // addition
    int la=i,c=0;
   for(i=1;i<n;i++)
    {
        l=s[i].length();
        if(la>l)
        {
            for(j=0;l-1>=0;j++,l--)
            {
                if(a[j]+s[i][l-1]-48+c<=9)
                {
                    a[j]=a[j]+s[i][l-1]-48+c;
                    c=0;
                }
                else
                {
                    func(a[j]+s[i][l-1]-48,c,a[j]);
                }
            }
            for(;j<la;j++)
            {
                if(a[j]+c<=9)
                {
                    a[j]=a[j]+c;
                    c=0;
                }
                else
                    func(a[j]+c,c,a[j]);
            }
        }
        else
        {
            for(j=0;j<la;j++,l--)
            {
                if(a[j]+s[i][l-1]+c-48<=9)
                {
                    a[j]=a[j]+s[i][l-1]-48+c;
                    c=0;
                }
                else
                {
                    func(a[j]+s[i][l-1]-48,c,a[j]);
                }
            }
            for(;j<l;j++)
            {
                if(a[j]+c<=9)
                {
                    a[j]=a[j]+c;
                    c=0;
                }
                else
                    func(a[j]+c,c,a[j]);
            }
            la=l;
        }
    }cout<<endl;
    for(i=0;i<la;i++)
    {
        cout<<a[i];
    }

return 0;
}
