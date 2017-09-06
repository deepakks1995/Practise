#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i,N=s.length();
    int A[10]={0};
    for(i=0;i<N;i++)
            A[s[i]-'0']=i;
    i=0;
    long count=0;
    while(i<N)
    {
        if(A[s[i]-'0']>i)
        {
            i=A[s[i]-'0'];
            count++;
        }
        else
        {
            i++;
            count++;
        }
    }
    cout<<count-1<<endl;
    return 0;
}
