#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define f first
#define s second

int n, m, ans=0, table[105][105]={};
vector<pair<int, int>> operations;

void solve_down(int x, int y) {
    if (table[x][y]==1) {
        ans++;
        table[x][y]=0;
        operations.push_back(make_pair(x, y));
        table[x+1][y]=1-table[x+1][y];
        operations.push_back(make_pair(x+1, y));
        if (y+1<=m) {
            table[x+1][y+1]=1-table[x+1][y+1];
            operations.push_back(make_pair(x+1, y+1));
        }
        else {
            table[x+1][y-1]=1-table[x+1][y-1];
            operations.push_back(make_pair(x+1, y-1));
        }
    }
}

void solve_right(int x, int y) {
    if (table[x][y]==1) {
        ans++;
        table[x][y]=0;
        operations.push_back(make_pair(x, y));
        table[x][y+1]=1-table[x][y+1];
        operations.push_back(make_pair(x, y+1));
        if (x+1<=n) {
            table[x+1][y+1]=1-table[x+1][y+1];
            operations.push_back(make_pair(x+1, y+1));
        }
        else {
            table[x-1][y+1]=1-table[x-1][y+1];
            operations.push_back(make_pair(x-1, y+1));
        }
    }
}

void solve_box(int x, int y) {
    int cnt=0;
    for (int i=x; i<x+2; i++) for (int j=y; j<y+2; j++) {
        cnt+=table[i][j];
    }

    while (cnt!=0) {
        if (cnt>=3) {
            for (int i=x; i<x+2; i++) for (int j=y; j<y+2; j++) {
                if (table[i][j]==1) {
                    table[i][j]=0;
                    operations.push_back(make_pair(i, j));
                }
            }
            cnt-=3;
        }
        else {
            int cnt_zero=0, cnt_one=0;
            for (int i=x; i<x+2; i++) for (int j=y; j<y+2; j++) {
                if (table[i][j]==0 && cnt_zero<2) {
                    table[i][j]=1;
                    operations.push_back(make_pair(i, j));
                    cnt_zero++;
                }
                else if (table[i][j]==1 && cnt_one<1) {
                    table[i][j]=0;
                    operations.push_back(make_pair(i, j));
                    cnt_one++;
                }
            }
            cnt+=1;
        }
        ans++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            char c; cin >> c;
            table[i][j]=c-'0';
        }

        for (int i=1; i<=n-2; i++) {
            for (int j=1; j<=m; j++) {
                solve_down(i, j);
            }
        }
        for (int j=1; j<=m-2; j++) {
            for (int i=n-1; i<=n; i++) {
                solve_right(i, j);
            }
        }
        solve_box(n-1, m-1);

        cout << ans << "\n";
        int idx=0;
        for (int i=0; i<ans; i++) {
            for (int j=0; j<3; j++) {
                cout << operations[idx].f << ' ' << operations[idx].s << ' ';
                idx++;
            }
            cout << "\n";
        }

        ans=0;
        operations.clear();
        fill(&table[0][0], &table[101][101], 0);
    }
}
