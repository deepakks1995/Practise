#include<iostream>
using namespace std;
int main()
{
    int t,i,j,k=0;
    cin>>t;
    while(t--)
    {
        int f,st,check=0;
        k++;
        cin>>st>>f;
        long int A[f];
        for(i=0;i<f;i++)
        {
            cin>>A[i];
            check=check+A[i];
        }
        if(check<st)
        {
            cout<<"Scenario #"<<k<<":\n";
            cout<<"impossible"<<"\n";
        }
         else
        {
        for(i=0;i<f-1;i++)
        {
            for(j=0;j<f-1-i;j++)
            {
                if(A[j]>A[j+1])
                {
                    int x=A[j];
                    A[j]=A[j+1];
                    A[j+1]=x;
                }
            }
        }
        check=0;
        int ct=0;
        for(i=f-1;i>=0;i--)
        {
            if(check<st)
            {
                check=check+A[i];
                ct++;
            }
            else break;
        }
        cout<<"Scenario #"<<k<<":\n";
        cout<<ct<<"\n";
    }
    }
}
