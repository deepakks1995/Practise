#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    int t,i,j;
    cin>>t;
    long long A[50001];
    while(t--)
    {
        long count=0;
        long N;
        cin>>N;
        for(i=0;i<N;i++)
            cin>>A[i];
        sort(A,A+N);
        int flag=0;
        /*for(i=0;i<N;i++)
            cout<<A[i]<<" ";
        cout<<endl;*/
        i=0;j=N-1;
        int num=N;
        while(num>0 && i<=N-1)
        {
            if(A[i]!=A[j] && A[i]!=-1 && A[j]!=-1)
            {
                A[i]=A[j]=-1;
                num--;
                num--;
            }
            if(A[i]==A[j] && A[i]!=-1 && A[j]!=-1)
                i++;

            if(A[i]==-1)
                i++;
            if(A[j]==-1)
                j--;
                count++;
        }
        for(i=0;i<N;i++)
            if(A[i]!=-1)
                count++;
        cout<<count<<endl;
    }
}
