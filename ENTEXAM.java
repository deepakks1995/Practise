/*
/* User_Id @deepakks
/* Problem_Code @ENTEXAM
/*
/*****************************************/


import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;



class TestClass
{
    public static void main(String args[] ) throws Exception
    {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int N,K,E,M,min;
        long total,temp;
        String s[];
        while(T--!=0)
        {
            int check=0;
            s = br.readLine().split(" ");
            N = Integer.parseInt(s[0]);
            K = Integer.parseInt(s[1]);
            E = Integer.parseInt(s[2]);
            M = Integer.parseInt(s[3]);
            long num[] = new long [N-1];
            for(int i=0; i<N-1; i++)
            {
                s = br.readLine().split(" ");
                for(int j=0; j<E; j++)
                    num[i] += Integer.parseInt(s[0]);
            }
            Arrays.sort(num);/*
    		for(int i=0;i<N-1;i++)
    			System.out.print(num[i]+" ");*/
            for(int i=0; i<(N-1)/2; ++i)
            {
                temp = num[i];
                num[i] = num[N-1 - i - 1];
                num[N-1 - i -1] = temp;
            }/*
    		System.out.println();
    		for(int i=0;i<N-1;i++)
    			System.out.print(num[i]+" ");*/
            s = br.readLine().split(" ");
            total = 0;
            for(int i=0; i<E-1; i++)
                total += Integer.parseInt(s[i]);
            if(total > num[K-1] )
                System.out.println(0);
            else 
            {
                if(num[K-1]-total>=M)
                    System.out.println("Impossible");
                else System.out.println(num[K-1] - total + 1);
            }
        }
    }
}
