#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int x,y,t,a;
	cin>>t;
	while(t--)
	{
		cin>>x;
		cin>>y;
		if(x==y  || y==x-2)
		{
			if(x%2)
			{
				a=x+y-1;
			}
			else
			a=x+y;
			cout<<a<<endl;
		}
	    else
	    cout<<"No Number\n";
		
	}

return 0;
}
