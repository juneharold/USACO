#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> p(n+1, 0), loc(n+1, 0);
        for (int i=1; i<=n; i++) {
            cin >> p[i];
            loc[p[i]]=i;
        }
        if ((loc[1]<loc[n] && loc[n]<loc[2]) || (loc[2]<loc[n] && loc[n]<loc[1])) {
            cout << "1 1\n";
        }
        else if (loc[n]<loc[1] && loc[1]<loc[2]) {
            cout << loc[n] << ' ' << loc[1] << "\n";
        }
        else if (loc[n]<loc[2] && loc[2]<loc[1]) {
            cout << loc[n] << ' ' << loc[2] << "\n";
        }
        else if (loc[1]<loc[2] && loc[2]<loc[n]) {
            cout << loc[n] << ' ' << loc[2] << "\n";
        }
        else if (loc[2]<loc[1] && loc[1]<loc[n]) {
            cout << loc[1] << ' ' << loc[n] << "\n";
        }
    }
}
