#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
각 점에서 어디 점으로 이동할 수 있는지 확인.
dfs로 갈 수 있는 점 찾기.
*/

struct moocast {
    int x, y, p;
};
moocast cow[205];

int visit[205]={};
vector <int> graph[205];
void dfs(int cur) {
    visit[cur]=1;
    for (int i=0; i<graph[cur].size(); i++) {
        int next=graph[cur][i];
        if (visit[next]==0) dfs(next);
    }
}


int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cow[i].x >> cow[i].y >> cow[i].p;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int d = abs(cow[i].x-cow[j].x)*abs(cow[i].x-cow[j].x) + abs(cow[i].y-cow[j].y)*abs(cow[i].y-cow[j].y);
            if (d<=cow[i].p*cow[i].p) {
                graph[i].push_back(j);
            }
        }
    }
    int ans=0;
    for (int i=0; i<n; i++) {
        dfs(i);
        int cnt=0;
        for (int j=0; j<205; j++) if (visit[j]==1) cnt++;
        if (cnt>ans) ans=cnt;
        fill(&visit[0], &visit[205], 0);
    }
    cout << ans;
}
