#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    long long R,G,B,i,K,max,min,mid;
    while(t--)
    {
        cin>>R>>G>>B>>K;
        max = R >= G ? ( R >= B ? R : B ) : ( G >= B ? G : B );
        min = R <= G && R <= B ? R : ( G <= B ? G : B );
        mid = ( (max==R && min==B) ? G : ( (max==R && min==G) ? B : ( (max==G && min==B) ? R : ( (max==G && min==R) ? B : ( (max==B && min==R) ? G : R )))));
        if( K <= min )
            cout<<( 3*(K-1)+1 )<<endl;
        else if( K > min && K <= mid )
            cout<< (3*min + 2*(K-min-1) + 1)<<endl;
        else
            cout<<(3*min + 2*(mid-min) + K-mid)<<endl;

    }
}
