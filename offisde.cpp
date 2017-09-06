#include<iostream>
using namespace std;
int main()
{
    int a,d;
    cin>>a>>d;
    while(a!=0 && d!=0)
    {
        int i,j,temp;
        int a1[a];
        int d1[d];
        for(i=0;i<a;i++)
            cin>>a1[i];
        for(i=0;i<d;i++)
            cin>>d1[i];
        for(i=0;i<a;i++)
        {
            for(j=i+1;j<a;j++)
            {
                if(a1[i]>a1[j])
                {
                    temp=a1[j];
                    a1[j]=a1[i];
                    a1[i]=temp;
                }
            }
        }
        for(i=0;i<d;i++)
        {
            for(j=i+1;j<d;j++)
            {
                if(d1[i]>d1[j])
                {
                    temp=d1[j];
                    d1[j]=d1[i];
                    d1[i]=temp;
                }
            }
        }
        if(a1[0]<d1[0] || a1[0]<d1[1])
            cout<<"Y\n";
        else
            cout<<"N\n";
        cin>>a>>d;
    }
    return 0;
}
