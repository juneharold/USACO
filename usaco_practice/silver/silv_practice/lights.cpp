#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define ll long long

struct cmp {
    bool operator() (const bitset<35> &b1, const bitset<35> &b2) const {
        return b1.to_ulong() < b2.to_ulong();
    }
};

ll N, M, n, ans=1e9;
map<bitset<35>, ll, cmp> mp;
vector<ll> graph[40];

void dfs1(ll cur, bitset<35> b, ll cnt) {
    //cout << cur << " " << b << endl;
    if (cur==n) {
        if (mp.find(b)==mp.end() || (mp.find(b)!=mp.end() && cnt<mp[b])) {
            mp[b]=cnt;
        }
        return;
    }
    dfs1(cur+1, b, cnt);
    bitset<35> nb=b;
    nb.flip(cur);
    for (auto nx: graph[cur]) {
        nb.flip(nx);
    }
    dfs1(cur+1, nb, cnt+1);
}

void dfs2(ll cur, bitset<35> b, ll cnt) {
    if (cur==N) {
        bitset<35> flipped=b.flip();
        for (ll i=N; i<35; i++) flipped[i]=0;

        if (mp.find(flipped)!=mp.end()) {
            ans=min(ans, cnt+mp[flipped]);
        }
        return;
    }
    dfs2(cur+1, b, cnt);
    bitset<35> nb=b;
    nb.flip(cur);
    for (auto nx: graph[cur]) {
        nb.flip(nx);
    }
    dfs2(cur+1, nb, cnt+1);
}

int main()
{
    cin >> N >> M;
    for (ll i=1; i<=M; i++) {
        ll a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    n=N/2;

    bitset<35> start;
    start.reset();
    dfs1(0, start, 0);
    start.reset();
    dfs2(n, start, 0);

    cout << ans;
}
