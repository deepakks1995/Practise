
import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class main
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int N,start,end,i,left_sum,right_sum,left_neg1,left_neg2,right_neg1,right_neg2,ans,sum,top,bottom;
		String s[];
		int A[] = new int[200005];
		while(T--!=0)
		{
            left_neg2 = left_neg1 = right_neg2 = right_neg1 = sum = left_sum = right_sum = 0;
            N = Integer.parseInt(br.readLine());
            s = br.readLine().split(" ");
            for (i=1;i<=N;++i)
                A[i] = Integer.parseInt(s[i-1]);
            s = br.readLine().split(" ");
            start = Integer.parseInt(s[0]);
            end = Integer.parseInt(s[1]);
            //Summing the left and right parts
            for( i=start; true; ++i)
            {
                if(i>N)
                    i%=N;
                if(i==end)
                    break;
                left_sum += A[i];
            }
            for( i=(start-1); true; --i)
            {
                if(i==0)
                    i=N;
                right_sum += A[i];
                if(i==end)
                    break;
            }
            top = bottom = sum = 0;
            // Taking manimum negative values for left part
            for( i=start; true; ++i)
            {
                if(i>N)
                    i%=N;
                if(i==end)
                    break;
                sum += A[i];
                if(left_neg1>sum)
                {
                    top = i;
                    left_neg1 = sum;
                }
            }
            sum = 0;
            for( i=(end-1); true; --i)
            {
                if(i==0)
                    i=N;
                sum += A[i];
                if(left_neg2>sum)
                {
                    bottom = i;
                    left_neg2 = sum;
                }
                if(i==start )
                    break;
            }
             System.out.println("left_neg1: " + left_neg1);
            System.out.println("left_neg2: " + left_neg1);
            System.out.println("right_sum: " + right_sum);
            if(left_neg1 < left_neg2)
            {
                left_neg2 = sum = 0;
                for( i=(end-1); true; --i)
                {
                    if(i==0)
                        i=N;
                    sum += A[i];
                    if(left_neg2>sum)
                        left_neg2 = sum;
                    if(i==start || i==((top+1)==N+1 ? 1 : (top + 1)) )
                        break;
                }   
            }
            else if(left_neg1 > left_neg2)
            {
                left_neg1 = sum = 0;
                for( i=start; true; ++i)
                {
                    if(i>N)
                        i%=N;
                    if(i==end || i==bottom)
                        break;
                    sum += A[i];
                    if(left_neg1>sum)
                        left_neg1 = sum;
                }   
            }
            else
                left_neg2 = 0;

            System.out.println("left_neg1: " + left_neg1);
            System.out.println("left_neg2: " + left_neg2);
            System.out.println("right_sum: " + right_sum);
            ans = right_sum + left_neg1*2 + left_neg2*2;
            System.out.println("ans: " + ans);
            //Taking minimum negative values for right part
            top = bottom = sum = 0;
            for( i=(start-1); true; --i)
            {
                if(i==0)
                    i=N;
                sum += A[i];
                if(right_neg1>sum)
                {
                    top = i;
                    right_neg1 = sum;
                }
                if(i==end)
                    break;
            }
            sum = 0;
            for( i=end; true; ++i)
            {
                if(i>N)
                    i%=N;
                if(i==start)
                    break;
                sum += A[i];
                if(right_neg2>sum)
                {
                    bottom = i;
                    right_neg2 = sum;
                }
            }
            if(right_neg2 < right_neg1)
            {
                right_neg1 = sum = 0;
                for( i=(start-1); true; --i)
                {
                    if(i==0)
                        i=N;
                    sum += A[i];
                    if(right_neg1>sum)
                        right_neg1 = sum;
                    if(i==end || i==((bottom + 1)==N+1 ? N : (bottom + 1)) )
                        break;
                }   
            }
            else if(right_neg2 > right_neg1)
            {
                sum = right_neg2 = 0;
                for( i=end; true; ++i)
                {
                    if(i>N)
                        i%=N;
                    if(i==start || i==(top))
                        break;
                    sum += A[i];
                    if(right_neg2>sum)
                        right_neg2 = sum;
                }
            }
            else
                right_neg2 = 0;
            System.out.println("r_neg1: " + right_neg1);
            System.out.println("r_neg2: " + right_neg2);
            System.out.println("left_sum: " + left_sum);
            ans = Math.min(ans,left_sum + right_neg1*2 + right_neg2*2);
            System.out.println(ans);
        }
    }
}