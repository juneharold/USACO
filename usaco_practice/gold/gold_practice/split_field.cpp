#include <iostream>
#include <algorithm>
#include <set>
#define ll long long
#define f first
#define s second
using namespace std;
const ll MAX=5e4+5;

ll N, fw[MAX]={};
pair<ll, ll> pos[MAX];
multiset <ll> ys, xs;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) { return a.s<b.s; }

int main()
{
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    cin >> N;

    ll up=1, down=1e18, left=1e18, right=1, og_area=0;
    for (ll i=0; i<N; i++) {
        cin >> pos[i].f >> pos[i].s;
        up=max(up, pos[i].s);
        down=min(down, pos[i].s);
        left=min(left, pos[i].f);
        right=max(right, pos[i].f);
        ys.insert(pos[i].s);
        xs.insert(pos[i].f);
    }
    og_area=(up-down)*(right-left);

    sort(&pos[0], &pos[N]);

    ll ans=0;
    ll u1=0, d1=1e18, l1=1e18, r1=0;


    for (ll i=0; i<N-1; i++) { //i번째까지 왼쪽 포함
        l1=min(l1, pos[i].f);
        r1=max(r1, pos[i].f);
        u1=max(u1, pos[i].s);
        d1=min(d1, pos[i].s);
        ll area1=(u1-d1)*(r1-l1);

        auto del=ys.find(pos[i].s);
        if (del!=ys.end()) ys.erase(del);

        ll l2=pos[i+1].f, r2=pos[N-1].f;
        auto it=ys.begin();
        ll d2=(*it);
        it=ys.end();
        ll u2=(*--it);

        ll area2=(u2-d2)*(r2-l2);

        if (r1==l2 && (u1==d2 || u2==d1)) continue;
        ans=max(ans, og_area-area1-area2);
    }

    u1=0; d1=1e18; l1=1e18; r1=0;
    for (int i=0; i<N; i++) swap(pos[i].f, pos[i].s);
    sort(&pos[0], &pos[N]);

    for (ll i=0; i<N-1; i++) { //i번째까지 왼쪽 포함
        l1=min(l1, pos[i].f);
        r1=max(r1, pos[i].f);
        u1=max(u1, pos[i].s);
        d1=min(d1, pos[i].s);
        ll area1=(u1-d1)*(r1-l1);

        auto del=xs.find(pos[i].s);
        if (del!=xs.end()) xs.erase(del);

        ll l2=pos[i+1].f, r2=pos[N-1].f;
        auto it=xs.begin();
        ll d2=(*it);
        it=xs.end();
        ll u2=(*--it);

        ll area2=(u2-d2)*(r2-l2);

        if (r1==l2 && (u1==d2 || u2==d1)) continue;
        ans=max(ans, og_area-area1-area2);
    }

    cout << ans;
}
