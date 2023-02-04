#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main()
{
    vector<int> Ans;
    int T; cin >> T;
    while (T--) {
        int n, c; cin >> n >> c;
        vector<int> costs;
        for (int i=1; i<=n; i++) {
            int a; cin >> a;
            costs.push_back(a+i);
        }
        sort(costs.begin(), costs.end());
        int ans=0;
        for (int cost: costs) {
            if (c>=cost) {
                ans++;
                c-=cost;
            }
            else break;
        }
        cout << ans << "\n";
    }
}