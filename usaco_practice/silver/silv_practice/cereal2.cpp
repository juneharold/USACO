#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

const int MAX=1e5+5;
int N, M, visit[MAX]={}, degree[MAX]={}, traveled[MAX]={}, cow_take[MAX]={};
pair<int, int> want[MAX]={};
vector<pair<int, int>> graph[MAX], order;
vector<int> ans;

void dfs(int cur) {
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i].f, id=graph[cur][i].s;
        //if (visit[want[id].f]==0) visit[want[id].f]=1;
        //else if (visit[want[id].s]==0) visit[want[id].s]=1;
        //else continue;
        if (traveled[id]==0 && (visit[want[id].f]==0 || visit[want[id].s]==0)) {
            if (visit[want[id].f]==0) visit[want[id].f]=1;
            else if (visit[want[id].s]==0) visit[want[id].s]=1;
            ans.push_back(id);
            cow_take[id]=1;
            traveled[id]=1;
            dfs(nx);
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> want[i].f >> want[i].s;
        graph[want[i].f].push_back({want[i].s, i});
        graph[want[i].s].push_back({want[i].f, i});
        degree[want[i].f]++; degree[want[i].s]++;
    }

    for (int i=1; i<=M; i++) {
        if (degree[i]>0) {
            order.push_back({degree[i], i});
        }
    }
    sort(order.begin(), order.end());

    for (int i=0; i<order.size(); i++) {
        dfs(order[i].s);
    }

    //cout << "here\n";
    cout << N-ans.size() << "\n";
    for (auto x: ans) cout << x << "\n";
    //cout << "here\n";
    for (int i=1; i<=N; i++) if (cow_take[i]==0) cout << i << "\n";
}
