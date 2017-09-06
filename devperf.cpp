/*
input
1
2 2
*.
..
*/
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long int N,M,i,j,count=0;
        cin>>N>>M;
        string s;
        long int mini=N+1,minj=M+1,maxi=-1,maxj=-1;
        for(i=0;i<N;i++)
        {
            cin>>s;
            for(j=0;j<M;j++)
            {
                if(s[j]=='*')
                {
                    if(mini>i)
                        mini=i;
                    if(maxi<i)
                        maxi=i;
                    if(minj>j)
                        minj=j;
                    if(maxj<j)
                        maxj=j;
                        count++;
                }
            }
        }
        long int ans=0;
        ans=((maxi-mini)>=(maxj-minj) ? (maxi-mini): (maxj-minj));

        ans = (ans%2==1 ? ((1+ans)/2) : ans/2);
        if(count)
            cout<<ans+1<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0;
}
