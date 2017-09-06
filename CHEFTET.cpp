/*  Accepted
*   User_ID @deepakks1995
*   Problem_Code @CHEFTET
*/


#include <iostream>
#include <algorithm>
#define size 10001
using std::cin;
using std::cout;
using std::endl;

long N,i,j;
long long A[size],B[size],max[4];
int index[size],t;
bool check1,check2,check3,check0;

bool solve(long long );
bool set_zero(long long );

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        check1 = check2 = check3 = check0 = 0;
        for(i=0; i<N; i++)
            index[i] = 0;
        cin>>N;
        for(i=0; i<N; i++)
            cin>>B[i];
        for(i=0; i<N; i++)
            cin>>A[i];

        max[0]=A[0];
        max[1]=B[0]+A[0];

        if(N>1)
        {
            max[2]=B[1]+A[0];
            max[3]=B[0]+B[1]+A[0];
            std::sort(max,max+4);

            check3 = solve(max[3]);

            if(!check3)
            {
                check2 = solve(max[2]);
                if(!check2)
                {
                    check1 = solve(max[1]);
                    if(!check1)
                        check0 = solve(max[0]);
                }
            }
        }
        else
        {
            check3 = check2 = 0;
            std::sort(max,max+2);
            check1 = solve(max[1]);
            if(!check1)
                check0 = solve(max[0]);
        }

        if(check3)
            cout<<max[3];
        else if(check2)
            cout<<max[2];
        else if(check1)
            cout<<max[1];
        else if(check0)
            cout<<max[0];
        else
            cout<<"-1";
        cout<<endl;
    }
}


bool solve(long long max)
{
    long long value;
    for(i=0; i<N; i++)
    {
        if(i>0 && !index[i-1])
        {
            value = A[i] + B[i-1];
            index[i-1]=1;
        }
        else
            value = A[i];

        if(value>max)
        {
            set_zero(i);
            return 0;
        }
        else if(value == max)
            continue;
        else if (!index[i] && ( B[i] + value == max ) )
            index[i] = 1;
        else if(i<N && !index[i+1] && ( B[i+1] + value == max ) )
            index[i+1] = 1;
        else if(i>0 && !index[i-1] && !index[i] && ( B[i] + B[i-1] + value == max ) )
            index[i] = index[i-1] = 1;
        else if(i<N && !index[i] && !index[i+1] && ( B[i] + B[i+1] + value == max ) )
            index[i] = index[i+1] = 1;
        else if(i<N && i>0 && !index[i-1] && !index[i] && !index[i+1] && ( B[i-1] + B[i] + B[i+1] + value == max ) )
            index[i-1] = index[i] = index[i+1] = 1;
        else
        {
            set_zero(i);
            return 0;
        }
    }
    if(!set_zero(N-1))
        return 1;
    else return 0;
}

bool set_zero(long long id)
{
    bool flag=0;
    for(j=0;j<=id;j++)
    {
        if(!index[j])
            flag = 1;
        index[j] = 0;
    }
    return flag;
}