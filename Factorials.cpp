#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int zero(int a)
{
	int c=0;
	for(int i=5;a/i>=1; i *=5)
		c+=a/i;
	return c;	
}
int main()
{
	int i,n,a,b;
	cin>>n;
	int p[n];
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(a>=1  &&  a<=1000000000)
	{
		b=zero(a);
		p[i]=b;
	}
	}
	for(i=0;i<n;i++)
	{
		cout<<p[i]<<endl;
	}
	return 0;
}
	
	
	
	
	

