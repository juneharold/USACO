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
        int x, k; cin >> x >> k;
        if (x%k==0) {
            cout << 2 << "\n" << x-1 << ' ' << 1 << "\n";
        }
        else cout << 1 << "\n" << x << "\n";
    }
}