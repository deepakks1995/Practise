#include<iostream>
using namespace std;
static long GCD(long a, long b)
{
  long r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long A,B,ans;
        cin>>A>>B;
        ans = GCD(A,B);
        cout<<ans<<" ";
        ans = (A*B)/ans;
        cout<<ans<<endl;
    }
}
