#include <iostream>
using namespace std;
long long MOD = 1e9+7;
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
typedef std::set<int> set_type;
typedef std::set<set_type> powerset_type;

powerset_type powerset(set_type const& set)
{
    typedef set_type::const_iterator set_iter;
    typedef std::vector<set_iter> vec;
    typedef vec::iterator vec_iter;

    struct local
    {
        static int dereference(set_iter v)
        {
            return *v;
        }
    };

    powerset_type result;

    vec elements;
    do
    {
        set_type tmp;
        std::transform(elements.begin(), elements.end(),
                       std::inserter(tmp, tmp.end()),
                       local::dereference);
        result.insert(tmp);
        if (!elements.empty() && ++elements.back() == set.end())
        {
            elements.pop_back();
        }
        else
        {
            set_iter iter;
            if (elements.empty())
            {
                iter = set.begin();
            }
            else
            {
                iter = elements.back();
                ++iter;
            }
            for (; iter != set.end(); ++iter)
            {
                elements.push_back(iter);
            }
        }
    }
    while (!elements.empty());

    return result;
}


void multiply(long long F[2][2], long long M[2][2]);

void power(long long F[2][2], long long n);

long long fib(long long n)
{
    long long F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1);
    return F[0][0];
}

void power(long long F[2][2], long long n)
{
    if( n == 0 || n == 1)
        return;
    long long M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);

    if (n%2 != 0)
        multiply(F, M);
}

void multiply(long long F[2][2], long long M[2][2])
{
    long long x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    long long y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    long long z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    long long w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}


long long pow(long long a, long long b)
{
    long long temp;
    if( b==0 )
        return 1;
    temp = pow(a,b/2);
    if( b%2==0 )
        return ( temp * temp ) ;
    else
        return (temp  *  temp  * a ) ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long N,M,L,R,i;
    cin>>N>>M;
    string s;
    long long A[N],sum,ans;
    for(i=0; i<N; i++)
        cin>>A[i];
    while(M--)
    {
        cin>>s>>L>>R;
        if(s[0]=='C')
            A[L-1]=R;
        else
        {
            sum=0;
            ans=0;
            set_type test_set(A+L-1, A+R);
            powerset_type test_powerset = powerset(test_set);
            for (powerset_type::iterator iter = test_powerset.begin();
                    iter != test_powerset.end();
                    ++iter)
            {
                sum=0;
                for (set_type::iterator iter2 = iter->begin();
                        iter2 != iter->end();
                        ++iter2)
                {
                    sum += *iter2;

                }

                ans=(ans%MOD+fib(sum)%MOD)%MOD;
            }
            cout<<ans<<endl;
        }
    }
}
