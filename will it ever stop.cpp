#include<iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    int k=0;
    while(n>1)
    {
        if(n%2==0)
        {
            n=n/2;
            k=1;
        }
        else if (n%2!=0)
        {
            cout<<"NIE";
            k=0;
            break;
        }
    }
    if(k==1)
    {
        cout<<"TAK";
    }
    return 0;
}
