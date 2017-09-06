
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.awt.*;
import java.net.*;

class Main
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		String s[];
		int Q,ans;
		boolean check;
		String indian = "INDIAN";
		while(T--!=0)
		{
			check = false;
			ans = 0;
			s = br.readLine().split(" ");
			Q = Integer.parseInt(s[0]);
			if(s[1].equals(indian))
				check = true;
				while(Q--!=0)
				{
					s = br.readLine().split(" ");
					if(s[0].equals("CONTEST_WON"))
					{
						ans += 300;
						if(Integer.parseInt(s[1])<20)
							ans += 20 - Integer.parseInt(s[1]);
					}
					else if(s[0].equals("TOP_CONTRIBUTOR"))
						ans += 300;
					else if(s[0].equals("BUG_FOUND"))
						ans += Integer.parseInt(s[1]);
					else
						ans += 50;
				}
				if(check)
					ans /= 200;
				else ans /= 400;
			System.out.println(ans);
		}
	}
}