#include<iostream>
using namespace std;
int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        long int w,b;
        cin>>w>>b;
        if(b%2!=0)
           {
               cout<<"1.000000\n";
           }
        else
            {
                cout<<"0.000000\n";
            }
    }
}
