#include<iostream>
using namespace std;

unsigned long long int sum(unsigned long long int num)
{
    unsigned long long int count=0;
    while(num)
    {
        count+=num%10;
        //cout<<"count : "<<count<<endl;
        num/=10;
    }
    unsigned long long int numb=count,count1=0;
    while(numb)
    {
        count1++;
        numb/=10;
    }
    if(count1>1)
        count=sum(count);
    return count;

}
int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int count=0;
        long long int A,D,R,L;
        unsigned long long int s=0,numb=0,i;
        cin>>A>>D>>L>>R;
        i=L;
        numb=A+(i-1)*D;
        while(i<=R)
        {
            //cout<<numb<<endl;
            count=sum(numb);
            //cout<<count<<endl;
            s+=count;
            numb+=D;
            i++;
        }
        cout<<s<<endl;
    }
}

