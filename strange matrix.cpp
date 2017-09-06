#include<stdio.h>
int GCD(int a,int b)
{
        if (b == 0) return a;
        return GCD(b, a % b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int N,M;
        scanf("%d%d",&N,&M);
        printf("%d\n",GCD(N-1,M-1)+1);
    }
    return 0;
}
