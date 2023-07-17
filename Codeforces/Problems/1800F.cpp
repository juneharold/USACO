#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef long long ll;

string s[200005];
int cnt[200005][26]={};
map<pair<int, int>, int> m;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    ll ans=0;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        for (auto x: s[i]) cnt[i][x-'a']++;
    }
    for (int i=1; i<=n; i++) {
        int bin=0;
        for (int j=0; j<26; j++) {
            if (cnt[i][j]==0) {
                int find=0;
                for (int k=0; k<26; k++) {
                    if (k==j) continue;
                    if (cnt[i][k]%2==0) find+=(1<<k);
                }
                if (m.count(make_pair(j, find))) ans+=m[make_pair(j, find)];
            }
            if (cnt[i][j]%2) bin+=(1<<j);
        }
        for (int j=0; j<26; j++) if (cnt[i][j]==0) m[make_pair(j, bin)]++;
    }
    cout << ans;
}
