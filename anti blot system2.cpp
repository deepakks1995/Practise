#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<"\n";
        //defining variable
        int k1=0,k2=0,k3=0,k4=0,n1=0,n2=0,n3=0,l1,l2,l3,i,j;
        string str1, str2, str3, in,in2;
        cin>>str1;
        cin>>in;
        cin>>str2;
        cin>>in2;
        cin>>str3;
        l1=str1.length();
        l2=str2.length();
        l3=str3.length();
        // checking for string
        for(i=0;i<l1;i++)
        {
            if(str1[i]==109)
                k1=1;
        }
        for(i=0;i<l2;i++)
        {
            if(str2[i]==109)
                k2=1;
        }
        for(i=0;i<l3;i++)
        {
            if(str3[i]==109)
                k3=1;
        }
        if(k1==1)
        {
            n2=0;
            n3=0;
            for(i=0;i<l2;i++)
            {
                n2=10*n2+str2[i]-48;
            }
            for(i=0;i<l3;i++)
            {
                n3=10*n3+str3[i]-48;
            }
            cout<<n3-n2<<" "<<in<<" "<<str2<<" "<<in2<<" "<<str3;
        }
        if(k2==1)
        {
            n1=0;
            n3=0;
            for(i=0;i<l1;i++)
            {
                n1=10*n1+str1[i]-48;
            }
            for(i=0;i<l3;i++)
            {
                n3=10*n3+str3[i]-48;
            }
            cout<<str1<<" "<<in<<" "<<n3-n1<<" "<<in2<<" "<<str3;
        }
        if(k3==1)
        {
            n1=0;
            n2=0;
            for(i=0;i<l1;i++)
            {
                n1=10*n1+str1[i]-48;
            }
            for(i=0;i<l2;i++)
            {
                n2=10*n2+str2[i]-48;
            }
            cout<<str1<<" "<<in<<" "<<str2<<" "<<in2<<" "<<n1+n2;
        }
    }
    return 0;
}
