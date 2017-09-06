/*input
12
bipinka bipinki bipinki bipinki bipinki bipinki bipinki bipinka bipinki bipinki bipinka bipinka  
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N,i,j,count1,index_ka,index_ki;

int main()
{
    ios_base::sync_with_stdio(0);

    cin>>N;
    string ka[N],ki[N];
    string s;
    index_ka = index_ki = count1 = j = 0;
    for(i=0; i<N; ++i)
    {
        cin>>s;
        if(s[s.length()-2]=='k')
        {
            if(s[s.length()-1]=='a')
            {
                ka[index_ka] = s;
                ka[index_ka][s.length()-1] = 'z';
                ka[index_ka][s.length()-2] = 'z';
                ++index_ka;
            }
            else if(s[s.length()-1]=='i')
            {
                ki[index_ki] = s;
                ki[index_ki][s.length()-1] = 'z';
                ki[index_ki][s.length()-2] = 'z';
                ++index_ki;
            }
        }
    }
    bool check_ka[index_ka];
    bool check_ki[index_ki];
    for(i=0; i<index_ka; ++i)
        check_ka[i] =0;
    for(i=0; i<index_ki; ++i)
        check_ki[i] =0;
    for(i=0; i<index_ka; ++i)
    {
        if(check_ka[i]==0)
        {
            for(j=0; j<index_ki; ++j)
                if(check_ki[j]==0 && ka[i]==ki[j])
                {
                    ++count1;
                    check_ki[j] = check_ka[i] = 1;
                    break;
                }
        }
    }
    cout<<count1<<endl;
}