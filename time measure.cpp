#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    int t;
    cin>>t;
    while(t--)
    {
        float phi;
        int i,j;
        float thet;
        cin>>thet;
        for(i=0;i<12;i++)
        {
            for(j=0;j<60;j++)
            {
                phi=abs(6.0*j-30.0*i-j/2.0);
                if(phi>180)
                    phi=360-phi;
                if(abs(phi-thet)<(1.0/120))
                    printf("%0.2d:%0.2d\n",i,j);
            }
        }
    }
    return 0;
}
