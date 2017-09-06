/*
*   User_Id @deepakks1995
*
*   Problem_Code @AlTARAY
*
*/

#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;
    long N,count,i,j,B[2][100000],index;
    long long A[100000];
    while(t--)
    {
        index=0;
        cin>>N;
        for(i=0; i<N; i++)
            cin>>A[i];
        int first=0;
        for(i=1; i<N; i++)
        {
            if(A[i]*A[i-1]<0)
            {
                first++;
                if(first==1)
                    B[0][index]=i-1;
            }
            else
            {
                if(first)
                {
                    B[1][index]=i-1;
                    ++index;
                }
                first=0;
            }
        }
        if(first)
        {
            B[1][index]=i-1;
            index++;
        }
        count=0;
        for(i=0; i<N; i++)
        {
            if(i==B[0][count] && count<index)
                cout<<B[1][count]-i+1<<" ";
            else if(i<=B[1][count] && i>B[0][count] && count<index)
                cout<<B[1][count]-i+1<<" ";
            else if(i>B[1][count] && count<index)
            {
                count++;
                if(i<B[0][count] && count<index)
                    cout<<"1 ";
                else if(i==B[0][count] && count<index)
                    cout<<B[1][count]-i+1<<" ";
                else
                    cout<<"1 ";
            }
            else cout<<"1 ";
        }
        cout<<endl;
    }
    return 0;
}
