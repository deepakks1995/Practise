/*input
2
7
1 5 0 0 4 0 3
11
3 9 9 6 4 3 6 4 9 6 0
*/
#include <iostream>
using namespace std;
 
int t,N,i,j;
int arr[10];
long long sum;
bool check_zero;
 
void solve();
 
int main()
{
    cin>>t;
    while(t--)
    {
        for(i=0; i<10; ++i)
            arr[i] = 0;
        check_zero = sum = 0;
        cin>>N;
        for(i=0; i<N; ++i)
        {
            cin>>j;
            sum += j;
            ++arr[j];
            if(j==0)
                check_zero = 1;
        }
        //cout<<":sum: "<<sum<<endl;/*
        /*for(i=0;i<10;++i)
            //cout<<"::i: "<<i<<" "<<arr[i]<<endl;*/
        solve();
    }
}
 
void solve()
{
    if(!check_zero)
        cout<<"-1";
    else
    {
        if(sum%3==0)
        {
            //cout<<"::% 0  "<<endl;
            i=9;
            while(i>=0)
            {
                while(arr[i]!=0)
                {
                    cout<<i;
                    --arr[i];
                }
                --i;
            }
        }
        else if(sum%3==1)
        {
            //cout<<"::% 1  "<<endl;
            if(arr[1]!=0)
            {
                //cout<<"::cond 1  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==1)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[4]!=0)
            {
                //cout<<"::cond 4  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==4)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[7]!=0)
            {
                //cout<<"::cond 7  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==7)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[2]>=2)
            {
                //cout<<"::cond 2>=2  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==2)
                        arr[i]-=2;
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[2]!=0 && arr[5]!=0)
            {
                //cout<<"::cond 2 & 5  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==2)
                        --arr[i];
                    if(i==5)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[5]>=2)
            {
                //cout<<"::cond 2 & 5  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==5)
                        arr[i]-=2;
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[4]!=0 && arr[6]!=0)
            {
                //cout<<"::cond 2 & 5  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==4)
                        --arr[i];
                    if(i==6)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[2]!=0 && arr[8]!=0)
            {
                //cout<<"::cond 2 & 5  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==2)
                        --arr[i];
                    if(i==8)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[8]!=0 && arr[5]!=0)
            {
                //cout<<"::cond 2 & 5  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==8)
                        --arr[i];
                    if(i==5)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[8]>=2)
            {
                //cout<<"::cond 2 & 5  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==8)
                        arr[i]-=2;
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else
                cout<<"-1";
        }
        else
        {
            //cout<<"::% 2  "<<endl;
            if(arr[2]!=0)
            {
                //cout<<"::cond 2   "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==2)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[5]!=0)
            {
                //cout<<"::cond 5  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==5)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[8]!=0)
            {
                //cout<<"::cond 8  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==8)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[1]>=2)
            {
                //cout<<"::cond 1>2  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==1)
                        arr[i]-=2;
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[1]!=0 && arr[4]!=0)
            {
                //cout<<"::cond 1 & 4  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==1)
                        --arr[i];
                    if(i==4)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[4]>=2 )
            {
                //cout<<"::cond 4>2  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==4)
                        arr[i]-=2;
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[1]!=0 && arr[7]!=0)
            {
                //cout<<"::cond 1 & 7  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==1)
                        --arr[i];
                    if(i==7)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[4]!=0 && arr[7]!=0)
            {
                //cout<<"::cond 1 & 7  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==4)
                        --arr[i];
                    if(i==7)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[7]>=2)
            {
                //cout<<"::cond 1 & 7  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==7)
                        arr[i]-=2;
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[1]!=0 && arr[2]>=2 )
            {
                //cout<<"::cond 1 & 2>2  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==1)
                        --arr[i];
                    if(i==2)
                        arr[i]-=2;
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else if(arr[1]!=0 && arr[2]!=0 && arr[5]!=0)
            {
                //cout<<"::cond 1 & 2 & 5  "<<endl;
                i=9;
                while(i>=0)
                {
                    if(i==1)
                        --arr[i];
                    if(i==2)
                        --arr[i];
                    if(i==5)
                        --arr[i];
                    while(arr[i]!=0)
                    {
                        cout<<i;
                        --arr[i];
                    }
                    --i;
                }
            }
            else
                cout<<"-1";
        }
    }
    cout<<endl;
}