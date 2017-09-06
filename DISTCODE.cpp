#include<iostream>
#include<cstring>
#include<malloc.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        char S[10001];
        cin>>S;
        int m=strlen(S);
        int *count=(int *) calloc (3000,sizeof(int));
        int tmp=0;
        int sum=0;
        for(int i=0;i<m-1;i++)
        {
            tmp=(S[i]-'A')*26+(S[i+1]-'A');
            if(count[tmp]==0)
            {
                count[tmp]++;
                sum++;
            }
        }

        /*for(int i=0;i<3000;i++)
        {
            if(count[i])
                sum+=count[i];
        }*/
        cout<<sum<<endl;
        free(count);
    }
    return 0;
}
