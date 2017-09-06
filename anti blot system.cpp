#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int add(int n, int &q, int &r)
{
    q=n/10;
    r=n%10;
}
int main()
{
    int t,i=0,j=0;
    cin>>t;
    while(t--)
    {
        cout<<"\n";
        //defining variable
        int k1=0,k2=0,k3=0,k4=0;
        string str1, str2, str3, in,in2,st1;
        cin>>str1;
        cin>>in;
        cin>>str2;
        cin>>in2;
        cin>>str3;
        int l1,l2,l3;
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
            int a1[l3],a2[l2],a3[l3];
            // reversing arrays
            for(i=l2-1,j=0;i>=0;i--,j++)
            {
                a2[i]=str2[j]-48;
            }
            for(i=l3-1,j=0;i>=0;i--,j++)
            {
                a3[i]=str3[j]-48;
            }
            //subtracting arrays
            for(i=0;i<l2;i++)
            {
                if(a2[i]>a3[i])
                {
                    str1[i]=10+a3[i]-a2[i];
                    a3[i+1]=a3[i+1]-1;
                }
                else
                {
                    str1[i]=a3[i]-a2[i];
                }
            }
            for(;i<l3;i++)
            {
                str1[i]=a3[i];
            }
            if(!str1[l3-1])
            {
                l3--;
            }
            for(j=i;j>=0;j++)
            {
                cout<<a1[j];
            }
        }
}
}
