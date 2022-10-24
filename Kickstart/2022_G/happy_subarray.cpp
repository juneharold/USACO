#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define ll long long
#define f first
#define s second
#define pii pair<ll, ll>

ll A[400005]={}, pfs[400005]={}, pfs2[400005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll T; cin >> T;
    for (ll t=1; t<=T; t++) {
        ll N; cin >> N;
        for (ll i=1; i<=N; i++) {
            cin >> A[i];
            pfs[i]=pfs[i-1]+A[i];
        }
        for (ll i=1; i<=N; i++) {
            pfs2[i]=pfs2[i-1]+pfs[i];
        }
        stack<ll> s; //큰거 위로
        ll ans=0;
        for (ll i=N; i>=1; i--) {
            if (pfs[i]>=pfs[i-1]) {
                while (!s.empty()) {
                    if (pfs[i-1]>pfs[s.top()]) break;
                    else s.pop();
                }
                if (s.empty()) {
                    ans+=pfs2[N]-pfs2[i-1]-pfs[i-1]*(N-i+1);
                }
                else {
                    ans+=pfs2[s.top()-1]-pfs2[i-1]-pfs[i-1]*(s.top()-i);
                }
            }
            s.push(i);
        }

        cout << "Case #" << t << ": " << ans << "\n";
        for (ll i=1; i<=N; i++) {
            A[i]=0;
            pfs[i]=0;
            pfs2[i]=0;
        }
    }
}
/*
1
3
1 2 -4

1
5
1 -2 3 -2 4


1
4
1 -1 1 -1
*/
