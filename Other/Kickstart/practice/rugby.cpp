#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define f first
#define s second

pair<ll, ll> loc[100005]={};

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.s==b.s) return a.f<b.f;
    return a.s<b.s;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N; cin >> N;
        for (int i=0; i<N; i++) cin >> loc[i].f >> loc[i].s;

        ll ans=0;
        sort(&loc[0], &loc[N]);
        for (int i=0; i<N; i++) loc[i].f-=i;
        sort(&loc[0], &loc[N]);
        for (int i=0; i<N; i++) ans+=abs(loc[i].f-loc[N/2].f);
        sort(&loc[0], &loc[N], cmp);
        for (int i=0; i<N; i++) ans+=abs(loc[i].s-loc[N/2].s);

        cout << "Case #" << t << ": " << ans << "\n";
        fill(&loc[0], &loc[N], make_pair(0, 0));
    }
}
