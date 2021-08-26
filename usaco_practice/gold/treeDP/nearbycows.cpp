#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define f first
#define s second
const int MAX_N=1e5+5;
int N, K, cows[MAX_N], dp[MAX_N]={};
priority_queue<pair<int, int>> child[MAX_N], parent[MAX_N]; // distance, num_cows
vector<int> graph[MAX_N];

priority_queue<pair<int, int>> down(int cur, int p) {
    if (!child[cur].empty()) return child[cur];

    child[cur].push({0, cows[cur]});

    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx==p) continue;
        priority_queue<pair<int, int>> temp=down(nx, cur);
        while (!temp.empty()) {
            int dist=temp.top().f, sz=temp.top().s;
            temp.pop();
            if (dist==K) continue;
            else {
                child[cur].push({dist+1, sz});
            }
        }
    }
    return child[cur];
}


int main()
{
    cin >> N >> K;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=1; i<=N; i++) cin >> cows[i];

    down(1, 0);
    for (int i=1; i<=N; i++) {
        priority_queue<pair<int, int>> temp=child[i];
        while(!temp.empty()) {
            dp[i]+=temp.top().s;
            temp.pop();
        }
    }

    
}
