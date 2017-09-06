#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    long long int n,max1=0,max2=0;
    cin>>n;
    long long int m,i;
    for(i=0;i<n;i++)
    {
        cin>>m;
        if(i>=1 && (max1<=m))
        {
            max2=max1;
            max1=m;
        }
        else if(i==0)
        {
            max1=m;
            max2=m;
        }
    }
    cout<<max1<<" "<<max2<<endl;
}
