//MotorBike Racing

#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<cstdio>
using namespace std;

struct bike
{
    int id;
    long v,x;
    long long res;
};
bool cmp(bike lhs, bike rhs) { return lhs.res > rhs.res; }
int main()
{
    long long t,k;
    int test,N,Q,i;
    scanf("%d",&test);
    struct bike bk[2000];
    while(test--)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%ld",&bk[i].v);
            //cin>>bk[i].v;
            scanf("%ld",&bk[i].x);
            //cin>>bk[i].x;
            bk[i].id=i;
        }
        cin>>Q;
        while(Q--)
        {
            scanf("%lld%lld",&t,&k);
            for(i=0;i<N;i++)
                bk[i].res = bk[i].v*t+bk[i].x;
            sort(bk,bk+N,cmp);
            cout<<bk[k-1].id+1<<endl;
        }
    }
}
