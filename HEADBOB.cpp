#include<iostream>
#include<cstdio>
//#define ONLINE_JUDGE
long solve(long B)
{
    if(B==1 || B==2 || B==3)
        return 0;
    else
        return (B-2)/2 + solve(B-2);
}
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE

    int t,i,N,count;
    cin>>t;
    while(t--)
    {
        count=0;
        cin>>N;
        while(N!=0)
        {
            i=N%10;
            N/=10;
            if(i==4)
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
