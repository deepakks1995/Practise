#include<iostream>
#include<malloc.h>

using namespace std;
#define lld long long int
#define num 10001
struct object
{
    long long int val;
    int prio;
};
int main()
{
        ios_base::sync_with_stdio(0);
    struct object obj[num][num];
    lld N,M,att,id,val,prio;
    cin>>N>>M;
    while(N--)
    {
        cin>>id>>att>>val>>prio;
        if(obj[id][att].prio<=prio)
        {
            obj[id][att].val=val;
            obj[id][att].prio=prio;
        }
    }
    while(M--)
    {
        cin>>id>>att;
        cout<<obj[id][att].val<<endl;
    }
    return 0;
}
