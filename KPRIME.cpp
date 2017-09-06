#include<iostream>
#include<string.h>
using namespace std;

int arr[100001]={0},counter[100001]={0},t;
long i,j,k=0,A,B,count;
int ans[100001][6]={0};
void sieve()
{
    for(i=2; i<=100000; i++)
    {
        if(arr[i]==0)
        {
            for(j=i;j<100001;j+=i)
            {
                arr[j]=1;
                counter[j]++;
            }
        }
    }
}
void cal_ans()
{
    for(i=2;i<=100000;i++)
    {
        for(j=1;j<=5;j++)
            ans[i][j]=ans[i-1][j];
        count=counter[i];
        ans[i][count]++;
    }
}
int main()
{
    sieve();
    cal_ans();

    cin>>t;

    while(t--)
    {
        count=0;
        cin>>A>>B>>k;
        int res = ans[B][k]-ans[A-1][k];
        cout<<res<<endl;
    }
    return 0;
}
