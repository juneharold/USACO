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
        int n; cin >> n;
        vector<int> p;
        p.push_back(0);
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            p.push_back(x);
        }

        vector<int> ans;

        int l, r;
        if (p[n]==n) {
            r=n, l=n;
            for (int i=n-1; i>1; i--) {
                if (p[i]>p[1]) l=i;
                else break;
            }

            for (int i=r; i>=l; i--) ans.push_back(p[i]);
            for (int i=1; i<=l-1; i++) ans.push_back(p[i]);
        }
        else if (p[1]==n) {
            int idx=-1;
            for (int i=1; i<=n; i++) if (p[i]==n-1) idx=i;

            if (idx==n) {
                ans.push_back(n-1);
                for (int i=1; i<=n-1; i++) ans.push_back(p[i]);
            }
            else {
                r=idx-1, l=idx-1;
                for (int i=idx-2; i>1; i--) {
                    if (p[i]>p[1]) l=i;
                    else break;
                }
                for (int i=r+1; i<=n; i++) ans.push_back(p[i]);
                for (int i=r; i>=l; i--) ans.push_back(p[i]);
                for (int i=1; i<=l-1; i++) ans.push_back(p[i]);
            }
        }
        else {
            int idx=-1;
            for (int i=1; i<=n; i++) if (p[i]==n) idx=i;
            r=idx-1, l=idx-1;
            for (int i=idx-2; i>1; i--) {
                if (p[i]>p[1]) l=i;
                else break;
            }
            for (int i=r+1; i<=n; i++) ans.push_back(p[i]);
            for (int i=r; i>=l; i--) ans.push_back(p[i]);
            for (int i=1; i<=l-1; i++) ans.push_back(p[i]);
        }

        // print answer

        for (int i=0; i<n; i++) cout << ans[i] << ' ';
        cout << "\n";
    }
}
