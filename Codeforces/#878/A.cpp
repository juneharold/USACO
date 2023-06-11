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
        int n; cin >> n;
        string S, ans=""; cin >> S;
        int i=0;
        while (i<n) {
            char cur=S[i];
            ans+=cur;
            i++;
            while (S[i]!=cur) i++;
            i++;
        }
        cout << ans << "\n";
    }
}
