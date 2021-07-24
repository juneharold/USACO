#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=1005;
int n, w;
int dp[MAX][2]={};
pair<int, int> cases[MAX];
vector<int> seq;

int main()
{
    cin >> n >> w;
    for (int i=1; i<=w; i++) cin >> cases[i].first >> cases[i].second;

    pair<int, int> p1={1, 1}, p2={n, n};

    for (int i=1; i<=w; i++) {
        int dist1=abs(p1.first-cases[i].first)+abs(p1.second-cases[i].second);
        int dist2=abs(p2.first-cases[i].first)+abs(p2.second-cases[i].second);
        if (dist1==dist2) {

        }
        else if (dist1<dist2) {
            dp[i]=dp[i-1]+dist1;
            p1=cases[i];
            seq.push_back(1);
        }
        else if (dist1>dist2) {
            dp[i]=dp[i-1]+dist2;
            p2=cases[i];
            seq.push_back(2);
        }
    }
    cout << dp[w] << "\n";
    //for (int i=1; i<=w; i++) cout << dp[i] << " ";
    for (auto x: seq) cout << x << "\n";
}
