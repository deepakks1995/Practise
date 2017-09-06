#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<malloc.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long N,M,i,j,k;
        long int count=0,avgI=0,avgJ=0;
        cin>>N>>M;
        string s;
        vector <long> I,J;
        //int I[N*M],J[N*M];
        for(i=0; i<N; i++)
        {
            cin>>s;
            for(j=0; j<M; j++)
            {
                if(s[j]=='*')
                {
                    I.push_back(i);
                    J.push_back(j);
                    avgI+=i;
                    avgJ+=j;
                    count++;
                }
            }
        }
        //cout<<"Count: "<<count<<endl;
        long i1,j1,index,min=1000;
        if(count!=0)
        {
          //  cout<<"Count: "<<count<<endl;
            avgI/=count;
            avgJ/=count;
            long max=0,dist;
            long initi=(avgI-1) <= 0 ? 0:(avgI-1) ;
            long condi=(avgI+1) >= N ? N :(avgI+1) ;
            long initj=( (avgJ-1) <= 0 ? 0:(avgJ-1) );
            long condj=( (avgJ+1) >= M ? M:(avgJ+1) );
            for(i=initi; i<condi; i++)
            {
                for(j= initj; j<condj; j++)
                {
                    index=0;
                    max=0;
                    while(index<count)
                    {
                        i1=I[index];
                        j1=J[index];
                        index++;
                        k=abs(i1-i);
                        if(j1>(j+k))
                            dist=abs(i1-i)+ abs(j1-(j+k));
                        else if(j1<(j-k))
                            dist=abs(i1-i) + abs(j1-(j-k));
                        else
                            dist=abs(i1-i);
                        if(max<dist)
                            max=dist;
                    }
  //                  cout<<"max: "<<max<<endl;
                    if(min>max)
                        min=max;
                }
            }
//            cout<<"min: "<<min<<endl;
            cout<<min+1<<endl;
        }
        else cout<<"0"<<endl;
    }
    return 0;
}

