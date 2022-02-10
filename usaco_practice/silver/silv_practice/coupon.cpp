#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long

ll N, K, M;
pair<ll, ll> price[100005]={};
set<pair<ll, ll>> s;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.s==b.s) return a.f<=b.f;
    return a.s<b.s;
}

int main()
{
    cin >> N >> K >> M;
    for (ll i=1; i<=N; i++) cin >> price[i].f >> price[i].s;
    sort(&price[1], &price[N+1], cmp);

    ll ind=1, spent=0, cnt=0;
    while (ind<=min(K, N)) {
        if (spent+price[ind].s<=M) {
            s.insert({price[ind].f-price[ind].s, ind});
            spent+=price[ind].s;
            cnt++;
            ind++;
        }
        else break;
    }

    while (ind<=N) {
        ll p=1e18, cow;
        if (!s.empty()) {
            p=(*s.begin()).f;
            cow=(*s.begin()).s;
        }

        if (spent+p+price[ind].s<spent+price[ind].f && spent+p+price[ind].s<=M) {
            s.erase(s.begin());
            s.insert({price[ind].f-price[ind].s, ind});
            spent+=p+price[ind].s;
            cnt++;
            ind++;
        }
        else if (spent+price[ind].f<=spent+p+price[ind].s && spent+price[ind].f<=M) {
            spent+=price[ind].f;
            cnt++;
            ind++;
        }
        else if (spent+price[ind].f<=M) {
            spent+=price[ind].f;
            cnt++;
            ind++;
        }
        else ind++;
    }

    cout << cnt;
}

/*
3 2 6
2 1
2 1
8 2

7 2 20
4 1
3 3
6 2
5 2
10 1
12 8
5 4
*/
