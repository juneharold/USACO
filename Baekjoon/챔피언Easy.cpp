#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int nmax=200005;

int a[nmax]={}, mn[nmax]={};

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    if (N==1) {
        cout << 1;
        exit(0);
    }

    for (int i=N-1; i>=1; i--) {
        mn[i]=max(a[i+1]+1, mn[i+1]-1);
    }

    vector<int> candidates;
    for (int i=1; i<=N; i++) {
        if (a[i]!=a[1] && a[i]!=a[i+1]) {
            ll power=a[i]+i-1;
            if (power>=mn[i]) candidates.push_back(a[i]);
        }
    }

    vector<int> ans;
    int idx=0;
    for (int i=1; i<=N; i++) {
        if (idx<candidates.size() && a[i]==candidates[idx]) {
            ans.push_back(i);
            idx++;
        }
    }
    if (ans.empty()) cout << -1;
    else for (int x: ans) cout << x << ' ';
}
