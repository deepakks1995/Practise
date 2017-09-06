/* IMPORTANT: Multiple classes and nested static classes are supported */


// * uncomment this if you want to read input.
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


class TestClass {
    public static void main(String args[] ) throws Exception {
        /*
         * Read input from stdin and provide input before running
*/
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s[] = (br.readLine()).split(" ");
        int N = Integer.parseInt(s[0]);
        int Q = Integer.parseInt(s[1]);
        s = br.readLine().split(" ");
        int max=0,min=100000000,num=0;
        for(int i=0;i<N;i++)
        {
            num = Integer.parseInt(s[i]);
            if(max< num )
                max = num;
            if(min > num)
                min = num;
        }
        while(Q--!=0)
        {
            num = Integer.parseInt(br.readLine());
            if(min<=num && num<=max)
                System.out.println("Yes");
            else
                System.out.println("No");
        }

    }
}
