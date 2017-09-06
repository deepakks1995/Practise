#include<iostream>
using namespace std;
int main()
{
   double l;
   cin>>l;
    while(l!=0.00)
    {
        int i=0;
        float sum=0;
        for(i=1;i<295;i++)
        {
          sum=sum+1.0/(i+1.0);
            if(sum>=l)
                break;
        }
        cout<<i<<" card(s)"<<endl;
        cin>>l;
    }
    return 0;
}
