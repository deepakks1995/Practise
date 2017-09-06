#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    long NUM = 100004;
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    long arr[NUM],i,j;
    long long sum;
    arr[1] = 1;
    //cout<<endl;
    for(i=2;i<=NUM;i++)
    {
        sum = 0;
        //cout<<"For : i= "<<i<<"  ";
        for(j=1;j*j<=i;j++)
        {
            if(!(i%j))
            {
                if(j%2)
                {
                    sum += j;
                   // cout<<j<<" ";
                }
                if(j*j!=i && (i/j)%2 )
                {
                    sum += (i/j);
                   // cout<<i/j<<" ";
                }
            }
        }
        //cout<<endl;
        arr[i] = sum;
    }
    while(t--)
    {
        cin>>NUM>>j;
        sum = 0;
        for(i=NUM;i<=j;i++)
            sum += arr[i];
        cout<<sum<<endl;

    }

}
