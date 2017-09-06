/*input
35 99999989 59741983
3127 99999989 26701892
3455 99999989 77111972
3841 99999989 89009070
3649 99999989 5577092
2187 99999989 23476925
2197 99999989 63406970
2401 99999989 83185785
2048 99999989 15584407
3721 99999989 26328001
2520 99999989 75961730
1680 99999989 85871698
1260 99999989 3323612
3780 99999989 78829442
3660 99999989 78702571
110880 99999989 32015903
83160 99999989 26845952
150000 99999989 90741384
149993 99999989 77982021
146160 99999989 73149428
*/
#include <iostream>
using namespace std;
#define size1 150000
long long N,MOD;
long long ans,temp;
int prime[size1+15],i,j;

void sieve()
{
	int size = N + 10;
	for(i=0;i<=size;i++)
		prime[i] = 0;
	prime[0]=1;
	prime[1]=1;
	for(i=2;i*i<=size;i++)
	{
		if(!prime[i])
		{
			j = i*i;
			while(j<=size)
			{
				prime[j]=1;
				j+=i;
			}
		}
	}
	for(i=2;i*i<=size;i++)
	{
		if(prime[i]==0)
		{
			j = i*i;
			while(j<=size)
			{
				prime[j]=i;
				j*=i;
			}
		}
	}
}

long long power(long long a, long long b)
{
    long long temp1;
    if( b==0 )
        return 1;
    temp1 = power(a,b/2);
    if( b%2==0 )
        return ( temp1%MOD * temp1%MOD ) %MOD;
    else
        return (temp1%MOD  *  temp1%MOD  * a%MOD ) %MOD;
}

void find_prime_factors()
{
	int size = N;
	int temp2 = N;
	int count = 0;
	ans = 0;
	for(i=2;i*i<=size;i++)
	{
		if(prime[i]==0 && temp2!=0 && temp2%i==0)
		{
			while(temp2%i==0)
				temp2/=i;
			ans = (ans%MOD + power(2,i)%MOD)%MOD;
			//cout<<"i :"<<i<<" ";
			count++; 
		}
		if(temp2==0)
			break;
	}
	if(temp2>0)
	{
		if(prime[temp2]==0)
			ans = (ans%MOD + power(2,temp2)%MOD)%MOD;
		//cout<<"temp2: "<<temp2<<" ";
		//cout<<ans<<endl;
	}
	ans = (ans%MOD - (2*count)%MOD)%MOD;
	//cout<<ans<<endl;
	//cout<<power(2,N)%MOD;
	if(ans<0)
		ans = ans+MOD;
	ans = (power(2,N)%MOD - ans%MOD)%MOD;
	if(ans<0)
		ans = ans + MOD;
}

int main()
{
	int t=20,p=0,out;
while(t--)
{	
	cout<<endl<<endl;
	cout<<"T: "<<p++<<endl;;
	cin>>N>>MOD>>out;
	sieve();/*
	for(i=0;i<=N;i++)
		cout<<prime[i]<<" ";*/
	cout<<"N: "<<N<<endl;
	if(N==1)
		ans = 2;
	else if(N%2==0)
	{
		if(prime[N]==0)
		{
			cout<<"prime number: "<<endl;
			ans = (power(2,N)%MOD - 2%MOD)%MOD;
		}
		else if(prime[prime[N]]==0)
		{
			cout<<"power of prime number: "<<endl;
			temp =	prime[N];
			cout<<"temp: "<<temp<<endl;
			cout<<power(2,N)<<endl;
			ans = (power(2,N)%MOD - power(2,temp)%MOD)%MOD;
		}
		else if(prime[N]==1)
		{
			cout<<"product of prime number: "<<endl;
			find_prime_factors();
		}
	}
	else
	{
		cout<<"even number: "<<endl;
		cout<<power(2,N)<<endl;
		ans = (power(2,N)%MOD + power(2,N/2)%MOD)%MOD;
		if(ans<0)
			ans+=MOD;
	}
	//cout<<ans<<endl;
	ans=ans%MOD;
	if(ans<0)
		ans+=MOD;
	cout<<"ans: "<<ans<<endl;
	cout<<"out: "<<out<<endl;
	}
}