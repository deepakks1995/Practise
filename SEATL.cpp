#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif // ONLINE_JUDGE
    int t;
    cin>>t;
    long matrix[100][100]= {0},counter[100000]= {0},keeper[1000]= {0};
    long N,M,inc,i,j,k,max;
    while(t--)
    {
        cin>>N>>M;
        for(i=0; i<N; i++)
        {
            k=0;
            for(j=0; j<M; j++)
            {
                cin>>matrix[i][j];
                counter[matrix[i][j]]++;
                keeper[k++]=matrix[i][j];
            }
            max=0;
            for(j=0; j<M; j++)
            {
                if(max<counter[matrix[i][j]])
                    max=counter[matrix[i][j]];
            }
            inc=M+1;
            for(j=0; j<M; j++)
            {
                if(counter[matrix[i][j]]==max)
                {
                    matrix[i][inc++]=matrix[i][j];
                    counter[matrix[i][j]]=0;
                }
            }
            for(j=0; j<k; j++)
                counter[keeper[j]]=0;
            matrix[i][M]=max;
        }
        memset(counter,0,sizeof(counter));

        for(j=0; j<M; j++)
        {
            k=0;
            for(i=0; i<N; i++)
            {
                counter[matrix[i][j]]++;
                keeper[k++]=matrix[i][j];
            }
            for(i=0; i<N; i++)
            {
                if(max<counter[matrix[i][j]])
                    max=counter[matrix[i][j]];
            }
            inc = N+1;
            for(i=0; i<N; i++)
            {
                if(counter[matrix[i][j]]==max)
                {
                    matrix[inc++][j] = matrix[i][j];
                    counter[matrix[i][j]]=0;
                }
            }
            for(i=0; i<k; i++)
                counter[keeper[i]]=0;
            matrix[N][j]=max;
        }
        /*cout<<endl;
        for(i=0; i<N+N+5; i++)
        {
            for(j=0; j<M+M+5; j++)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        }*/
        max=0;
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {

            }
        }
    }
}
