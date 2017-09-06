/*input
4 11
*/
#include <iostream>
using namespace std;

long N,M,A,i;
int check;

int main()
{
	check=0;
	cin>>N>>M;
	if((2*M)%N!=0)
		check=2;
	for(i=1;i<=100;i++)
	{
		if(check==2)
			break;
		A = ((2*M)/N) - (N-1)*i;
		if(A>=2 && A<=200 && A%2==0)
			check = 1;
	}
	if(check==1)
		cout<<"possible";
	else
		cout<<"impossible";
	cout<<endl;
}