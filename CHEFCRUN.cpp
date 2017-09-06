/*input
1
7
5 10 2 3 20 -15 -5
1 5
*/
#include <iostream>
#include <cstdio>
#define max_size 200005
using std::cin;
using std::cout;
using std::endl;
//using std::ios_base;

long long t,N,start,end,i,j;
long long A[max_size];
long long left_neg,right_neg,left,right,ans1,ans2,sum,check;

int main()
{
    //ios_base::sync_with_stdio(0);
    scanf("%lld",&t);
    while(t--)
    {
        check = ans1 = ans2 = sum = left = right = left_neg = right_neg = 0;
        scanf("%lld",&N);
        for( i=1; i<=N; ++i )
            scanf("%lld",&A[i]);
        scanf("%lld",&start);
        scanf("%lld",&end);
        for( i=start; true; ++i)
        {
            if(i>N)
                i%=N;
            if(i==end)
                break;
            sum += A[i];
            if(left_neg>sum)
                left_neg = sum;
        }
        sum = 0;
        for( i=(start-1); true; --i)
        {
            if(i==0)
                i=N;
            sum += A[i];
            if(right_neg>sum)
                right_neg = sum;
            if(i==end)
                break;
        }
        for( i=start; true; ++i)
        {
            if(i>N)
                i%=N;
            if(i==end)
                break;
            left += A[i];
        }
        for( i=(start-1); true; --i)
        {
            if(i==0)
                i=N;
            right += A[i];
            if(i==end)
                break;
        }
        ans[1] = left + (right_neg*2);
        ans[2] = right + (left_neg*2);
        sum = left_neg = right_neg = 0;
        for( i=end; true; ++i)
        {
            if(i>N)
                i%=N;
            if(i==start)
                break;
            sum += A[i];
            if(left_neg>sum)
                left_neg = sum;
        }
        sum = 0;
        for( i=(end-1); true; --i)
        {
            if(i==0)
                i=N;
            sum += A[i];
            if(right_neg>sum)
                right_neg = sum;
            if(i==start)
                break;
        }
        ans[3] = left + left_neg*2;
        ans[0] = right + right_neg*2;
        Arrays.sort(ans); 
        System.out.println(ans[0]);
    }
}