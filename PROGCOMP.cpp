/*input
3
aba
aaa
abc
*/
#include <iostream>
#define max_size 100001
#define MOD	1000000007
using namespace std;

long long fact[max_size],i,ans;
short int t,team;
string s;
long alpha[30];

void factorial()
{
	fact[0] = 1;
	for(i=1;i<=max_size-1;++i)
		fact[i] = (i%MOD * fact[i-1]%MOD)%MOD;
}

int main()
{	
	ios_base::sync_with_stdio(0);
	factorial();
	cin>>t;
	while(t--)
	{	
		team = 0;
		ans  = 1;
		for(i=0;i<30;++i)
			alpha[i] = 0;
		cin>>s;
		for(i=0;i<s.length();++i)
			++alpha[s[i]-'a'];
		for(i=0;i<30;++i)
			if(alpha[i])
				++team;
		ans = (ans%MOD * fact[team]%MOD)%MOD;
		for(i=0;i<30;++i)
			if(alpha[i])
				ans = (ans%MOD * fact[alpha[i]]%MOD)%MOD;
		cout<<ans<<endl;
	}
}