/*input
6
3 1 8 2 6 4
*/
#include <bits/stdc++.h>
using namespace std;

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int max(int a, int b, int c) {
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int applyDynamic(std::vector<int> v, int start, int end){
    int dp[v.size()][2];
    dp[start][0] = 0;
    dp[start][1] = v[start];
    for (int i = start+1; i < end+1; ++i){
        dp[i][0] = dp[i-1][1];
        // either i-1 gets the desert or i-2 gets the desert if i gets the desert
        dp[i][1] = v[i] + min(dp[i-1][1], dp[i-1][0]);
    }
    return min(dp[end][0], dp[end][1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    std::vector<int> array(N);
    for (int i = 0; i < N; ++i)
        cin>>array[i];
    //King arthur gets his desert
    int ans1 = applyDynamic(array, 1, array.size()-1) + array[0];
    //King arthur does not gets his desert, last knight gets desert
    int ans2 = applyDynamic(array, 0, array.size()-2) + array[array.size()-1];
    cout<<min(ans2, ans1)<<endl;
}