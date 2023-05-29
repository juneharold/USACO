#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define f first
#define s second
#define ll long long
#define MOD 1000000007

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt=1, ans=1;
        char prev=s[0];
        for (int i=1; i<n; i++) {
            if (s[i]!=prev) {
                cnt=1;
            }
            else {
                cnt++;
            }
            ans=max(ans, cnt);
            prev=s[i];
        }
        cout << ans+1 << "\n";
    }
}