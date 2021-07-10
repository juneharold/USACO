#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=1e4+5;
int n, l, m;
vector<pair<int, int>> fish;

int main()
{
    cin >> n >> l >> m;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        fish.push_back({a, b});
    }

    int ans=0;
    for (auto f: fish) {
        for (int i=1; i<=l/2-1; i++) {
            int hor=i, ver=l/2-i;
            for (int j=f.first-hor; j<=f.first; j++) {
                int cnt=0;
                for (auto temp: fish) {
                    if (j<=temp.first && temp.first<=j+hor && f.second<=temp.second && temp.second<=f.second+ver) {
                        cnt++;
                    }
                }
                ans=max(ans, cnt);
            }
            for (int j=f.first-hor; j<=f.first; j++) {
                int cnt=0;
                for (auto temp: fish) {
                    if (j<=temp.first && temp.first<=j+hor && f.second-ver<=temp.second && temp.second<=f.second) {
                        cnt++;
                    }
                }
                ans=max(ans, cnt);
            }
            for (int j=f.second-ver; j<=f.second; j++) {
                int cnt=0;
                for (auto temp: fish) {
                    if (j<=temp.second && temp.second<=j+ver && f.first<=temp.first && temp.first<=f.first+hor) {
                        cnt++;
                    }
                }
                ans=max(ans, cnt);
            }
            for (int j=f.second-ver; j<=f.second; j++) {
                int cnt=0;
                for (auto temp: fish) {
                    if (j<=temp.second && temp.second<=j+ver && f.first-hor<=temp.first && temp.first<=f.first) {
                        cnt++;
                    }
                }
                ans=max(ans, cnt);
            }
        }
    }
    cout << ans;
}
