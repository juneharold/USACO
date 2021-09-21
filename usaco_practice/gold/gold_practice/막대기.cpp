#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define f first
#define s second

const int MAX_N=1e5+5;
pair<ll, ll> stick[MAX_N];
ll N, L, dp[MAX_N][2]={}, ans=0;
set<ll> ut, ud;
vector<ll> compt, compd;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L;
    for (int i=1; i<=N; i++) {
        cin >> stick[i].f >> stick[i].s;
        if (ut.count(stick[i].f)==0) {
            ut.insert(stick[i].f);
            compt.push_back(stick[i].f);
        }
        if (ud.count(stick[i].s)==0) {
            ud.insert(stick[i].s);
            compd.push_back(stick[i].s);
        }
    }
    sort(stick+1, stick+N+1);
    sort(compt.begin(), compt.end());
    sort(compd.begin(), compd.end());

    for (int i=1; i<=N; i++) {
        int top=lower_bound(compt.begin(), compt.end(), stick[i].f)-compt.begin();
        int down=lower_bound(compd.begin(), compd.end(), stick[i].s)-compd.begin();

        ll length=abs(stick[i].f-stick[i].s)+L;
        ll a=dp[top][1], b=dp[down][0];
        dp[top][1]=max(dp[top][1], b+length);
        dp[down][0]=max(dp[down][0], a+length);

        ans=max({ans, dp[top][1], dp[down][0]});
    }
    cout << ans;
}
