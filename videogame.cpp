#include <iostream>
#include <cstdio>
#include <malloc.h>
#include <vector>
#include <stdlib.h>
using namespace std;
bool flag=0;

//function declaration.................

void pickup(long long int A[], long long int );
void moveright(long long int *,long long int );
void moveleft(long long int *);
void dropbox(long long int A[],long long int ,long long int );

int main()
{
    long long int N,H,i,j=0,k,index=0;
    cin>>N>>H;
    long long int *A=(long long int *)calloc(N,sizeof(long long int));
    for(i=0; i<N; i++)
        cin>>A[i];
        getchar();
    vector<int> a;
    string ch;
    getline(cin,ch);
    j=ch.length();
    for(k=0; k<j; k++)
    {
        if(ch[k]!=32)
        {
            a.push_back(ch[k]-48);
            index++;
        }
    }
    i=0;
    flag=0;
    for(j=0; j<index; j++)
    {
        if(a[j]==3)
            pickup(A,i);
        else if (a[j]==2)
            moveright(&i,N);
        else if (a[j]==1)
            moveleft(&i);
        else if(a[j]==4)
            dropbox(A,i,H);
            else if(a[j]==0)
                break;
    }
    for(i=0; i<N; i++)
        cout<<A[i]<<" ";
    free(A);
    flag=0;
    return 0;
}

//function definition......................

void pickup(long long int A[], long long int i)
{
    if(flag==0)
    {
        if(A[i]!=0)
        {
            flag=1;
            A[i]=A[i]-1;
        }
    }
}

void moveright(long long int *i,long long int N)
{
    if(*i+1<=N-1)
        (*i)++;
}

void moveleft(long long int *i)
{
    if(*i)
        (*i)--;
}

void dropbox(long long int A[],long long int i,long long int H)
{
    if(A[i]<H && flag==1)
    {
        A[i]+=1;
        flag=0;
    }
}