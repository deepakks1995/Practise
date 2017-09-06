#include<iostream>
using namespace std;
int main()
{
    int N,i,sum,x,y,Q,ans;
    int A[100005][2],colsum[100005]={0};
    cin>>N;
    colsum[0]=0;
    sum=0;
    for(i=1;i<=N;i++)
    {
        cin>>A[i][0];
        cin>>A[i][1];
        sum += A[i][1] - A[i][0] + 1;
        colsum[A[i][0]]++;
        colsum[A[i][1]+1]--;
    }
    for(i=1;i<=N;i++)
        colsum[i] += colsum[i-1];
    cin>>Q;
    for(i=0;i<Q;i++)
    {
        cin>>x>>y;
        ans = sum - (A[x][1] - A[x][0] + 1 ) - colsum[y];
        if( y >= A[x][0]  &&  y <= A[x][1])
            ans++;
        if(ans%2==0)
            cout<<"E\n";
        else
            cout<<"O\n";
    }
    return 0;
}
