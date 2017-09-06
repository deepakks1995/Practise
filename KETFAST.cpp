
#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,i,j,tmp1,tmp2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int A[2][26];
        //Input
        for(i=0;i<26;i++)
        {
            scanf("%d",&A[0][i]);
            A[1][i]=i;
        }

        //Sorting according to time in increasing order
        for(i=0;i<25;i++)
        {
            for(j=i+1;j<26;j++)
            {
                if(A[0][i]>A[0][j])
                {
                    tmp1=A[0][i];
                    tmp2=A[1][i];
                    A[0][i]=A[0][j];
                    A[1][i]=A[1][j];
                    A[0][j]=tmp1;
                    A[1][j]=tmp2;
                }
            }
        }
        int count[26];
        char c[12];
        scanf("%s",&c);
        //Input
        for(i=0;i<26;i++)
           count[i]=0;
        for(i=0;i<strlen(c);i++)
            count[c[i]-'a']++;
        bool flag=0;

        //reducing the alphabet taking the longest time
        for(i=25;i>=0;i--)
        {
            tmp1=A[1][i];
            if(flag==1)
                break;
            if(count[tmp1])
            {
                if(count[tmp1]>=n)
                {
                    count[tmp1]-=n;
                    flag=1;
                }
                else
                {
                    n-=count[tmp1];
                    count[tmp1]=0;
                }
            }
        }

        //Calculating the answers
        long ans=0;
        for(i=0;i<26;i++)
        {
            tmp1=A[1][i];
            if(count[tmp1]>0)
                ans+=(count[tmp1]*A[0][i]);
        }
        printf("%ld\n",ans);
    }
}
