import java.util.*;
import java.io.*;
import java.util.Arrays;
class main
{
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N,K,temp,t = Integer.parseInt(br.readLine());
        String s[];
        double sum;
        while(t--!=0)
        {
            sum=0;
            s = br.readLine().split(" ");
            N = Integer.parseInt(s[0]);
            K = Integer.parseInt(s[1]);
            s = br.readLine().split(" ");
            int A[] = new int[N];
            for(int i=0; i<N; i++)
                A[i] = Integer.parseInt(s[i]);
            Arrays.sort(A);
           /* for (int i = 0; i < N-1; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    if (A[i] > A[j])
                    {
                        temp = A[i];
                        A[i] = A[j];
                        A[j] = temp;
                    }
                }
            }*/
            /*for(int i=0 ; i<N; i++)
                System.out.print(A[i] + " ");*/
            for(int i = K ; i<=N-1-K ; i++)
            {
                sum += A[i];
                //System.out.println("Sum: " + sum);
            }
            sum/=(N-2*K);
            System.out.println(sum);
        }
    }
}
