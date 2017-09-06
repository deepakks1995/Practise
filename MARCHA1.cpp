#include<iostream>
using namespace std;
bool find(int set[], int N, int M)
{
    bool arr[M+1][N+1];
    for (int i = 0; i <= N; i++)
      arr[0][i] = true;
    for (int i = 1; i <= M; i++)
      arr[i][0] = false;
     for (int i = 1; i <= M; i++)
     {
       for (int j = 1; j <= N; j++)
       {
         arr[i][j] = arr[i][j-1];
         if (i >= set[j-1])
           arr[i][j] = arr[i][j] || arr[i - set[j-1]][j-1];
       }
     }
     return arr[M][N];
}
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        int N,M;
        cin>>N>>M;
        int A[N];
        for(i=0;i<N;i++)
            cin>>A[i];
        if(find(A, N, M))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
