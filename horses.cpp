#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int i;
        long int n;
        cin>>n;
        long int S[n];
        for(i=0;i<n;i++)
            cin>>S[i];
        sort(S,S+n);
        int min=S[1]-S[0];
        for(i=1;i<n-1;i++)
        {
            if(min>S[i+1]-S[i])
                min=S[i+1]-S[i];
        }
        cout<<min<<endl;
    }
}
