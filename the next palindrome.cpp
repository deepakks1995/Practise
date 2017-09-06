#include<iostream>
#include<string>
#include<string.h>
using namespace std;
void func(int n, int &q, int &r)
{
    q=n/10;
    r=n%10;
}
int check(int x[1000000],long int l)
{

    int i,j,k=0;
    for(i=0,j=l-1;i<l;i++,j--)
    {
        if(x[i]=x[j])
            k=1;

    }
    return k;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int l;
        string a;
        cin>>a;
        int i,k=0,j,c=0;
        l=a.length();
        int x[l];
        for(i=0,j=l-1;i<l;i++,j--)
        {
            x[i]=a[j]-48;
        }

while(k!=1)
{
            // addition
            k=0;
            c=0;
            if(x[0]+1<=9)
            {
                x[0]=x[0]+1;
            }
            else
            func(x[0]+1,c,x[0]);
            for(i=1;i<l;i++)
            {
                if(c+x[i]<=9)
                {
                    x[i]=c+x[i];
                    c=0;
                }
                else func(c+x[i],c,x[i]);
            }
            // checking whter palin or not
            k=check(x,l);
            if(k==1)
            {
                for(i=l-1;i>=0;i++)
                {
                    cout<<x[i];
                }
            }


    }

    }
    return 0;
}
