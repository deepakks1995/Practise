import java.util.*;
import java.net.*;
import java.io.*;
import java.applet.*;
class main {
    static int arr[];
    static int temp[];
    static int N;
    public static void main(String args[]) throws Exception{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      N = Integer.parseInt(br.readLine());
      main ob = new main();
      arr = new int[N];
      temp = new int[N];
      do{
        String s[] = br.readLine().split(" ");
        for(int i=0; i<N; ++i) {
          arr[i] = Integer.parseInt(s[i]);
          temp[i] = arr[i];
        }
      }
      while(false);
      ob.merge_sort(0,N-1);
      for(int i=0; i<N; ++i)
        System.out.print(arr[i] + " ");
   }
  void merge_sort(int lo, int hi) {
    main ob = new main();
      if(lo<hi){
        int mid = (lo + hi)/2;
        
        ob.merge_sort(lo,mid);
        ob.merge_sort(mid+1, hi);
        ob.merge(lo, mid, hi);
      }
    }

   void merge(int lo, int mid, int hi) {
      /*System.out.println("lo " + lo);
      System.out.println("mide " + mid);
      System.out.println("hi " + hi);*/
      int k = lo, left = lo,right = mid+1;
      while(true) {
        if(left>mid || right > hi)
          break;
        if(Math.abs(temp[left]) < Math.abs(temp[right])) {
          arr[k] = temp[left];
          ++left;++k;
        }
        else {
          arr[k] = temp[right];
          ++right;++k;
        }
      }
      while(left<=mid) {
        arr[k] = temp[left];
        ++left;++k;
      }
      while(right <= hi) {
        arr[k] = temp[right];
        ++right;++k;
      }
      for(int i=lo; i<=hi; ++i)
        temp[i] = arr[i];/*
      for(int i=0; i<N; ++i)
        System.out.print(arr[i] + " ");
      System.out.println();*/
   }
}

