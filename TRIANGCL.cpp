/*
USER_ID @deepakks1995
PROBLEM_CODE @TRIANGCL
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#define diff pow(10,-6)
#define INFY 100000
#define ang (M_PI/2)
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE

    int subtask;
    int t,i;
    int X[3],Y[3];

    cin>>subtask;
    cin>>t;

    long lenA,lenB,lenC,longest;
    string angle,side;

    while(t--)
    {
        side="Scalene";
        angle="";
        longest=lenA=lenB=lenC=0;

        cin>>X[0]>>Y[0];
        cin>>X[1]>>Y[1];
        cin>>X[2]>>Y[2];

        lenA = ( pow((X[0] - X[1]),2) + pow((Y[0] - Y[1]),2) );
        lenB = ( pow((X[2] - X[1]),2) + pow((Y[2] - Y[1]),2) );
        lenC = ( pow((X[0] - X[2]),2) + pow((Y[0] - Y[2]),2) );

        if(abs(sqrt(lenA)-sqrt(lenB))<diff || abs(sqrt(lenA)-sqrt(lenC))<diff || abs(sqrt(lenB)-sqrt(lenC))<diff)
            side = "Isosceles";

        if(subtask==2)
        {
            longest = ( lenA>lenB ) ? ( lenA>lenC ? lenA : lenC ) : ( lenB>lenC ? lenB : lenC) ;

            if(longest == lenA)
            {
                if(lenB+lenC ==longest)
                    angle="right";
                else if(lenC + lenB > longest)
                    angle = "acute";
                else
                    angle = "obtuse";
            }
            else if(longest == lenB)
            {
                if(lenA+lenC ==longest)
                    angle="right";
                else if(lenC + lenA > longest)
                    angle = "acute";
                else
                    angle = "obtuse";
            }
            else if(longest == lenC)
            {
                if(lenB+lenA ==longest)
                    angle="right";
                else if(lenA + lenB > longest)
                    angle = "acute";
                else
                    angle = "obtuse";
            }
            cout<<side<<" "<<angle<<" triangle\n";
        }
        else
            cout<<side<<" triangle\n";
    }
    return 0;
}
