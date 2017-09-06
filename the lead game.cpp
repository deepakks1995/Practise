#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
     int N;
     scanf("%d",&N);
     int p,q,p1=0,p2=0;
     int maxA=0,maxB=0,temp=0;
     while(N--)
     {
         scanf("%d%d",&p,&q);
         p1+=p;
         p2+=q;
         if(p1>p2)
         {
             temp=p1-p2;
             if(maxA<temp)
                 maxA=temp;
         }
         else if(p2>p1)
         {
             temp=p2-p1;
             if(maxB<temp)
                maxB=temp;
         }
     }
     if(maxA>maxB)
        printf("\n1 %d",maxA);
     else if(maxB>maxA)
        printf("\n2 %d",maxB);
     return 0;
}
