#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
#define f first
#define s second

int main()
{
    int n; cin >> n;
    vector<ll> a(n+1, 0), pfs(n+1, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pfs[i]=pfs[i-1]+a[i];
    }

    vector<pair<int, int>> bounds(n+1, {0, 0});
    stack<int> st;
    for (int i=1; i<=n; i++) {
        while (!st.empty() && a[st.top()]>=a[i]) {
            st.pop();
        }
        if (st.empty()) bounds[i].f=0;
        else bounds[i].f=st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i=n; i>=1; i--) {
        while (!st.empty() && a[st.top()]>=a[i]) {
            st.pop();
        }
        if (st.empty()) bounds[i].s=n;
        else bounds[i].s=st.top()-1;
        st.push(i);
    }

    ll ans=0, l=0, r=0;
    for (int i=1; i<=n; i++) {
        ll temp=(pfs[bounds[i].s]-pfs[bounds[i].f])*a[i];
        if (temp>=ans) {
            ans=temp;
            l=bounds[i].f+1;
            r=bounds[i].s;
        }
    }
    cout << ans << "\n" << l << ' ' << r;
}