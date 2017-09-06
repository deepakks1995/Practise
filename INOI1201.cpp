/*
*   User_ID @deepakks1995
*   Problem_Code @INOI1201
*/

#include <iostream>
using namespace std;

int N,i,j;
int arr[1000000][3],temp,ans;

void counting_sort();
void print();
int read();

int main()
{
    ios_base::sync_with_stdio(false);
    N = read();
    for(i=0; i<N; i++)      {   arr[i][0] = read();     arr[i][1] = read();     arr[i][2] = read();     arr[i][1] += arr[i][2];     }
    counting_sort();
    ans = j = 0;
    for(i=0; i<N; i++)      {   j += arr[i][0];     temp = j + arr[i][1];       ans = max(temp,ans);        }
    cout<<ans<<endl;
}

int read()
{
    int temp;
    register int ch = getchar_unlocked();
    while(ch<'0' || ch>'9')     {   ch = getchar_unlocked();    }
    while(ch>='0' && ch<='9')   {   temp = (temp<<3) + (temp<<1) + ch -'0';     ch = getchar_unlocked();    }
    return temp;
}

void counting_sort()
{
    int k = 10000;
    int C[k];
    for(i=0;i<k;i++)
        C[i]=0;
    int B[N][2];
    for(i=0; i<N ; i++)                         {   C[arr[i][1]]++; }
    for( i=1; i<k; i++)                         {   C[i] = C[i] + C[i-1];   }
    for( i=N-1; i>=0; i--)                      {   B[C[arr[i][1]]-1][1] = arr[i][1];   B[C[arr[i][1]]-1][0] = arr[i][0];   C[arr[i][1]]--; }
    for(i = 0,j=N-1 ; i<= N-1 ; j--, i++)       {   arr[i][0] = B[j][0];    arr[i][1] = B[j][1];    }
}

void print()
{
    for(i=0;i<N;i++)
    {
        cout<<endl;
        for (j = 0; j < 2; ++j)     {   cout<<arr[i][j]<<" ";   }
    }
    cout<<endl;
}