#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

bool cow_loc[3000][3000];
queue<pair<int,int>> q;

void solve(int x, int y) {
    if (!cow_loc[x][y]) return;
    int num_adj = 0;
    for (int d = 0; d < 4; ++d)
        num_adj += cow_loc[x+dx[d]][y+dy[d]];
    if (num_adj == 3)
        for (int d = 0; d < 4; ++d) {
            pair<int,int> next{x+dx[d],y+dy[d]};
            if (!cow_loc[next.first][next.second])
                q.push(next);
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	int total_cows=0;
	for (int i=1; i<=N; i++) {
		pair<int,int> p; cin >> p.first >> p.second;
		p.first+=1000;
        p.second+=1000;
		q.push(p);
		while (!q.empty()) {
			pair<int,int> loc=q.front();
			q.pop();
			if (cow_loc[loc.first][loc.second]) continue;
			total_cows++;
            cow_loc[loc.first][loc.second] = 1;
			solve(loc.first,loc.second);
			for (int d = 0; d < 4; ++d)
				solve(loc.first+dx[d],loc.second+dy[d]);
		}
		cout << total_cows-i << "\n";
	}
}
