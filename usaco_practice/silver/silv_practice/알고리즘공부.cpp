#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define f first
#define s second

const int MAX=1e5+5;
int N, M, R, k[MAX], used[MAX]={};
vector<pair<int, int>> adj[MAX];
multiset<pair<int, int>> ms;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> k[i];
        ms.insert({k[i], i});
    }
    cin >> R;
    for (int i=1; i<=R; i++) {
        int a, b, d; cin >> a >> b >> d;
        adj[a].push_back({b, d});
    }

    int cnt=0, ans=0;
    while (cnt<M) {
        int cur=(*ms.begin()).f, ind=(*ms.begin()).s;
        ms.erase(ms.begin());
        ans=max(ans, cur);
        cnt++; used[ind]=1;

        for (auto x: adj[ind]) {
            int nx=x.f, w=x.s;
            if (used[nx]==1) continue;
            auto it=ms.find({k[nx], nx});
            ms.erase(it);
            k[nx]-=w;
            ms.insert({k[nx], nx});
        }
    }

    cout << ans;
}
