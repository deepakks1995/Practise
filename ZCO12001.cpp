/*input
20
1 2 1 1 2 2 1 2 1 1 2 1 2 2 1 1 2 1 2 2
*/
#include <iostream>
#include <cstdio>
using namespace std;
class stack
{
private:
    int *data;
    long top;
public:
    stack(long num)
    {
        data = new int[num];
        top = -1;
    }
    long size()
    {
        return top+1;
    }
    bool empty()
    {
        return top==-1;
    }
    void push(int x)
    {
        top++;
        data[top]= x;
    }
    void pop()
    {
        top--;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    long N,i,index_nest,index_chain,max_nest,length,count,index;
    int num;
        stack st(100000);
        cin>>N;
        length=count=max_nest=0;
        index=index_chain=index_nest=100000;
        for(i=1; i<=N; i++)
        {
            cin>>num;
            if(num==1)
            {
                st.push(num);
                if(count==0)
                    index = i ;
                count++;
            }
            else
            {
                count++;
                if(st.size()>max_nest)
                {
                    max_nest = st.size();
                    index_nest = i-1;
                }
                st.pop();
            }
            if(st.size()==0)
            {
                if(i!=1)
                {
                    if(count>length)
                    {
                        length = count;
                        index_chain = index;
                    }
                    count=0;
                }
            }
        }
        cout<<max_nest<<" "<<index_nest<<" "<<length<<" "<<index_chain<<endl;
    
}
