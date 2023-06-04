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
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7;

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n; 
        vector<int> b(n+1, 0); 
        for (int i=1; i<=n; i++) cin >> b[i];

        vector<int> lmax(n+1, -1e9), rmax(n+1, -1e9);
        for (int i=2; i<=n; i++) lmax[i]=max(b[i-1]+i-1, lmax[i-1]);
        for (int i=n-1; i>=2; i--) rmax[i]=max(b[i+1]-(i+1), rmax[i+1]);

        int ans=0;
        for (int i=2; i<=n-1; i++) {
            ans=max(ans, b[i]+lmax[i]+rmax[i]);
        }
        cout << ans << "\n";
    }
}

/*
1
7
5 1 2 1 3 3 5
*/