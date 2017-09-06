#include<iostream>
#include<cstdio>
#include<string.h>
#include<cstring>
using namespace std;
struct str
{
    string s;
};
struct line
{
    string t;
    int c;
};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
        {
        int N,k,l,i,j;
        scanf("%d%d",&N,&k);
        struct line term[N];
        for(i=0;i<N;i++)
                {
                    cin>>term[i].t;
                    term[i].c=0;
                }
        while(k--)
        {
            scanf("%d",&l);
            struct str str[l];
            for(i=0;i<l;i++)
            {
                cin>>str[i].s;
                for(j=0;j<N;j++)
                {
                    if(term[j].t==str[i].s)
                        term[j].c=1;

                }
            }
        }
        for(i=0;i<N;i++)
        {
            if(term[i].c==1)
            {
                printf("YES ");
            }
            else if (term[i].c==0)
                printf("NO ");
        }
        }
}
