#include<iostream>
#include<cmath>

using namespace std;
/* Function to calculate x raised to the power y in O(logn)*/
long long int power(long long int x, unsigned int y)
{
    long long int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
int main(void)
{
    long int t;
    long long int N;
    long long int x,y;
    long long int x0,y0;
    long long int x1,y1;
    long long int ans= 0;
    long long int i = 1;
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>N;
        cin>>x0>>y0;
        cin>>x1>>y1;
        long long int m1,m2,m3;
        N = N-2;
        while(N--)
        {
            cin>>x>>y;
            m1 = (power(x1-x0,2)+power(y1-y0,2));
            m2 = (power(x-x1,2)+power(y-y1,2));
            m3 = (power(x-x0,2)+power(y-y0,2));
            if(m1 + m2 == m3)
            {
                ans++;
            }
            x0 = x1;
            y0 = y1;
            x1 = x;
            y1 = y;
        }
        cout<<ans<<endl;
    }
    return 0;
}
