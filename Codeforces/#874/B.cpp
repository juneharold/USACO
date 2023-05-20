#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
#define f first
#define s second

int main()
{
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> a; 
        vector <int> b; 
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            a.push_back(make_pair(x, i));
        }
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<int> ans;
        for (int i=0; i<n; i++) ans.push_back(0);

        for (int i=0; i<n; i++) {
            ans[a[i].s]=b[i];
        }

        for (int i=0; i<n; i++) cout << ans[i] << ' ';
        cout << "\n";
    }
}
