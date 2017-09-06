#include<iostream>
#include<cstring>
#include<cstdio>
using std::cin;
using std::cout;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE

    std::ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        bool *arr1= new bool[150]();
        std::string A,B;
        cin>>A>>B;
        for(int i=0;i<A.length();i++)
        {
                arr1[A[i]]=1;
        }
        bool check=0;
        for(int i=0;i<B.length();i++)
        {
                if(arr1[B[i]])
                    check=1;
        }
        if(check)
            cout<<"Yes\n";
        else
            cout<<"No\n";
            delete [] arr1;
    }
    return 0;
}
