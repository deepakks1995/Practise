#include<iostream>
#include<malloc.h>
#include<algorithm>
using namespace std;
long *l1,*l2;
long *r1,*r2;
void print(long int *a,long int n)
{
    for(long int i=0;i<n;i++)
    {
        cout<<a[i];
    }
}
void input(long int *A,long int size)
{
    for(long int i=0;i<size;i++)
    {
        cin>>A[i];
    }
}
void size_alloc(long int size)
{
    l1=(long *)(malloc(sizeof(long int)*(size/10)));
    l2=(long *)(malloc(sizeof(long int)*(size/10)));
    r1=(long *)(malloc(sizeof(long int)*(size/10)));
    r2=(long *)(malloc(sizeof(long int)*(size-size/10)));
}
void divide(long int *A,long int *B,long int size2,long int j)
{
    long int i,m;
    for(i=0,m=j;i<size2;i++,m++)
    {
        B[i]=A[m];
    }
}
long int inv_count(long int *A,long int size2)
{
    long int count=0;
    for(long int i=0;i<size2;i++)
    {
        for(long int j=0;j<size2;j++)
        {
            if(A[i]>A[j])
                count++;
        }
    }
    return count;
}
void sort_array(long int size)
{
    long int size2=static_cast<long int>(size)/10;
    sort(l1,l1+size2);
    sort(l2,l2+size2);
    sort(r1,r1+size2);
    size2=size-size2;
    sort(r2,r2+size2);
}
long int merge_inv(long int *A, long int *B,long int size1,long int size2)
{
     int st=0,en=0,count1=0;
     long int i,j;
       a:
        for(i=st;i<size1;i++)
        {
            for(j=size2-1;j>=en;j--)
            {
                if(A[i]>B[j])
                {
                    count1+=(size1-i)*(j+1-en);
                    st=i+1;
                    en=j+1;
                    if(st<=size1)
                        goto a;
                    else
                        goto b;
                }

            }
        }
        b:
        return count1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int size=0,size1=0,size2=0;
        long int count=0,count1=0;
        cin>>size;
        long int A[size];
        input(A,size);
        size_alloc(size);
        size2=size/10;
        long int j=0;
        divide(A,l1,size2,j);
        j=size2;
        divide(A,l2,size2,j);
        divide(A,r1,size2,2*j);
        size2=size-size2;
        divide(A,r2,size2,3*j);
        size2=(size)/10;
        count+=inv_count(l1,size2);
        count+=inv_count(l2,size2);
        count+=inv_count(r1,size2);
        size2=size-size2;
        count+=inv_count(r2,size2);
        sort_array(size);
        size2=(size)/10;
        count1+=merge_inv(l1,l2,size2,size2);
        count+=merge_inv(l1,r1,size2,size2);
        size1=size-size2;
        count+=merge_inv(l1,r2,size2,size1);
        count+=merge_inv(l2,r1,size2,size2);
        count+=merge_inv(l2,r2,size2,size1);
        count+=merge_inv(r1,r2,size2,size1);
        cout<<count+count1<<"\n";

    }
    return 0;
}

