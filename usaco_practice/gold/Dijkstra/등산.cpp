#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const long long MAX_N=1e5+5, MAX_M=2e5+5;
long long v_home[MAX_N]={}, v_uni[MAX_N]={}, h[MAX_N]={};
vector<pair<long long, long long>> edge[MAX_M];
priority_queue<pair<long long, long long>> pq_home, pq_uni;
long long N, M, D, E;

int main()
{
    cin >> N >> M >> D >> E;
    for (long long i=1; i<=N; i++) cin >> h[i];
    for (long long i=1; i<=M; i++) {
        long long a, b, c; cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    //집에서부터 거리 구하기
    fill(&v_home[0], &v_home[MAX_N], 1e18);
    pq_home.push({0, 1});
    v_home[1]=0;
    while (!pq_home.empty()) {
        long long dis=-pq_home.top().first, cur=pq_home.top().second;
        pq_home.pop();

        if (dis>v_home[cur]) continue;

        for (long long i=0; i<edge[cur].size(); i++) {
            long long next=edge[cur][i].first, nd=edge[cur][i].second;
            if (h[next]<=h[cur]) continue;

            if (dis+nd<v_home[next]) {
                v_home[next]=dis+nd;
                pq_home.push({-(dis+nd), next});
            }
        }
    }

    //고대에서부터 거리 구하기.
    fill(&v_uni[0], &v_uni[MAX_N], 1e18);
    pq_uni.push({0, N});
    v_uni[N]=0;
    while (!pq_uni.empty()) {
        long long dis=-pq_uni.top().first, cur=pq_uni.top().second;
        pq_uni.pop();

        if (dis>v_uni[cur]) continue;

        for (long long i=0; i<edge[cur].size(); i++) {
            long long next=edge[cur][i].first, nd=edge[cur][i].second;
            if (h[next]<=h[cur]) continue;

            if (dis+nd<v_uni[next]) {
                v_uni[next]=dis+nd;
                pq_uni.push({-(dis+nd), next});
            }
        }
    }

    //
    long long ans=-1e18;
    for (long long i=2; i<=N-1; i++) {
        if (v_home[i]!=1e18 && v_uni[i]!=1e18) ans=max(ans, h[i]*E-(v_home[i]+v_uni[i])*D);
    }
    if (ans==-1e18) cout << "Impossible";
    else cout << ans;
}
