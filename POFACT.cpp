#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    long long arr[100001]={1},MOD=1589540031,i,N;
    for(i=1;i<100001;i++)
        arr[i] = (arr[i-1] * i)%MOD;
    while(t--)
    {
        cin>>N;
        cout<<arr[N]<<endl;
    }
}
