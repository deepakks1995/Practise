#include<iostream>
#include<malloc.h>
#include<cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        long int N;
        cin>>N;
        char *ans;
        char *cans;
        long long int i,count=0,max=0;
        ans = (char *)calloc(N,sizeof(char));
        cans = (char *)calloc(N,sizeof(char));
        long long int *W = (long long int *) calloc(N+1,sizeof(long long int));
        //Reading
        for(i=0; i<N; i++)
            cin>>ans[i];
        count=0;
        for(i=0; i<N; i++)
        {
            cin>>cans[i];
            if(cans[i]==ans[i])
                count++;
        }
        for(i=0; i<N+1; i++)
            cin>>W[i];
            //calculations

        if(count!=N)
        {
            max=0;
            for(i=0; i<=count; i++)
            {
                if(max<=W[i])
                {
                    max=W[i];
                }
            }
            cout<<max<<"\n";
        }
        else
            cout<<W[N]<<"\n";
        free(ans);
        free(cans);
        free(W);
    }
    return 0;
}
