/*
Userid::  deepakks1995
Problem @ Gravity Guy
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    long long int l,i,k=0;
    long long int count;
    int track;
    bool flag=0;
    cin>>t;
    while(t--)
    {
        string L1,L2;
        cin>>L1>>L2;
        l=L1.length();
        count=0;
        flag=0;
        k=0;
        //Track=1 if chef follows L1 string and Track=2 if chef follows L2 string
        if((L1[0]=='#' && L2[0]=='#'))
            cout<<"No\n";
        else if(L1[0]=='.'  && L2[0]=='#')
        {
            flag=0;
            track=1;
            k=0;
            while(k<l)
            {
                if(track==1)
                {
                    if(L1[k]=='#')
                    {
                        if(L2[k]=='#')
                            flag=1;
                        else if(L2[k]=='.')
                        {
                            count++;
                            track=2;
                        }
                    }
                }
                else if(track==2)
                {
                    if(L2[k]=='#')
                    {
                        if(L1[k]=='#')
                            flag=1;
                        else if(L1[k]=='.')
                        {
                            count++;
                            track=1;
                        }
                    }
                }
                if(flag)
                    break;
                k++;
            }
            if(flag)
                cout<<"No\n";
            else
                cout<<"Yes\n"<<count<<"\n";
        }
        else if(L2[0]=='.'  && L1[0]=='#')
        {
            flag=0;
            track=2;
            k=0;
            while(k<l)
            {
                if(track==1)
                {
                    if(L1[k]=='#')
                    {
                        if(L2[k]=='#')
                            flag=1;
                        else if(L2[k]=='.')
                        {
                            count++;
                            track=2;
                        }
                    }
                }
                else if(track==2)
                {
                    if(L2[k]=='#')
                    {
                        if(L1[k]=='#')
                            flag=1;
                        else if(L1[k]=='.')
                        {
                            count++;
                            track=1;
                        }
                    }
                }
                if(flag)
                    break;
                k++;
            }
            if(flag)
                cout<<"No\n";
            else
                cout<<"Yes\n"<<count<<"\n";
        }

        else
        {
            for(i=0; i<l; i++)
                if(L1[i]=='#')
                    break;
            for(k=0; k<l; k++)
                if(L2[k]=='#')
                    break;
            if(i==l && k==l)
                cout<<"Yes\n"<<"0\n";

            else if(i==k && i!=l)
                cout<<"No\n";
            else if(i<k)
            {
                flag=0;
                track=2;
                k=0;
                while(k<l)
                {
                    if(track==1)
                    {
                        if(L1[k]=='#')
                        {
                            if(L2[k]=='#')
                                flag=1;
                            else if(L2[k]=='.')
                            {
                                count++;
                                track=2;
                            }
                        }
                    }
                    else if(track==2)
                    {
                        if(L2[k]=='#')
                        {
                            if(L1[k]=='#')
                                flag=1;
                            else if(L1[k]=='.')
                            {
                                count++;
                                track=1;
                            }
                        }
                    }
                    if(flag)
                        break;
                    k++;
                }
                if(flag)
                    cout<<"No\n";
                else
                    cout<<"Yes\n"<<count<<"\n";
            }
            else
            {
                flag=0;
                track=1;
                k=0;
                while(k<l)
                {
                    if(track==1)
                    {
                        if(L1[k]=='#')
                        {
                            if(L2[k]=='#')
                                flag=1;
                            else if(L2[k]=='.')
                            {
                                count++;
                                track=2;
                            }
                        }
                    }
                    else if(track==2)
                    {
                        if(L2[k]=='#')
                        {
                            if(L1[k]=='#')
                                flag=1;
                            else if(L1[k]=='.')
                            {
                                count++;
                                track=1;
                            }
                        }
                    }
                    if(flag)
                        break;
                    k++;
                }
                if(flag)
                    cout<<"No\n";
                else
                    cout<<"Yes\n"<<count<<"\n";
            }
        }
    }
    return 0;
}
