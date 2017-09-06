#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    long D,i,l,j;
    cin>>D;
    while(D--)
    {
        char S[10000];
        scanf("%s",S);
        if(strlen(S)%2==0)
        {
            bool check=0;
            for(i=0,j=strlen(S)/2; i<strlen(S)/2; i++,j++)
                if(S[i]!=S[j])
                    check=1;
            if(check)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
        else
        {
            bool ans=0;
            bool check=0;
            long index,count;
            int A=1;
            count=0;
            for(i=0,j=l/2+1;i<l/2+1,j<l;j++,i++)
            {
                if(S[i]!=S[j] && S[i+1]==S[j] && count==0)
                {
                    index=i;
                    count++;
                    i++;
                }
                else if(S[i]!=S[j] && (S[i+1]!=S[j] || (S[i+1]!=S[j] && count>0) ) )
                {
                    A=0;
                    break;
                }
            }
            if(count==1 && A==1)
            {
                ans=1;
                for(i=0,j=l/2+1;i<l/2+1,j<l;i++,j++)
                {
                    if(i==index)
                        i++;
                    if(S[i]!=S[j])
                        ans=0;
                }
            }
            else if(count==0 && A==1)
            {
                ans=1;
                for(i=0,j=l/2+1;i<=l/2-1,j<l;i++,j++)
                {
                    if(S[i]!=S[j])
                        ans=0;
                }
            }
            else if(A==0)
            {
                index=count=0;
                for(i=0,j=l/2;i<=l/2-1,j<l;i++,j++)
                {
                    if(S[i]!=S[j] && S[i]==S[j+1])
                    {
                        index=j;
                        count++;
                        j++;
                    }
                    if(S[i]!=S[j] && (S[i]!=S[j+1] || (count>0 && S[i]!=S[j+1])))
                    {
                        A=3;
                        ans=0;
                    }
                }
                if(count==1 && A==0)
                {
                    ans=1;
                    for(i=0,j=l/2;i<=l/2-1,j<l;i++,j++)
                    {
                        if(j==index)
                            j++;
                        if(S[i]!=S[j])
                            ans=0;
                    }
                }
                else if(count==0 && A==0)
                {
                    ans=1;
                    for(i=0,j=l/2;i<=l/2-1;i++,j++)
                        if(S[i]!=S[j])
                            ans=0;
                }
            }
            if(ans==1)
                cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
