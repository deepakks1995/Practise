#include<iostream>
#include<string>
using namespace std;
int coun(int n)
{
    int coun=0;
    while(n!=0)
    {
        n/=10;
        coun++;
    }
    return coun;
}
int main()
{
    /*string A,B,C;
    cin>>A>>C>>B;
    int l,m;
    l=A.length();
    m=B.length();
    long long int a=0,b=0;
    for(int i=0;i<l;i++)
    {
        a=10*a+A[i]-48;
    }
    for(int i=0;i<m;i++)
    {
        b=10*b+B[i]-48;
    }
    if(C[0]=='+')
    {*/
       // int x=a+b;
    long long int i=0,x;
        cin>>x;
        int X[200]={0};
        int c=coun(x);
        for(i=0;i<c;i++)
        {
            X[i]=x%10;
            x/=10;
        }
                        //checking for 0
       int count=0;
        int c0=0;
        for(i=0;i<c;i++)
        {
            if(X[i]==0)
                {++count;
                c0=1;}
        }
        int k0=count;
        //checking for 1
         count=0;
         int c1=0;
        for(i=0;i<c;i++)
        {
            if(X[i]==1)
                {
                    ++count;
                c1=1;}
        }
        int k1=count;
        //checking for 2
        count=0;
        int c2=0;
        for(i=0;i<c;i++)
        {
            if(X[i]==2)
                {
                    ++count;
                c2=1;
                }
        }
        int k2=count;
                //checking for 3
        count=0;
        int c3=0;
        for(i=0;i<c;i++)
        {
            if(X[i]==3)
                {++count;
                c3=1;}
        }
        int k3=count;
                //checking for 4
        count=0;
        int c4=0;
        for(i=0;i<c;i++)
        {
            if(X[i]==4)
                {++count;
                c4=1;}
        }
        int k4=count;
                //checking for 5
        count=0;
        int c5=0;
        for(i=0;i<c;i++)
        {
            if(X[i]==5)
                {++count;
                c5=1;}
        }
        int k5=count;
                //checking for 6
        count=0;
        int c6=0;
        for(i=0;i<c;i++)
        {
            if(X[i]==6)
                {++count;
                c6=1;}
        }
        int k6=count;
                //checking for 7
        count=0;
        int c7=0;
        for(i=0;i<c;i++)
        {
            if(X[i]==7)
                {++count;
                c7=1;}
        }
        int k7=count;
                //checking for 8
        count=0;
        int c8=0;
        for(i=0;i<c;i++)
        {
            if(X[i]==8)
                {++count;
                c8=1;}
        }
        int k8=count;
                //checking for 9
        count=0;
        int c9=0;
        for(i=0;i<c;i++)
        {
            if(X[i]==9)
                {++count;
                c9=1;}
        }
        int k9=count;
        //printing the number
        if(c0==1)
        {
            if(k0>9)
            {
                cout<<"9"<<"0"<<k0-9<<"0";
            }
            else
                cout<<k0<<"0";
        }
        if(c1==1)
        {
            if(k1>9)
            {
                cout<<"9"<<"1"<<k1-9<<"1";
            }
            else
                cout<<k1<<"1";
        }
        if(c2==1)
        {
            if(k2>9)
            {
                cout<<"9"<<"2"<<k2-9<<"2";
            }
            else
                cout<<k2<<"2";
        }
        if(c3==1)
        {
            if(k3>9)
            {
                cout<<"9"<<"3"<<k3-9<<"3";
            }
            else
                cout<<k3<<"3";
        }
        if(c4==1)
        {
            if(k4>9)
            {
                cout<<"9"<<"4"<<k4-9<<"4";
            }
            else
                cout<<k4<<"4";
        }
        if(c5==1)
        {
            if(k5>9)
            {
                cout<<"9"<<"5"<<k5-9<<"5";
            }
            else
                cout<<k5<<"5";
        }
        if(c6==1)
        {
            if(k6>9)
            {
                cout<<"9"<<"6"<<k6-9<<"6";
            }
            else
                cout<<k6<<"6";
        }
        if(c7==1)
        {
            if(k7>9)
            {
                cout<<"9"<<"7"<<k7-9<<"7";
            }
            else
                cout<<k7<<"7";
        }
        if(c8==1)
        {
            if(k8>9)
            {
                cout<<"9"<<"8"<<k8-9<<"8";
            }
            else
                cout<<k8<<"8";
        }
        if(c9==1)
        {
            if(k9>9)
            {
                cout<<"9"<<"9"<<k9-9<<"9";
            }
            else
                cout<<k9<<"9";
        }


    }



//}
