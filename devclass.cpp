/*input
1
0
BGG
*/
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
    int t,type;
    long l,g,b,i,count,count1,count2,j,k;
    char s[100000];
    bool flag;
    cin>>t;
    while(t--)
    {
        count=count1=count2=flag=b=g=0;
        cin>>type;
        cin>>s;
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='B')
                b++;
            else
                g++;
        }

        if(type==0)
        {
            if(b==g+1)
            {
                for(i=0;i<l;i+=2)
                {
                    if(s[i]=='G')
                        count++;
                }
            }
            else if(g==b+1)
            {
                for(i=0;i<l;i+=2)
                {
                    if(s[i]=='B')
                        count++;
                }
            }
            else if(b==g)
            {
                count1=0;
                for(i=0;i<l;i+=2)
                    if(s[i]=='B')
                        count++;
                    else
                        count1++;
                if(count1<count)
                    count=count1;
            }
            else
                count=-1;
            cout<<count<<endl;
        }
        else
        {
            j=k=count1=count=0;
            if(g==b+1)
            {
                for(i=0;i<l;i+=2)
                {
                    while(s[j]!='G')
                        j++;
                        count+=abs(i-j);
                        j++;
                }
            }
            else if(b==g+1)
            {
                for(i=0;i<l;i+=2)
                {
                    while(s[j]!='B')
                        j++;
                        count+=abs(i-j);
                        j++;
                }
            }
            else if(b==g)
            {
                for(i=0;i<l;i+=2)
                {
                    while(s[j]!='G')
                        j++;
                        count+=abs(i-j);
                        j++;
                }
                j=0;
                for(i=0;i<l;i+=2)
                {
                    while(s[j]!='B')
                        j++;
                        count1+=abs(i-j);
                        j++;
                }
                if(count1<count)
                    count=count1;
            }
            else
                count=-1;

            cout<<count<<endl;
        }

    }
    return 0;
}
