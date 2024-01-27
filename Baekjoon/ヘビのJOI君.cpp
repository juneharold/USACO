#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define f first
#define s second
#define ll long long

int N, M, X, temp[10005]={}, visit[10005][205][3]={};
vector<pair<int, int>> graph[10005];
priority_queue<pair<pair<int, int>, pair<int, int>>> pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> X;
    for (int i=1; i<=N; i++) cin >> temp[i];
    for (int i=1; i<=M; i++) {
        int a, b, d; cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }

    fill(&visit[0][0][0], &visit[10004][204][3], 1e9);
    visit[1][0][0]=0;
    pq.push({{0, 1}, {0, 0}});

    while (!pq.empty()) {
        int cur=pq.top().f.s, d=-pq.top().f.f, x=pq.top().s.f, room_type=pq.top().s.s;
        pq.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int nx=graph[cur][i].f, nd=graph[cur][i].s, dt=min(x+nd, X+1);

            if (temp[nx]==0) {
                if ((room_type==0 || dt>=X) && d+nd<visit[nx][0][0]) {
                    visit[nx][0][0]=d+nd;
                    pq.push({{-(d+nd), nx}, {0, 0}});
                }
            }
            if (temp[nx]==1) {
                if (d+nd<visit[nx][dt][room_type]) {
                    visit[nx][dt][room_type]=d+nd;
                    pq.push({{-(d+nd), nx}, {dt, room_type}});
                }
            }
            if (temp[nx]==2) {
                if ((room_type==1 || dt>=X) && d+nd<visit[nx][0][1]) {
                    visit[nx][0][1]=d+nd;
                    pq.push({{-(d+nd), nx}, {0, 1}});
                }
            }
        }
    }

    int ans=1e9;
    for (int i=0; i<=X+1; i++) ans=min(ans, min(visit[N][i][0], visit[N][i][1]));
    cout << ans;
}
