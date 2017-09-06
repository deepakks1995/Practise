
#include <iostream>
#include <vector>
#define max_size 100005
#define gc getchar_unlocked
 
int t,N,i,j;
int A[max_size],count;
int id[max_size],id2[max_size];
std::vector<int> vec(max_size);

inline int read();

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    t = read();
    while(t--)
    {
        vec.resize(0);
        count = 0;
        N = read();
        for(i=0; i<N; ++i)
        {
            A[i] = read();
            id2[i] =  id[i] = 0;
        }
        for(i=0; i<N; ++i)
        {
            if(id2[i] == 0)
            {
                id[i] = 1;
                for(j=i;;)
                {
                    j+=A[j] + 1;
                    if(j>=N)                                j%=N;
                    vec.push_back(j);
                    if(id[j] || id2[j]==1)              {   id[j] =2;       break;      }
                    if(id2[j] ==2 )                         break;
                    id[j] = 1;
                }
                if(id[i] == 2)
                    for(j=0;j<vec.size();++j)           {   id2[vec[j]] = 1;    ++count;    id[vec[j]] = 0;     }
                else
                {
                    id2[i] = 2;
                    for(j=0;j<vec.size();++j)               id[vec[j]] = 0;
                }
                vec.resize(0);
            }
        }
        std::cout<<count<<std::endl;
    }
}

inline int read()
{
    int temp=0;
    register int ch = gc();
    while(ch<'0' || ch>'9')     {   ch = gc();    }
    while(ch>='0' && ch<='9')   {   temp = (temp<<3) + (temp<<1) + ch -'0';     ch = gc();    }
    return temp;
}