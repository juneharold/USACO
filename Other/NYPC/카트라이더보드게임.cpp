#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int dp[1005][64]={}, score[64]={};
pair<int, int> from[1005][64];
vector<int> to[64]={};

void initialize() {
    int one[10]={8, 17, 20, 31, 37, 39, 44, 49, 60, 63};
    int two[8]={2, 6, 10, 19, 23, 25, 27, 43};
    int three[6]={13, 33, 41, 52, 53, 54};
    int five[2]={55, 64};
    for (int i=0; i<10; i++) score[one[i]-1]=1;
    for (int i=0; i<8; i++) score[two[i]-1]=2;
    for (int i=0; i<6; i++) score[three[i]-1]=3;
    for (int i=0; i<2; i++) score[five[i]-1]=5;

    for (int i=0; i<64; i++) {
        to[i].push_back((i+1)%64);
    }

    to[11].push_back(16);
    to[31].push_back(36);
    to[38].push_back(40);
    to[42]={39};
    to[39]={43};
    to[48]={49, 51, 55};
    to[54]={50};
    to[58]={50};
    to[50]={59};
}

void move(int cur, int turn, int bef, int cnt) {
    if (cnt>6) return;
    if (dp[turn-1][bef]+score[cur]>dp[turn][cur]) {
        dp[turn][cur]=dp[turn-1][bef]+score[cur];
        from[turn][cur]={cnt, bef};
    }
    for (auto nx: to[cur]) move(nx, turn, bef, cnt+1);
}

int main()
{
    int N, X; cin >> N >> X;
    initialize();

    fill(&dp[0][0], &dp[1002][64], -1e9);
    dp[0][0]=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<64; j++) {
            for (auto nx: to[j]) move(nx, i+1, j, 1);
        }
    }
    cout << dp[N][X-1] << "\n";

    vector<pair<int, int>> path;
    vector<int> dice;
    int cur=X-1;
    for (int i=N; i>=1; i--) {
        path.push_back({from[i][cur].s, cur});
        dice.push_back(from[i][cur].f);
        cur=from[i][cur].s;
    }
    for (int i=path.size()-1; i>=0; i--) {
        cout << "Moved from " << path[i].f+1 << " to " << path[i].s+1;
        cout << " (dice = " << dice[i] << ", lucci = " << score[path[i].s] << ")\n";
    }
}
