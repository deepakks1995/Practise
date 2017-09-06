import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class main
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer("");
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();
        long long int l,i,k=0;
        long long int count;
        int track;
        int flag=0;
        while(t--!=0)
        {
            String L1[] = br.readLine();
            String L2[] = br.readLine();
            l=L1.length();
            count=0;
            flag=0;
            k=0;
            //Track=1 if chef follows L1 string and Track=2 if chef follows L2 string
            if((L1[0]=='#' && L2[0]=='#'))
                System.out.println("No");
            else if(L1[0]=='.'  && L2[0]=='#')
            {
                flag=0;
                track=1;
                k=0;
                while(k<l)
                {
                    if(track==1)
                    {
                        if(L1[k]=='#')
                        {
                            if(L2[k]=='#')
                                flag=1;
                            else if(L2[k]=='.')
                            {
                                count++;
                                track=2;
                            }
                        }
                    }
                    else if(track==2)
                    {
                        if(L2[k]=='#')
                        {
                            if(L1[k]=='#')
                                flag=1;
                            else if(L1[k]=='.')
                            {
                                count++;
                                track=1;
                            }
                        }
                    }
                    if(flag==1)
                        break;
                    k++;
                }
                if(flag==1)
                    System.out.println("No");
                else
                {
                    System.out.println("Yes");
                    System.out.println(count);
                }
            }
            else if(L2[0]=='.'  && L1[0]=='#')
            {
                flag=0;
                track=2;
                k=0;
                while(k<l)
                {
                    if(track==1)
                    {
                        if(L1[k]=='#')
                        {
                            if(L2[k]=='#')
                                flag=1;
                            else if(L2[k]=='.')
                            {
                                count++;
                                track=2;
                            }
                        }
                    }
                    else if(track==2)
                    {
                        if(L2[k]=='#')
                        {
                            if(L1[k]=='#')
                                flag=1;
                            else if(L1[k]=='.')
                            {
                                count++;
                                track=1;
                            }
                        }
                    }
                    if(flag==1)
                        break;
                    k++;
                }
                if(flag==1)
                    System.out.println("No");
                else
                {
                    System.out.println("Yes");
                    System.out.println(count);
                }
            }

            else
            {
                for(i=0; i<l; i++)
                    if(L1[i]=='#')
                        break;
                for(k=0; k<l; k++)
                    if(L2[k]=='#')
                        break;
                if(i==l && k==l)
                {
                    System.out.println("Yes");
                    System.out.println("0");
                }

                else if(i==k && i!=l)
                    System.out.println("No");
                else if(i<k)
                {
                    flag=0;
                    track=2;
                    k=0;
                    while(k<l)
                    {
                        if(track==1)
                        {
                            if(L1[k]=='#')
                            {
                                if(L2[k]=='#')
                                    flag=1;
                                else if(L2[k]=='.')
                                {
                                    count++;
                                    track=2;
                                }
                            }
                        }
                        else if(track==2)
                        {
                            if(L2[k]=='#')
                            {
                                if(L1[k]=='#')
                                    flag=1;
                                else if(L1[k]=='.')
                                {
                                    count++;
                                    track=1;
                                }
                            }
                        }
                        if(flag==1)
                            break;
                        k++;
                    }
                    if(flag==1)
                        System.out.println("No");
                    else
                    {
                        System.out.println("Yes");
                        System.out.println(count);
                    }
                }
                else
                {
                    flag=0;
                    track=1;
                    k=0;
                    while(k<l)
                    {
                        if(track==1)
                        {
                            if(L1[k]=='#')
                            {
                                if(L2[k]=='#')
                                    flag=1;
                                else if(L2[k]=='.')
                                {
                                    count++;
                                    track=2;
                                }
                            }
                        }
                        else if(track==2)
                        {
                            if(L2[k]=='#')
                            {
                                if(L1[k]=='#')
                                    flag=1;
                                else if(L1[k]=='.')
                                {
                                    count++;
                                    track=1;
                                }
                            }
                        }
                        if(flag==1)
                            break;
                        k++;
                    }
                    if(flag==1)
                        System.out.println("No");
                    else
                    {
                        System.out.println("Yes");
                        System.out.println(count);
                    }
                }
            }
        }
    }
}