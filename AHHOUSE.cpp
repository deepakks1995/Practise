
#include <iostream>
#include <vector>
#define INT_MAX (int) 9999999
using namespace std;

int PF[11][11], PT[11][11];
int N,M;

std::vector<pair<int, int> > calculateAdjacentnodes(int, int );
void applyDijkstra();
int ReadInt();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int t = ReadInt();
    while(t--)
    {
        N = ReadInt();
        M = ReadInt();
        for(int i=0; i<N; ++i)
            for(int j=0; j<M; ++j)
                PF[i][j] = ReadInt();
        for(int i=0; i<N; ++i)
            for(int j=0; j<M; ++j)
                PT[i][j] = ReadInt();
        applyDijkstra();
    }
}

/**
Modified Dijkstra Algorithm (Applied on Grid Problem)
Here each cell is treated as a node as instead of Adjacency List manual adjacent nodes are provided
in form of vector array
**/
void applyDijkstra()
{
    int V = N*M;
    int dist[N][M], dist2[N][M];
    bool sptSet[N][M];
    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
        {
            dist[i][j] = dist2[i][j] = INT_MAX;
            sptSet[i][j] = false;
        }
    dist[0][0] = PF[0][0];
    dist2[0][0] = PT[0][0];

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            /* Leave last node as it cannot be treated as source */
            if(i == N-1 && j == M-1)
                continue;
            /*Calculating minimum distance values across the nodes*/
            int min_value = INT_MAX, min_index1 = -1, min_index2 = -1;
            for(int itr=0; itr<N; ++itr)
                for(int itr2=0; itr2<M; ++itr2)
                {
                    if(!sptSet[itr][itr2])
                    {
                        if(min_value > dist[itr][itr2])
                        {
                            min_value = dist[itr][itr2];
                            min_index1 = itr;
                            min_index2 = itr2;
                        }
                    }
                }
            sptSet[min_index1][min_index2] = true;

            /*Calculating adjacent nodes for the node with minimum value*/
            std::vector<pair<int, int> > pairs = calculateAdjacentnodes(min_index1, min_index2);

            /*Applying Dijkstra on adjacent nodes*/
            for(int itr = 0; itr<pairs.size(); ++itr)
            {
                int index1 = pairs[itr].first;
                int index2 = pairs[itr].second;
                if(!sptSet[index1][index2] && dist[min_index1][min_index2] != INT_MAX && dist[min_index1][min_index2] + PF[index1][index2] <= dist[index1][index2])
                {
                    dist[index1][index2] = dist[min_index1][min_index2] + PF[index1][index2];
                    if(dist2[min_index1][min_index2] != INT_MAX && dist2[index1][index2] > dist2[min_index1][min_index2] + PT[index1][index2] )
                        dist2[index1][index2] = dist2[min_index1][min_index2] + PT[index1][index2];
                }
            }
        }
    }
    cout<<dist[N-1][M-1]<<" "<<dist2[N-1][M-1]<<endl;
}

std::vector<pair<int, int> > calculateAdjacentnodes(int min_index1, int min_index2)
{
    std::vector<pair<int, int> > pairs;
    if(min_index1 > 0 && min_index1 < N-1 && min_index2 > 0 && min_index2 < M-1)
    {
        pairs.push_back(make_pair(min_index1-1, min_index2));
        pairs.push_back(make_pair(min_index1+1, min_index2));
        pairs.push_back(make_pair(min_index1, min_index2-1));
        pairs.push_back(make_pair(min_index1, min_index2+1));
    }
    else if((min_index1 == 0 || min_index1 == N-1 ) && min_index2 > 0 && min_index2 < M-1)
    {
        pairs.push_back(make_pair(min_index1,min_index2-1));
        pairs.push_back(make_pair(min_index1,min_index2+1));
        if(min_index1 == 0 && 0 != N-1 )
            pairs.push_back(make_pair(min_index1+1,min_index2));
        else if(min_index1 == N-1 && 0!= N-1)
            pairs.push_back(make_pair(min_index1-1,min_index2));
    }
    else if((min_index2 == 0 || min_index2 == M-1) && min_index1 > 0 && min_index1 < N-1)
    {
        pairs.push_back(make_pair(min_index1-1,min_index2));
        pairs.push_back(make_pair(min_index1+1,min_index2));
        if(min_index2 == 0 && 0 != M-1)
            pairs.push_back(make_pair(min_index1,min_index2+1));
        else if(min_index2 == M-1 && 0 != M-1)
            pairs.push_back(make_pair(min_index1,min_index2-1));
    }
    else if(min_index1 == 0 && min_index2 == 0)
    {
        if(0 != N-1)
            pairs.push_back(make_pair(min_index1+1,min_index2));
        if(0 != M-1)
            pairs.push_back(make_pair(min_index1,min_index2+1));
    }
    else if(min_index1 == 0 && min_index2 == M-1)
    {
        if(0 != N-1)
            pairs.push_back(make_pair(min_index1+1,min_index2));
        if(0 != M-1)
            pairs.push_back(make_pair(min_index1,min_index2-1));
    }
    else if(min_index1 == N-1 && min_index2 == 0)
    {
        if(0 != N-1)
            pairs.push_back(make_pair(min_index1-1,min_index2));
        if(0 != M-1)
            pairs.push_back(make_pair(min_index1,min_index2+1));
    }
    else if(min_index1 == N-1 && min_index2 == M-1)
    {
        if(0 != N-1)
            pairs.push_back(make_pair(min_index1-1,min_index2));
        if(0 != M-1)
            pairs.push_back(make_pair(min_index1,min_index2-1));
    }
    return pairs;
}


int ReadInt()
{
    register int ch = getchar_unlocked();
    int temp = 0;
    while(ch<'0' || ch>'9')			ch = getchar_unlocked();
    while(ch>='0' && ch<='9')
    {
        temp = (temp<<3) + (temp<<1) + ch-48;
        ch = getchar_unlocked();
    }
    return temp;
}
