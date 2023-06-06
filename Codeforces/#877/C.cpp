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

bool isPrime(int x) {
    if (x<=1) return false;
    for (int i=2; i*i<=x; i++) {
        if (x%i==0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> out(n+1, vector<int>(m+1, 0));
        int idx=2;
        for (int i=1; i<=n/2; i++) {
            for (int j=1; j<=m; j++) {
                out[idx][j]=(i-1)*m+j;
            }
            idx+=2;
        }
        idx=1;
        for (int i=n/2+1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                out[idx][j]=(i-1)*m+j;
            }
            idx+=2;
        }

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) cout << out[i][j] << ' ';
            cout << "\n";
        }
        cout << "\n";
    }
}
// 6, 12, 18, 24, 25 