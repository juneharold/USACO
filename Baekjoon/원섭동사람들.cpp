#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define f first
#define s second
const int nmax=200005;

int N, A[nmax]={}, B[nmax]={}, in[nmax]={}, rsv[nmax]={}, vst[nmax]={}, ans=0;
vector<pair<int, int>> path;

void dfs(int cur) {
    vst[cur]=1;
    path.push_back({cur, max(0, B[cur]-rsv[cur])});
    if (vst[A[cur]]) {
        int mn=1e9, start=-1;
        for (int i=0; i<path.size(); i++) {\
            if (path[i].s<mn) {
                start=path[i].f;
                mn=path[i].s;
            }
        }
        ans+=max(0, B[start]-rsv[start]);
        rsv[A[start]]+=B[start];
        int now=A[start];
        while (now!=start) {
            ans+=max(0, B[now]-rsv[now]);
            rsv[A[now]]+=B[now];
            now=A[now];
        }
        path.clear();
    }
    else dfs(A[cur]);
}

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A[i] >> B[i];
        in[A[i]]++;
    }
    queue<int> q;
    for (int i=1; i<=N; i++) if (in[i]==0) q.push(i);
    while (!q.empty()) {
        int cur=q.front(); q.pop();
        vst[cur]=1;
        ans+=max(0, B[cur]-rsv[cur]);
        rsv[A[cur]]+=B[cur];
        in[A[cur]]--;
        if (in[A[cur]]==0) q.push(A[cur]);
    }
    for (int i=1; i<=N; i++) {
        if (vst[i]==0) dfs(i);
    }
    cout << ans;
}
