#include<iostream>
#include<malloc.h>
using namespace std;
int main()
{
    int t,i,j,temp;
    cin>>t;
    while(t--)
    {
        int n,count1=0,count2=0,count3=0;
        cout<<"\n";
        cin>>n;
        int half=n/2;
        long int *A,*left,*right;
        A=(long int*)malloc(sizeof(long int)*n);
        right=(long *)malloc(sizeof(long int)*(n-half));
        left=(long *)malloc(sizeof(long int)*half);
        for(i=0;i<n;i++)
            cin>>A[i];
        for(i=0;i<half;i++)
            left[i]=A[i];
        for(j=0;i<n;i++,j++)
            right[j]=A[i];
        for(i=0;i<half;i++)
        {
            for(j=i+1;j<half;j++)
            {
                if(left[i]>left[j])
                {
                    temp=left[i];
                    left[i]=left[j];
                    left[j]=temp;
                    count1+=1;
                }
            }
        }
        for(i=0;i<(n-half);i++)
        {
            for(j=i+1;j<(n-half);j++)
            {
                if(right[i]>right[j])
                {
                    temp=right[i];
                    right[i]=right[j];
                    right[j]=temp;
                    count2+=1;
                }
            }
        }
        i=0;
        int check=0;
        a:
            check=0;
            while(i<half)
            {
                for(j=(n-half-1);j>=0;j--)
                {
                    if(left[i]>right[j])
                    {
                        count3=count3+1+j;
                        i++;
                        check=1;
                        goto a;
                    }
                    else continue;
                }
                if(check==0)
                    i++;
            }
        cout<<count3+count2+count1<<"\n";

    }
    return 0;
}
