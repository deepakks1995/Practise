#include<iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
using namespace std;
int reverse(int a)
    { int r=0;
    for(;a!=0;)
        {
            r=r*10;
		    r=r+a%10; 
			a=a/10;
        }
        return r;
    }
int main()
{
	int n,i,a,b,c;
	cin>>n;
	int p[1000];
	for(i=0;i<n;i++)
	{
		cin>>a;
		cin>>b;
		a=reverse(a);
		b=reverse(b);
		c=a+b;
		c=reverse(c);
		p[i]=c;
	}
	for(i=0;i<n;i++)
	{
		cout<<p<<endl;
	}
	return 0;
}
