import java.util.*;
import java.net.*;
import java.io.*;
import java.applet.*;
class main {
  public static void main(String args[]) throws Exception   {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());
    ArrayList<Integer> list = null;
    while(T--!=0) {
            int N = Integer.parseInt(br.readLine());
            String s[] = br.readLine().split(" ");
            HashMap<Integer, ArrayList<Integer> > map = new HashMap<Integer, ArrayList<Integer> > ();
            for(int i=0; i<N; ++i) {
                int x = Integer.parseInt(s[i]);
                int Key = findKey(x);
                if(map.containsKey(Key)){
                    list = map.get(Key);
                    list.add(x);
                    map.put(Key, list);
                }
                else {
                    list = new ArrayList<Integer> ();
                    list.add(x);
                    map.put(Key, list);
                }
            }
            boolean check = false;
            for(int i=1; i<=9; ++i)
                if(map.containsKey(i))
                    check = true;
            if(check) {
                for(int j=9; j>=0; --j) {
                    if(map.containsKey(j)) {
                        list = map.get(j);
                        Collections.sort(list);
                        Collections.reverse(list);
                        for(int i=0; i<list.size(); ++i)
                            System.out.print(list.get(i));
                    }
                }
            }
            else System.out.print("0");
            System.out.println();
    }
}
    
    static int findKey(int n) {
        int ans = 0;
        while(n!=0) {
            ans = n;
            n/=10;
        }
        return ans;
    }

}
