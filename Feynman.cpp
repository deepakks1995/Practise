#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i,j,k;
while(1)
	{
		cin>>n;
		if(n!=0)
		{ 
		j=1;
		k=0;
		for(i=0;i<n;i++)
		{
			k=k+pow(j,2);
			j++;
			
		}
		cout<<k<<endl;
	   }
	   else break;
	   
    }
    return 0;
}
