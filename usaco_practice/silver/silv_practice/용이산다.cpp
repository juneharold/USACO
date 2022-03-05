#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define f first
#define s second

int event[1000005]={}, uniq[1000005]={}, water[1000005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        priority_queue<pair<int, int>> pq; //큰 게 앞에
        priority_queue<int> reserves[1000005];
        vector<int> ans;

        int n, m; cin >> n >> m;
        for (int i=1; i<=m; i++) {
            cin >> event[i];
            if (event[i]!=0) {
                if (uniq[event[i]]==0) {
                    pq.push({-i, event[i]});
                    uniq[event[i]]=1;
                }
                else {
                    reserves[event[i]].push(-i);
                }
            }
        }

        fill(&water[1], &water[n+1], 1);
        bool solve=true;
        for (int i=1; i<=m; i++) {
            if (event[i]==0 && !pq.empty()) {
                water[pq.top().s]=0;
                ans.push_back(pq.top().s);
                pq.pop();
            }
            else if (event[i]==0 && pq.empty()) {
                ans.push_back(0);
            }
            else if (event[i]!=0 && water[event[i]]>0) {
                solve=false;
                break;
            }
            else if (event[i]!=0 && water[event[i]]==0) {
                water[event[i]]=1;
                if (!reserves[event[i]].empty()) {
                    pq.push({reserves[event[i]].top(), event[i]});
                    reserves[event[i]].pop();
                }
            }
        }

        if (solve) {
            cout << "YES\n";
            for (auto x: ans) cout << x << " ";
            cout << "\n";
        }
        else {
            cout << "NO\n";
        }

        fill (&uniq[0], &uniq[1000001], 0);
    }
}
