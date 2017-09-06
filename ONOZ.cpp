#include<iostream>
using namespace std;
bool check(int x, int y)
{
    int dig = x%10;
    if(x==0 || y==0)
        if(x!=y)
            return 0;
    while(x)
    {
        if(dig!=(x%10))
            return 0;
        x/=10;
    }
    while(y)
    {
        if(dig!=(y%10))
            return 0;
        y/=10;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int H,M,count=0,i,j;
        cin>>H>>M;
        for(i=0;i<H;i++)
            for(j=0;j<M;j++)
            {
                if(check(i,j))
                    count++;
            }
            cout<<count<<endl;
    }
    return 0;
}
