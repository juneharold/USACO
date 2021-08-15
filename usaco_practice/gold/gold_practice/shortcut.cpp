#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long
const int MAX_N=1e4+5, MAX_M=5e4+5;
ll N, M, T, c[MAX_N], p[MAX_N], passing[MAX_N]={}, visit[MAX_N]={};
priority_queue<pair<ll, ll>> pq;
vector<pair<ll, ll>> edge[MAX_M];

int main()
{
    cin >> N >> M >> T;
    for (int i=1; i<=N; i++) cin >> c[i];
    for (int i=1; i<=M; i++) {
        ll a, b, t; cin >> a >> b >> t;
        edge[a].push_back({b, t});
        edge[b].push_back({a, t});
    }

    fill(&visit[0], &visit[MAX_N], 1e9);
    fill(&p[0], &p[MAX_N], -1);
    pq.push({0, 1});
    visit[1]=0;
    while (!pq.empty()) {
        ll cur=pq.top().second, time=-pq.top().first;
        pq.pop();

        if (visit[cur]>time) continue;

        for (int i=0; i<edge[cur].size(); i++) {
            ll next=edge[cur][i].first, nt=edge[cur][i].second;
            if (time+nt<visit[next] || (time+nt==visit[next] && cur<p[next])) {
                p[next]=cur;
                visit[next]=time+nt;
                pq.push({-(time+nt), next});
            }
        }
    }

    for (int k=1; k<=N; k++) {
        int i=k;
        while (i!=-1) {
            passing[i]+=c[k];
            i=p[i];
        }
    }

    ll ans=0;
    for (int k=1; k<=N; k++) {
        ans=max(ans, passing[k]*(visit[k]-T));
    }
    cout << ans;
}
