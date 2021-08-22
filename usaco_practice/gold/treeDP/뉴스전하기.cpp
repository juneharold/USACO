#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N=55;
int N, dp[MAX_N]={};
vector<int> graph[MAX_N];

bool cmp(int a, int b) {
    return a > b;
}

int solve(int cur) {
    if (dp[cur]!=0) return dp[cur];
    vector <int> res;
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        res.push_back(solve(nx));
    }

    sort(res.begin(), res.end(), cmp);
    for (int i=0; i<res.size(); i++) {
        dp[cur]=max(dp[cur], res[i]+i+1);
    }
    return dp[cur];
}


int main()
{
    cin >> N;
    int minsik; cin >> minsik;
    for (int i=1; i<=N-1; i++) {
        int a; cin >> a;
        if (a==-1) continue;
        graph[a].push_back(i);
    }
    //fill(&dp[0], &dp[MAX_N], -1);
    cout << solve(0);
}

/*
10
-1
0
0
1
2
2
3
5
5
6
*/
