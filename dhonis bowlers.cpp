#include <iostream>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	int num=n%10;
	n=n/10;
	num=(n%10)*10+num;
	int check1=sqrt(num);
	float check2=sqrt(num);
	if(check1==check2)
	{
	    num=sqrt(num);
		check1=sqrt(num);
		check2=sqrt(num);
		if(check1==check2)
		cout<<"1\n";
		else cout<<"-1\n";
	}
	else cout<<"-1\n";
	return 0;
}
