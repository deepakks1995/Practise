#include <iostream>
#include <malloc.h>
using namespace std;
int main()
{
    long int N,M,Q,i,k;
    cin>>N>>M>>Q;
    long int P[N];
    long int R[2][M];
    for(i=0; i<N; i++)
        cin>>P[i];
    for(i=0; i<M; i++)
        cin>>R[0][i]>>R[1][i];
    //Creating Subsets
    long int *subsets=(long int *) calloc (N+1,sizeof(long int *));
    subsets[1]=1;
    long int *parent=(long int *) calloc (N+1,sizeof(long int *));
    for(i=0; i<M; i++)
        parent[R[1][i]]=R[0][i];
    long int count=1,j=0;;
    for(i=1; i<N+1; i++)
    {
        j=parent[i];
        if(parent[i]==0)
        {
            subsets[j]=count++;
        }
        else
        {
            while(j!=i && j!=0)
            {
                subsets[j]=count;
                j=parent[j];
            }
            subsets[j]=count;
            count++;
        }
    }
    for(i=0;i<count;i++)
        cout<<subsets[i];
    cout<<endl;
    while(Q--)
    {
        char s;
        cin>>s;
        long int sum=0,max=0;
        if(s=='P')
        {
            long int id,ppl;
            cin>>id>>ppl;
            P[id-1]=ppl;
            max=0;
            for(i=1; i<count; i++)
            {
                sum=0;
                for(k=1; k<N+1; k++)
                {
                    if(subsets[k]==i)
                        sum+=P[k-1];
                }
                if(sum>max)
                    max=sum;
            }
            cout<<max<<endl;
            for(i=0;i<count;i++)
                cout<<subsets[i];
                cout<<endl;
        }
        else if (s=='D')
        {
            long int index;
            cin>>index;
            long int first,second;
            first=R[0][index-1];
            second=R[1][index-1];
            parent[second]=0;
            j=parent[first];
            bool flag=0;
            while(j!=0 && j!=second && flag==0)
            {
                j=parent[j];
                if(j==second)
                    flag=1;
            }
            if(flag)
            {
                max=0;
                for(i=1; i<count; i++)
                {
                    sum=0;
                    for(k=1; k<N+1; k++)
                    {
                        if(subsets[k]==i)
                            sum+=P[k-1];
                    }
                    if(sum>max)
                        max=sum;
                }
                cout<<max<<endl;
                for(i=0;i<count;i++)
                    cout<<subsets[i];
                    cout<<endl;
            }
            else
            {
                for(i=0;i<N+1;i++)
                {
                    if(subsets[i]==subsets[second])
                    {
                        if(parent[i]=second)
                            subsets[i]=count;
                    }
                }
                count++;
                max=0;
                for(i=1; i<count; i++)
                {
                    sum=0;
                    for(k=1; k<N+1; k++)
                    {
                        if(subsets[k]==i)
                            sum+=P[k-1];
                    }
                    if(sum>max)
                        max=sum;
                }
                cout<<max<<endl;
                for(i=0;i<count;i++)
                    cout<<subsets[i];
                    cout<<endl;
            }
        }
    }
    return 0;
}
