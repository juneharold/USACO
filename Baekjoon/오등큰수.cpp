#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a(n, 0), cnt(1000001, 0), ans(n, 0);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    stack<pair<int, int>> s;
    for (int i=n-1; i>=0; i--) {
        while (!s.empty() && s.top().first<=cnt[a[i]]) s.pop();
        if (s.empty()) ans[i]=-1;
        else ans[i]=s.top().second;
        s.push({cnt[a[i]], a[i]});
    }
    for (int i=0; i<n; i++) cout << ans[i] << ' ';
}