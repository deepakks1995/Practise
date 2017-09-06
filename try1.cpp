#include<iostream>
using namespace std;
int main()
{
    int t;		//t is the number of test cases
    int r,g,b;	// r denotes red,g denotes green, b for blue
    int k;		//at least k ballons of the same color
    cin >> t;
    int total;
    int i;
    int countr,countg,countb;
    int t1,t2,t3;
    while(t--)
    {
        cin >> r >> g >> b;
        cin >> k;
        countr=countg=countb=0;
        total=r+g+b;
        t1=1;
        t2=0;
        t3=0;
        int j=0;
        i=0;
        while(1)
        {
            if(countr==k || countg==k || countb==k)
            {
                break;
            }
            j=i%3;
            if(r!=0 && j==0)
            {
                countr++;
                r--;
            }

            else if(g!=0 && j==1)
            {
                countg++;
                g--;
            }

            else if(b!=0 && j==2)
            {
                countb++;
                b--;
            }
            i++;


        }
        int ans;
        ans=countr+countg+countb;
       // cout << countr<<"\t" << countg<<"\t" << countb;
        cout << ans << "\n";

    }
}
