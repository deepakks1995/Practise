#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int a,b;
        int count=0;
        cin>>a>>b;
        while(a!=b)
        {
            if(a>b)
            {
                a=a/2;
                count++;
            }
            else if(a<b)
            {
                b=b/2;
                count++;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}
