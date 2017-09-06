#include<iostream>
#include<string>
#include<assert.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
    string A;
   // cin>>A;
    while(getline(cin,A))
    {
        int i,j,l,count;
        l=A.length();
        int a[300]={'\0'};
        for(i=0;i<l;i++)
        {
            a[i]=A[i];
        }
        int b[300]={'\0'},check=0,k=0,y=1;
        for(i=0;i<l;i++)
        {
            check=0;
            count=0;
            if(y==1)
            {
                for(j=0;j<l;j++)
                {
                    if(a[i]==a[j])
                    {
                        count+=1;
                        check=1;
                    }
                }
                if(check==1)
                {
                    b[k]=a[i];
                    k+=1;
                }
            //printing the numbers
           /* if(count>9)
            {
                int n=count/9;
                for(i=0;i<n;i++)
                {
                    cout<<"9"<<(char)a[i];
                }
                cout<<(count-n*9)<<(char)a[i];
            }
            else*/
                    cout<<count<<"!"<<(char)a[i]<<"\n";

            }
            y=1;
            for(int m=0;m<k;m++)
            {
                if(a[i]==b[m])
                    y=0;
            }
        }
    }
    return 0;
}
