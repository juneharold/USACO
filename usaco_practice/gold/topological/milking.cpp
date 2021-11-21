#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> input[50005];
int N, M, ans[100005]={};

bool check (int X) {
    vector<int> adj[100005];
    int indegree[100005]={};

    for (int i=0; i<X; i++) {
        for (int j=1; j<input[i].size(); j++) {
            adj[input[i][j-1]].push_back(input[i][j]);
            indegree[input[i][j]]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=1; i<=N; i++) {
        if (indegree[i]==0) pq.push(i);
    }

    if (pq.empty()) return false;

    int idx=0;
    while(!pq.empty()) {
        idx++;
        int cur=pq.top(); pq.pop();
        ans[idx]=cur;

        for (int i=0; i<adj[cur].size(); i++) {
            int nx=adj[cur][i];
            indegree[nx]--;
            if (indegree[nx]==0) pq.push(nx);
        }
    }

    if (idx!=N) return false;
    return true;
}

int main()
{
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int k; cin >> k;
        for (int j=0; j<k; j++) {
            int v; cin >> v;
            input[i].push_back(v);
        }
    }

    int lo=0, hi=M-1;
    while (lo<hi) {
        int mid=(lo+hi)/2+1;
        if (check(mid)) lo=mid;
        else hi=mid-1;
    }

    for (int i=1; i<=N; i++) cout << ans[i] << " ";
}
