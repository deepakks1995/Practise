/*input
2
12
3 1 2 3 2 0 2 2 2 0 2 3
11
3 9 9 6 4 3 6 4 9 6 0
*/
#include <iostream>
#include <algorithm>
#define max_size 1000005
using namespace std;
 
long long t,N,i,j,one,two;
long long arr[max_size],bits[max_size];
long long sum;
bool check_zero;
 
int solve();
void print(long long& );
void print1(long long& , long long&);
 
int main()
{
    cin>>t;
    while(t--)
    {
        two = one = check_zero = sum = 0;
        cin>>N;
        for (int i = 0; i < N; ++i)
        {
            arr[i] = 0;
            bits[i] = 0;
        }
        for(i=0; i<N; ++i)
        {
            cin>>arr[i];
            sum += arr[i];
            if(arr[i]==0)
                check_zero = 1;
        }
        //cout<<":sum: "<<sum<<endl;/*
        /*for(i=0;i<10;++i)
            //cout<<"::i: "<<i<<" "<<arr[i]<<endl;*/
        sort(arr,arr+N);
        for(i=0;i<N;++i)
        {
            bits[i] = arr[i] % 3;
            if(bits[i]==1)
                ++one;
            else if(bits[i] == 2)
                ++two;
        }
        if(!check_zero)
            cout<<"-1";
        else
            solve();
        cout<<endl;
    }
}


int solve()
{
    if(sum%3==0)
    {
        long long indx = -100;
        print(indx);
    }
    else if (sum%3==1)
    {
        if(one>0)
        {
            for(i=0;i<N;++i)
            {
                if(bits[i]==1)
                {
                    print(i);
                    break;
                }
            }
        }
        else if (two>=2) 
        {   
            for(i=0;i<N;++i)
                if(bits[i]==2)
                    break;
            for(j=i+1;j<N;++j)
                if(bits[j]==2)
                    break;
            print1(i,j);
        }
        else
            cout<<"-1";
    }
    else
    {
        if(two)
        {
            for(i=0;i<N;++i)
            {
                if(bits[i]==2)
                {
                    print(i);
                    break;
                }
            }
        }
        else if (one>=2)
        {
            for(i=0;i<N;++i)
                if(bits[i]==1)
                    break;
            for(j=i+1;j<N;++j)
                if(bits[j]==1)
                    break;
            print1(i,j);
        }
        else
            cout<<"-1";
    }
}

void print(long long& i)
{
    for(long long x = N-1 ; x>=0 ; --x)
    {
        if(x!=i)
            cout<<arr[x];
        else
            continue;
    }
}

void print1(long long& i, long long& j)
{
    for(long long x = N-1 ; x>=0 ; --x)
    {
        if(x!=i && x!=j)
            cout<<arr[x];
        else
            continue;
    }
}   