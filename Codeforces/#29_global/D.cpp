#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void remove_from_set(map<ll, ll> &cnt, set<pii> &merge, set<pii> &not_merge, ll val) {
    if (cnt.find(val)==cnt.end()) return;
    not_merge.erase({cnt[val], val});
    merge.erase({cnt[val], val});
}

void add_to_set(map<ll, ll> &cnt, set<pii> &merge, set<pii> &not_merge, ll val) {
    if (cnt.find(val)==cnt.end()) return;
    if (cnt.count(val-1)) merge.insert({cnt[val], val});
    else not_merge.insert({cnt[val], val});
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];

    ll sum=0;
    map<ll, ll> cnt;
    for (ll i=1; i<=n; i++) {
        cnt[a[i]]++;
        sum+=a[i];
    }

    set<pii> merge, not_merge;
    for (auto x: cnt) {
        if (cnt.find(x.fs-1)!=cnt.end()) {
            merge.insert({x.sc, x.fs});
        }
        else {
            not_merge.insert({x.sc, x.fs});
        }
    }

    ll turn=0;
    ll score[2]={};

    while (!(not_merge.empty() && merge.empty())) {
        ll c, v, d, prev;
        if (!not_merge.empty()) {
            auto temp=*--not_merge.end();
            c=temp.fs, v=temp.sc;

            auto it=cnt.find(v);
            if (it!=cnt.begin()) {
                it--;
                prev=it->fs;
            }
            else prev=0;
        }
        else {
            auto temp=*--merge.end();
            c=temp.fs, v=temp.sc;
            prev=v-1;
        }
        d=v-prev;
        score[turn]+=(d+1)/2*c;
        score[1-turn]+=d/2*c;

        if (d%2) turn=1-turn;
        
        // remove
        remove_from_set(cnt, merge, not_merge, v);
        remove_from_set(cnt, merge, not_merge, v+1);
        if (prev>0) {
            remove_from_set(cnt, merge, not_merge, prev);
            remove_from_set(cnt, merge, not_merge, prev+1);
        }

        cnt.erase(v);
        if (prev>0) cnt[prev]+=c;

        // add 
        add_to_set(cnt, merge, not_merge, v);
        add_to_set(cnt, merge, not_merge, v+1);
        if (prev>0) {
            add_to_set(cnt, merge, not_merge, prev);
            add_to_set(cnt, merge, not_merge, prev+1);
        }
    }
    cout << score[0] << ' ' << score[1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
