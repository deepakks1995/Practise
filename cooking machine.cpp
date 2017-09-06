#include<iostream>
using namespace std;
int even(long int x)
{
    if(x%2==0)
        return 1;
    else return 0;
}
int calc(long int x)
{
    int count=0;
    if(x==1)
        return count;
    while(x>1)
    {
        x=x/2;
        count++;
    }
    return count;
}
int check(long int x)
{
    int c=0,chec=0;
    while(x>1)
    {
        chec=even(x);
        if(chec==1)
        {
            c=1;
            x=x/2;
        }
        else{
            c=0;
            goto a;
        }
    }
    a:
    return c;
}
int main()
{
    int t,count;
    cin>>t;
    while(t--)
    {
        count=0;
        long int a,b,c=0,chec=0;
        cin>>a>>b;
        if(a==b)
        {
            cout<<"0\n";
        }
        else if(a<b)
        {
            c=check(a);
            if(c==1)
            {
                cout<<calc(b)-calc(a)<<"\n";
            }
            else
            {
                chec=0;
                count=0;
                while(chec!=1 && a>1)
                {
                    if(even(a))
                    {
                        a=a/2;
                        chec=check(a);
                        ++count;
                    }
                    else
                    {
                        a=(a-1)/2;
                        chec=check(a);
                        ++count;
                    }
                }
                cout<<calc(b)+count-calc(a)<<"\n";
            }
        }
        else if(a>b)
        {
            chec=0;
            if(check(a))
            {
                cout<<calc(a)-calc(b)<<"\n";
            }
            else
            {
                count=0;
                while(chec!=1 && a>1)
                {
                    if(even(a))
                    {
                        a=a/2;
                        chec=check(a);
                        ++count;
                    }
                    else
                    {
                        a=(a-1)/2;
                        chec=check(a);
                        ++count;
                    }
                }
                if(chec==1)
            cout<<count+calc(b)-calc(a)<<"\n";
            else cout<<count-calc(b)+calc(a)<<"\n";
        }
        }
    }
    return 0;
}
