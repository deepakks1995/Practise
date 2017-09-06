    #include <iostream>
    using namespace std;
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        /*
        #ifndef ONLINE
           freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
        #endif // ONLINE*/
        int t;
        cin>>t;
        int N,Q,L,R,K,i;
        string s;
        while(t--)
        {
            cin>>N>>Q;
            cin>>s;
            int arr[N];
            for(i=0; i<N; i++)
                arr[i] = 0;
            while(Q--)
            {
                cin>>L>>R>>K;
                K%=26;
                for(i=L-1; i<=R-1; i++)
                    arr[i] += K;
            }
//            for(i=0;i<N;i++)
//                cout<<arr[i]<<" ";
//            cout<<endl;
            for(i=0; i<N; i++)
            {
                arr[i]%=26;
                if(arr[i]>=0)
                {
                    if(s[i] + arr[i] <=122)
                        s[i] += arr[i];
                    else
                        s[i] = 96 - 122 + s[i] + arr[i];
                }
                else
                {
                    if(arr[i] + s[i] >=97)
                        s[i] += arr[i];
                    else
                        s[i] = s[i] + arr[i] - 96 + 122;
                }
                //cout<<arr[i]<<" ";
            }
           // cout<<endl;
            /*
            for(i=L-1; i<=R-1; i++)
            {
                if(K>0)
                {
                    if(s[i]+K<=122)
                        s[i]+=K;
                    else
                        s[i] = 96 - 122 + s[i] +K;
                }
                else
                {
                    if(s[i] + K >=97)
                        s[i]+=K;
                    else
                        s[i] = s[i] + K -96 + 122;
                }
            }*/

            cout<<s<<endl;
        }
    }
