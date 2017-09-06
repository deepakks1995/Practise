#include<iostream>

#include<algorithm>

#include<cmath>

using namespace std;

bool myfunction (int i,int j)

{

	return (i>j);

}

int main()

{

	std::ios::sync_with_stdio(false);

	long long int t,i,/*a[100010],*/ans,x,j/*,b[200010]*/,n,k,m,k1;

	cin>>t;

	for(i=0;i<t;i++)

	{

		ans=0;

		cin>>n>>k>>m;
		long long int a[n],b[k+m];

		for(j=0;j<n;j++)

		{

			cin>>a[j];

		}

		for(j=0;j<n;j++)

		{

			cin>>x;

			a[j]-=x;

			if(a[j]<0)

				a[j]*=-1;

			ans+=a[j];

		}

		sort(a,a+n,myfunction);

		for(j=0;j<k+m;j++)

		{

			cin>>b[j];

		}

		sort(b,b+k+m,myfunction);

		k1=0;

		for(j=0;j<n&&k1<k+m;j++)

		{

			for(;k1<k+m;k1++)

			{

				if(a[j]>=b[k1])

				{

					ans-=b[k1];

					k1++;

					break;

				}

			}

		}

		cout<<ans<<endl;

	}

	return 0;

}
