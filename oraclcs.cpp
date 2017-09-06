#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int mina=1000,minb=1000;
        int n;
        cin>>n;
        int count1,count2;
        string s;
        while(n--)
        {
            count1=0,count2=0;
            cin>>s;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='a')
                    count1++;
                else count2++;
            }
            mina = ( mina > count1 ? count1 : mina ) ;
            minb = ( minb > count2 ? count2 : minb );
        }
        cout<<( mina > minb ? minb : mina )<<endl;
    }
    return 0;
}
