#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int nxt[500005]={}, in[500005]={}, visit[500005]={}, mafia[500005]={};

void solve(queue<int> q){
    while (!q.empty()) {
        int cur=q.front(); q.pop();
        if (mafia[cur]==0 && visit[nxt[cur]]!=2) {
            visit[cur]=2; //mafia
            mafia[nxt[cur]]=1;
        }
        else visit[cur]=1;
        in[nxt[cur]]--;
        if (in[nxt[cur]]==0) q.push(nxt[cur]);
    }
}

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> nxt[i];
        in[nxt[i]]++;
    }

    queue<int> q;
    for (int i=1; i<=N; i++) if (in[i]==0) q.push(i);
    solve(q);

    for (int i=1; i<=N; i++) {
        if (in[i]==1 && mafia[i]==1) {
            in[i]--;
            q.push(i);
            solve(q);
        }
    }
    for (int i=1; i<=N; i++) {
        if (in[i]==1) {
            in[i]--;
            q.push(i);
            solve(q);
        }
    }

    int ans=0;
    for (int i=1; i<=N; i++) if (visit[i]==2) ans++;
    cout << ans;
}

/*
4
2
3
4
1

6
3
4
4
5
6
3
*/
