#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define f first
#define s second
typedef long long ll;

ll a[1000005]={}, n, ans=0;
pair<ll, ll> border[1000005];

void solve() {
    stack<ll> st;
    for (int i=1; i<=n; i++) {
        while (!st.empty() && a[st.top()]>a[i]) {st.pop();}
        if (st.empty()) border[i].f=1;
        else border[i].f=st.top()+1;
        st.push(i);
    }
    while (!st.empty()) {st.pop();}
    for (int i=n; i>=1; i--) {
        while (!st.empty() && a[st.top()]>=a[i]) {st.pop();}
        if (st.empty()) border[i].s=n;
        else border[i].s=st.top()-1;
        st.push(i);
    }
    for (int i=1; i<=n; i++) {
        ans-=(border[i].s-i+1)*(i-border[i].f+1)*a[i];
    }
}

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    solve();
    for (int i=1; i<=n; i++) a[i]=-a[i];
    solve();
    cout << ans;
}