#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void query(vector<int> &q, vector<int> &res) {
    cout << "? " << q.size() << ' ';
    for (int x: q) cout << x << ' ';
    cout << "\n";
    cout.flush();

    int cnt, x; cin >> cnt;
    for (int i=1; i<=cnt; i++) {
        cin >> x;
        res.push_back(x);
    }
}

int n, N;
vector<int> check_ans(vector<int> &dp) {
    vector<int> ret;
    int cur=n+1;
    for (int i=1; i<=N; i++) {
        if (dp[i]==cur && dp[i]!=dp[i+1]) {
            ret.push_back(i);
            cur--;
        }
    }
    return ret;
}

void solve() {
    cin >> n;
    N=n*n+1;
    vector<int> unknown(N+5, 1), dp(N+5, 0);
    vector<vector<int>> results(n+1);
    for (int i=1; i<=n; i++) {
        vector<int> q, res;
        for (int j=1; j<=N; j++) if (unknown[j]) q.push_back(j);
        //cout << "hello1" << endl;
        query(q, res);
        //cout << "hello2" << endl;

        int idx=res.size()-1;
        for (int j=N; j>=1; j--) {
            //cout << "j: " << j << endl;
            dp[j]=dp[j+1];
            if (idx>=0 && res[idx]==j) {
                dp[j]=dp[j+1]+1;
                idx--;
            }
        }
        //cout << "hello3" << endl;

        vector<int> ans=check_ans(dp);
        if (!ans.empty()) {
            cout << "! ";
            for (int x: ans) cout << x << ' ';
            cout << "\n";
            cout.flush();
            return;
        }

        for (int x: res) unknown[x]=0;

        results[i]=res;
    }

    vector<int> ans;
    results[n].push_back(N+1);
    for (int i=results[n].size()-2; i>=0; i--) {
        bool found=false;
        for (int j=results[n][i]+1; j<results[n][i+1]; j++) {
            if (unknown[j]) {
                ans.push_back(j);
                ans.push_back(results[n][i]);
                found=true;
                break;
            }
        }
        if (found) break;
    }
    for (int i=n-1; i>=0; i--) {
        for (int j=results[i].size()-1; j>=0; j--) {
            if (results[i][j]<ans.back()) {
                ans.push_back(results[i][j]);
                break;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << "! ";
    for (int x: ans) cout << x << ' ';
    cout << "\n";
    cout.flush();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
