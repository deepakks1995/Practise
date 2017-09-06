#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int A[110],B[110];
int X[110],Y[110];
int K[110],N[110];
void func(int n, int &q, int &r)
{
     r=n%10;
    q=n/10;
}
void fun(int n, int &q, int &r)
{
    q=n/2;
    r=n%2;
}
int main()
{
    int t=10;
    while(t--)
    {
        char total[110], more[110];
        cin>>total;
        cin>>more;
        int t= strlen(total);
        int m= strlen(more);
        if(t>=101 || m>=101)
            break;
        else
        {
        int i=0,j=0,c=0;
 // inverting arrays
        for(i=0,j=t-1;i<t;i++,j--)
        {
            A[i]=total[j]-48;
        }
        for(i=0,j=m-1;i<m;i++,j--)
        {
            B[i]=more[j]-48;
        }
 // adding both the arrays
        for(i=0;i<m;i++)
        {
            if(c+A[i]+B[i]<=9)
            {
                X[i]=A[i]+B[i]+c;
                c=0;
            }
            else
            {
                func(c+A[i]+B[i],c,X[i]);
            }
        }
        for(;i<t;i++)
        {
            if(A[i]+c<=9)
            {X[i]=A[i]+c;
            c=0;
            }
            else
            {
                func(c+A[i],c,X[i]);
            }
        }
 // dividing the added arrays
        c=0;
        for(i=t-1;i>=0;i--)
        {
            fun(10*c+X[i],X[i],c);
            if(!X[t-1])
                {
                    t--;
                }
        }
         t= strlen(total);
         m= strlen(more);
  // Subtraction
        for(i=0;i<m;i++)
        {
            if(B[i]>A[i])
            {
                Y[i]=10+A[i]-B[i];
                A[i+1]=A[i+1]-1;
            }
            else
            {
                Y[i]=A[i]-B[i];
            }
        }
        for(;i<t;i++)
        {
            Y[i]=A[i];
        }
        if(!Y[t-1])
        {
            t--;
        }
// Dividing Arrays
        c=0;
        for(i=t-1;i>=0;i--)
        {
            fun(10*c+Y[i],Y[i],c);
            if(!Y[t-1])
            {
                t--;
            }
        }
        if(!Y[t-1])
        {
            t--;
        }
 // printing output
        for(i=0,j=t-1;i<t;i++,j--)
        {
            K[i]=X[j];
            N[i]=Y[j];
        }
        for(i=0;i<t;i++)
        {
            cout<<K[i];
        }
        cout<<endl;
        for(i=0;i<t;i++)
        {
            cout<<N[i];
        }
        cout<<endl;
        }
    }
        return 0;
}



