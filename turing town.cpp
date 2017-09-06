#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    long k;
    cin>>k;
    long gall=k/(29*17);
    k -=gall*(29*17);
    long sick = k/29;
    k-=sick*29;
    cout<<"Output: "<<gall<<" galleons "<<sick<<" sickles "<<k<<" knuts\n";

}
