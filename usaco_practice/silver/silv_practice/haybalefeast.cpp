#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long

const ll MAX=1e5+5;
ll N, M, pfs[MAX];
pair<ll, ll> F[MAX]={}, S[MAX]={};

int main()
{
    cin >> N >> M;
    for (ll i=1; i<=N; i++) {
        cin >> F[i].f >> S[i].f;
        S[i].s=i; F[i].s=i;
    }
    for (ll i=1; i<=N; i++) pfs[i]=pfs[i-1]+F[i].f;

    set<ll> s;
    ll ans=1e18;
    sort(&S[1], &S[N+1]);
    for (int i=N; i>=1; i--) {
        ll start, end;
        auto ub=s.upper_bound(S[i].s);
        if (ub==s.begin() && ub==s.end()) {
            end=N;
            start=0;
        }
        else if (ub==s.end()) {
            end=N;
            start=*--ub;
        }
        else if (ub==s.begin()) {
            start=0;
            end=*ub;
        }
        else {
            end=*ub;
            start=*--ub;
        }

        ll sum=pfs[end]-pfs[start];
        if (sum>=M) ans=min(ans, S[i].f);

        s.insert(S[i].s);
    }


    cout << ans;
}

/*
8 27
5 8
5 20
5 7
5 13
5 15
5 4
5 25
5 30
*/
