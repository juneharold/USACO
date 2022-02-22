#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second
#define ll long long

ll N, M;
pair<ll, ll> comp[300005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> comp[i].f;
    for (int i=1; i<=N; i++) {
        cin >> comp[i].s;
        comp[i].f=max(comp[i].f, comp[i].s);
    }

    ll lo=0, hi=1e18;
    while (lo<hi) {
        ll mid=(lo+hi)/2+1, cnt=N*M;
        for (int i=1; i<=N; i++) {
            if (comp[i].f*M>=mid) {
                ll x=mid/comp[i].f; // x번 듣기.
                if (x*comp[i].f<mid) x++;
                cnt-=x;
            }
            else {
                ll y=mid-M*comp[i].f;
                ll x=y/comp[i].s; //x번 추가적으로 듣기
                if (x*comp[i].s<y) x++;
                cnt-=(x+M);
            }
            if (cnt<0) break;
        }

        if (cnt>=0) lo=mid;
        else hi=mid-1;
    }
    cout << lo;
}

/*
20 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
