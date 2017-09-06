import java.io.*;
import java.util.*;

class Pair
{
	int left,right;
	Pair()
	{
		left = right = 0;
	}
}

class main
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N1,N2;
		String s1[] = br.readLine().split(" ");
		N1 = Integer.parseInt(s1[0]);
		N2 = Integer.parseInt(s1[1]);

		String s,key;
		ArrayList<String> list = new ArrayList<String>();
		for(int i=0; i<N1; ++i)
		{
			s = br.readLine();
			list.add(s);
		}
		int count= 0;
		main m = new main();
		for(int i=0; i< N2 ;++i)
		{
			s = br.readLine();
			for(int j=0; j<N1; ++j)
			{
				if(m.compareFunc(s,list.get(j)))
					count++;
			}
		}
		System.out.println(count);
	}
	public boolean compareFunc(String a, String b)
	{
		int arr[] = new int [26];
		for(int i=0; i<26; ++i)
		{
			arr[i] = 0;
		}
		int ch;
		for(int i=0; i<a.length();++i)
		{
			ch = a.charAt(i);
			ch -= 'A';
			arr[ch] = 1;
		}
		for(int i=0; i<b.length();++i)
		{
			ch = b.charAt(i);
			ch -= 'A';
			arr[ch] = 1;
		}
		for(int i=0;i<26;++i)
			if(arr[i]==0)
				return false;
		return true;
	}
}