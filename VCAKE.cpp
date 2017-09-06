/*input
7
4 5 5 3 12
4 5 10 4 6
4 5 6 10 4
4 5 4 6 10
2 2 2 2 2
0 0 0 0 0
4 5 13 7 0
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long R,C,arr[3],i,j,C1,R1,a2,a1,a0,C2,R2;
    while(t--)
    {
        bool check=0,check1a=0,check2a=0,check3a=0,check4a=0,check5a=0,check6a=0;;
        cin>>R>>C>>arr[0]>>arr[1]>>arr[2];
        C2=C;
        R2=R;
        if((R*C> arr[0]+arr[1]+arr[2]) || (R*C < arr[0]+arr[1]+arr[2]))
            check=1;
        else
        {
            sort(arr,arr+3);
            a2=arr[2];
            a1=arr[1];
            a0=arr[0];
            if(C && R && arr[2]%C==0 && arr[2]%R!=0 )
            {
                if(C)
                    R-=arr[2]/C;
                if(C && R && arr[1]%R==0 && arr[1]%C!=0)
                {
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R!=0 )
                {
                    if(C)
                        R-=arr[1]/C;    
                    if(R*C!=arr[0])
                        check=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R==0 )
                {
                    bool check2=0,check3=0;
                    C1=C;
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check2=1;

                    C=C1;
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check3=1;
                    if(check2 && check3)
                        check=1;
                }
                else if(R==0 || C==0)
                {
                    if(arr[1]+arr[0]!=0)
                        check=1;
                }
                else
                    check=1;
            }

            else if(C && R && arr[2]%R==0 && arr[2]%C!=0 )
            {
                if(R)
                    C-=arr[2]/R;
                if(C && R && arr[1]%R==0 && arr[1]%C!=0)
                {
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R!=0 )
                {
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R==0 )
                {
                    bool check2=0,check3=0;
                    C1=C;
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check2=1;

                    C=C1;
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check3=1;
                    if(check2 && check3)
                        check=1;
                }
                else if(R==0 || C==0)
                {
                    if(arr[1]+arr[0]!=0)
                        check=1;
                }
                else
                    check=1;
            }
            else if(C && R && arr[2]%R==0 && arr[2]%C==0)
            {
                bool check21=0,check31=0;

                R1=R;
                if(C)
                    R-=arr[2]/C;
                if(C && R && arr[1]%R==0 && arr[1]%C!=0 )
                {
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check21=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R!=0 )
                {
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check21=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R==0 )
                {
                    bool check2=0,check3=0;
                    C1=C;
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check2=1;

                    C=C1;
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check3=1;

                    if(check2 && check3)
                        check21=1;
                }
                else if(R==0 || C==0)
                {
                    if(arr[1]+arr[0]!=0)
                        check=1;
                }
                else
                    check21=1;

                R=R1;
                if(R)
                C-=arr[2]/R;
                if(C && R && arr[1]%R==0 && arr[1]%C!=0 )
                {
                    if(R)
                    C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check31=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R!=0 )
                {
                    if(C)
                    R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check31=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R==0 )
                {
                    bool check2=0,check3=0;
                    C1=C;
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check2=1;

                    C=C1;
                    if(C)
                    R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check3=1;
                    if(check2 && check3)
                        check31=1;
                }
                else if(R==0 || C==0)
                {
                    if(arr[1]+arr[0]!=0)
                        check=1;
                }
                else
                    check31=1;

                if(check21 && check31)
                    check=1;
            }
            else if(R==0 || C==0)
            {
                if(arr[2]+arr[1]+arr[0]!=0)
                    check=1;
            }
            else
                check=1;



check1a=check;
check=0;
arr[2]=a1;
arr[1]=a2;
arr[0]=a0;
C=C2;
R=R2;

            if(C && R && arr[2]%C==0 && arr[2]%R!=0 )
            {
                
                if(C)
                    R-=arr[2]/C;
                if(C && R && arr[1]%R==0 && arr[1]%C!=0)
                {
                                 
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R!=0 )
                {
                    if(C)
                        R-=arr[1]/C;    
                    if(R*C!=arr[0])
                        check=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R==0 )
                {
                                    
                    bool check2=0,check3=0;
                    C1=C;
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check2=1;

                    C=C1;
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check3=1;
                    if(check2 && check3)
                        check=1;
                }
                else if(R==0 || C==0)
                {
                                  
                    if(arr[1]+arr[0]!=0)
                        check=1;
                }
                else
                {
                                   
                    check=1;
                }
            }

            else if(C && R && arr[2]%R==0 && arr[2]%C!=0 )
            {
                              
                if(R)
                    C-=arr[2]/R;
                if(C && R && arr[1]%R==0 && arr[1]%C!=0)
                {
                                   
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R!=0 )
                {
                                                   
                    if(C)
                        R-=arr[1]/C;

                    if(R*C!=arr[0])
                        check=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R==0 )
                {
                                                      
                    bool check2=0,check3=0;
                    C1=C;
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check2=1;

                    C=C1;
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check3=1;
                    if(check2 && check3)
                        check=1;
                }
                else if(R==0 || C==0)
                {
                                                     
                    if(arr[1]+arr[0]!=0)
                        check=1;
                }
                else
                {
                           
                    check=1;
                }
            }
            else if(C && R && arr[2]%R==0 && arr[2]%C==0)
            {
                                               
                bool check21=0,check31=0;

                R1=R;
                if(C)
                    R-=arr[2]/C;
                if(C && R && arr[1]%R==0 && arr[1]%C!=0 )
                {
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check21=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R!=0 )
                {
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check21=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R==0 )
                {
                    bool check2=0,check3=0;
                    C1=C;
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check2=1;

                    C=C1;
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check3=1;

                    if(check2 && check3)
                        check21=1;
                }
                else if(R==0 || C==0)
                {
                    if(arr[1]+arr[0]!=0)
                        check=1;
                }
                else
                    check21=1;

                R=R1;
                if(R)
                C-=arr[2]/R;
                if(C && R && arr[1]%R==0 && arr[1]%C!=0 )
                {
                    if(R)
                    C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check31=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R!=0 )
                {
                    if(C)
                    R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check31=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R==0 )
                {
                    bool check2=0,check3=0;
                    C1=C;
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check2=1;

                    C=C1;
                    if(C)
                    R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check3=1;
                    if(check2 && check3)
                        check31=1;
                }
                else if(R==0 || C==0)
                {
                    if(arr[1]+arr[0]!=0)
                        check=1;
                }
                else
                    check31=1;

                if(check21 && check31)
                    check=1;
            }
            else if(R==0 || C==0)
            {
                if(arr[2]+arr[1]+arr[0]!=0)
                    check=1;
            }
            else
                check=1;



check2a=check;
check=0;
arr[2]=a0;
arr[1]=a1;
arr[0]=a2;
C=C2;
R=R2;

            if(C && R && arr[2]%C==0 && arr[2]%R!=0 )
            {
                if(C)
                    R-=arr[2]/C;
                if(C && R && arr[1]%R==0 && arr[1]%C!=0)
                {
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R!=0 )
                {
                    if(C)
                        R-=arr[1]/C;    
                    if(R*C!=arr[0])
                        check=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R==0 )
                {
                    bool check2=0,check3=0;
                    C1=C;
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check2=1;

                    C=C1;
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check3=1;
                    if(check2 && check3)
                        check=1;
                }
                else if(R==0 || C==0)
                {
                    if(arr[1]+arr[0]!=0)
                        check=1;
                }
                else
                    check=1;
            }

            else if(C && R && arr[2]%R==0 && arr[2]%C!=0 )
            {
                if(R)
                    C-=arr[2]/R;
                if(C && R && arr[1]%R==0 && arr[1]%C!=0)
                {
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R!=0 )
                {
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R==0 )
                {
                    bool check2=0,check3=0;
                    C1=C;
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check2=1;

                    C=C1;
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check3=1;
                    if(check2 && check3)
                        check=1;
                }
                else if(R==0 || C==0)
                {
                    if(arr[1]+arr[0]!=0)
                        check=1;
                }
                else
                    check=1;
            }
            else if(C && R && arr[2]%R==0 && arr[2]%C==0)
            {
                bool check21=0,check31=0;

                R1=R;
                if(C)
                    R-=arr[2]/C;
                if(C && R && arr[1]%R==0 && arr[1]%C!=0 )
                {
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check21=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R!=0 )
                {
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check21=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R==0 )
                {
                    bool check2=0,check3=0;
                    C1=C;
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check2=1;

                    C=C1;
                    if(C)
                        R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check3=1;

                    if(check2 && check3)
                        check21=1;
                }
                else if(R==0 || C==0)
                {
                    if(arr[1]+arr[0]!=0)
                        check=1;
                }
                else
                    check21=1;

                R=R1;
                if(R)
                C-=arr[2]/R;
                if(C && R && arr[1]%R==0 && arr[1]%C!=0 )
                {
                    if(R)
                    C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check31=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R!=0 )
                {
                    if(C)
                    R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check31=1;
                }
                else if(C && R && arr[1]%C==0 && arr[1]%R==0 )
                {
                    bool check2=0,check3=0;
                    C1=C;
                    if(R)
                        C-=arr[1]/R;
                    if(R*C!=arr[0])
                        check2=1;

                    C=C1;
                    if(C)
                    R-=arr[1]/C;
                    if(R*C!=arr[0])
                        check3=1;
                    if(check2 && check3)
                        check31=1;
                }
                else if(R==0 || C==0)
                {
                    if(arr[1]+arr[0]!=0)
                        check=1;
                }
                else
                    check31=1;

                if(check21 && check31)
                    check=1;
            }
            else if(R==0 || C==0)
            {
                if(arr[2]+arr[1]+arr[0]!=0)
                    check=1;
            }
            else
                check=1;



check3a=check;
check=0;
if(check1a && check2a && check3a)
    check=1;






        }

        if(check)
            cout<<"No";
        else cout<<"Yes";
        cout<<endl;
    }
}

