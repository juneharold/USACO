#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAX_N=1e5+5;
int N, dp[MAX_N]={};
vector<int> graph[MAX_N];
set<int> coin_comb[MAX_N];

void find_coins(int cur, int p) {
    int max1=0, max2=0;
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx==p) continue;

        find_coins(nx, cur);

        if (coin_comb[nx].empty()) continue;
        set<int>::iterator it=coin_comb[nx].end();
        it--;
        int choice=*it;
        coin_comb[cur].insert(choice);
        if (choice>=max1) {
            max2=max1;
            max1=choice;
        }
        else if (choice>max2) {
            max2=choice;
        }
    }
    if (dp[cur]==0 && max1!=0 && max2!=0) dp[cur]=max1+max2;
    if (dp[cur]!=0) coin_comb[cur].insert(dp[cur]);
}

int main()
{
    cin >> N;
    for (int i=2; i<=N; i++) {
        int p; cin >> p;
        graph[i].push_back(p);
        graph[p].push_back(i);
    }
    for (int i=1; i<=N; i++) {
        cin >> dp[i];
    }

    find_coins(1, 0);

    long long ans=0;
    for (int i=1; i<=N; i++) {
        ans+=dp[i];
    }
    cout << ans;
}
