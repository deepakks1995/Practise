#include<iostream>
#include<malloc.h>
#include<algorithm>
using namespace std;
void print(long int *a,long int n)
{
    for(long int i=0;i<n;i++)
    {
        cout<<a[i];
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=0;
        cout<<"\n";
        cin>>n;
        long int A[n],*left,*right;
        long int i,j,l;
        l=static_cast<long int>(n)/2;
        left=(long *)(malloc(sizeof(long int)*(l)));
        right=(long *)(malloc(sizeof(long int)*(n-l)));
        for(i=0;i<n;i++)
        {
            cin>>A[i];
        }
        for(i=0;i<l;i++)
        {
            left[i]=A[i];
        }
        for(i=l,j=0;i<n;i++,j++)
        {
            right[j]=A[i];
        }
        //inversion count
        int count=0;
        for(i=0;i<l;i++)
        {
            for(j=i+1;j<l;j++)
            {
                if(left[i]>left[j])
                    count++;
            }
        }
        sort(left,left+l);
       /* print(left,l);
        cout<<endl;*/
        for(i=0;i<n-l;i++)
        {
            for(j=i+1;j<n-l;j++)
            {
                if(right[i]>right[j])
                    count++;
            }
        }
        sort(right,right+n-l);
       /* print(right,n-l);
        cout<<endl;*/
        long int st=0,en=0;
       //counting merge arrays
       int count1=0;
       a:
           long int k,m;
        for(i=st;i<l;i++)
        {
            for(j=n-l-1;j>=en;j--)
            {
                if(left[i]>right[j])
                {
                    count1+=(l-i)*(j+1-en);
                    st=i+1;
                    en=j+1;
                    if(st<=l)
                        goto a;
                    else
                        goto b;
                }

            }
        }
        b:
        cout<<count1+count<<"\n";

    }
    return 0;
}
