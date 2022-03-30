#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, K, S[1000005]={}, nxt[1000005]={}, visit[1000005]={}, ans[1000005]={};
vector<long long> path;

void dfs(long long cur) {
    visit[cur]=1;
    path.push_back(cur);
    if (visit[nxt[cur]]==1) {
        long long move=K%path.size();
        for (long long i=0; i<path.size(); i++) {
            long long idx=(i+move)%path.size();
            ans[path[idx]]=S[path[i]];
        }
    }
    else dfs(nxt[cur]);
}

int main()
{
    cin >> N >> K;
    for (long long i=1; i<=N; i++) cin >> S[i];
    for (long long i=1; i<=N; i++) cin >> nxt[i];

    for (long long i=1; i<=N; i++) {
        if (visit[i]==0) {
            dfs(i);
            path.clear();
        }
    }

    for (long long i=1; i<=N; i++) cout << ans[i] << " ";
}
