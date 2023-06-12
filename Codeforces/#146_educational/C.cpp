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
#include <numeric>
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
        ll n, s1, s2; cin >> n >> s1 >> s2;
        vector<pair<int, int>> arr1; 
        for (int i=0; i<n; i++) {
            int r; cin >> r;
            arr1.push_back({r, i+1});
        }
        sort(arr1.begin(), arr1.end());
        vector<pair<int, int>> arr2;
        for (int i=1; i<=n; i++) arr2.push_back({s1*i, 1});
        for (int i=1; i<=n; i++) arr2.push_back({s2*i, 2});
        sort(arr2.begin(), arr2.end());
        
        vector<int> a, b;
        int idx=0;
        for (int i=n-1; i>=0; i--) {
            if (arr2[idx].second==1) a.push_back(arr1[i].second);
            else b.push_back(arr1[i].second);
            idx++;
        }

        cout << a.size() << ' ';
        for (int x: a) cout << x << ' ';
        cout << "\n";
        cout << b.size() << ' ';
        for (int x: b) cout << x << ' ';
        cout << "\n";
    }
}
