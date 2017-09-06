#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int N,M,P,Q;
        long long int S,count=0,i,j;
        cin>>N>>M>>S>>P>>Q;
        int points=N-M+1,VK=0,RS=0;

        if(P>Q)
        {
            for(i=0; i<S; i++)
            {
                if(RS<=M-1)
                {
                    VK+=P;
                    RS+=Q;
                    if(RS==VK)
                        count++;
                }
                else break;
            }
            RS-=M-1;
            RS=RS%points;
            VK-=M-1;
            VK=VK%points;
            for(j=i; j<S; j++)
            {
                if(RS==VK)
                    count++;
                VK+=P;
                RS+=Q;
                if(VK>points)
                    VK%=points;
                if(RS>points)
                    RS%=points;

            }
            if(j==S)
            {
                if(RS==VK)
                    count++;
            }
            cout<<count<<"\n";
        }
        else if(Q>P)
        {
            for(i=0; i<S; i++)
            {
                if(VK<=M-1)
                {
                    VK+=P;
                    RS+=Q;
                    if(RS==VK)
                        count++;
                }
                else break;
            }
            RS-=M-1;
            RS=RS%points;
            VK-=M-1;
            VK=VK%points;
            for(j=i; j<S; j++)
            {
                if(RS==VK)
                    count++;
                VK+=P;
                RS+=Q;
                if(VK>points)
                    VK%=points;
                if(RS>points)
                    RS%=points;
            }
            if(j==S)
            {
                if(RS==VK)
                    count++;
            }
            cout<<count<<"\n";
        }
    }
    return 0;
}
