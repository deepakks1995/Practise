/*

Userid  @deepakks1995
Problem Code  @CSS2

*/
import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Pair   // class Pair to store pair elements in HashMap
{
    int val;
    int prio;
    public Pair()
    {
        this.val=0;
        this.prio=0;
    }
    public Pair(int val, int prio)
    {
        this.val = val;
        this.prio = prio;
    }
    public int val()  { return val; }
    public int prio() { return prio; }
}

class main
{
    public static void main(String args[]) throws Exception
    {
         // Array of HashMaps
        LinkedHashMap Arr[] = new LinkedHashMap[1000001];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s[];
        s=br.readLine().split(" ");
        int N = Integer.parseInt(s[0]);
        int M = Integer.parseInt(s[1]);
        int id,att,val,prio;
        while(N--!=0)
        {

//Reading Input

            s=br.readLine().split(" ");
            id = Integer.parseInt(s[0]);
            att = Integer.parseInt(s[1]);
            val = Integer.parseInt(s[2]);
            prio = Integer.parseInt(s[3]);

//Checking whether the array contains any Maps in it......

            if(Arr[id]!=null)
            {
                LinkedHashMap<Integer, Pair> map = new LinkedHashMap<Integer, Pair>();
                map = Arr[id];
                if(map.get(att)!=null)
                {
                    Pair p1 = new Pair();
                    p1 = map.get(att);

                    if(p1.prio<=prio)
                    {
                        p1.val=val;
                        p1.prio = prio;
                        Arr[id].put(att,p1);
                    }
                }
                else
                {
                    Pair p = new Pair(val,prio);
                    Arr[id].put(att,p);
                }
            }
            else
            {
                LinkedHashMap<Integer, Pair> map = new LinkedHashMap<Integer, Pair>();
                Pair p = new Pair(val,prio);
                map.put(att,p);
                Arr[id]=map;
            }
        }



        while(M--!=0)
        {
            LinkedHashMap<Integer, Pair> map = new LinkedHashMap<Integer, Pair>();
            s= br.readLine().split(" ");
            id = Integer.parseInt(s[0]);
            att = Integer.parseInt(s[1]);

            map = Arr[id];
            Pair p2 = new Pair();
            p2 = map.get(att);
            System.out.println(p2.val());
        }
    }

}


