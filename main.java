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
        int t = Integer.parseInt(br.readLine());
        HashMap<Integer,Integer> map;
        String s[];
        while(t--!=0)
        {
            map = new HashMap<Integer,Integer>();
            int N = Integer.parseInt(br.readLine());
            int count=0,i=0;
            s = br.readLine().split(" ");
            while(N--!=0)
            {
                int k = Integer.parseInt(s[i++]);
                if(map.get(k%10)==null)
                    map.put(k%10,k);
                else
                    count++;
            }
        System.out.println(count);
        }
    }
}
