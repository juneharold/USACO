#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans=0, table[105][105]={};
vector<pair<int, int>> operations;

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
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            char c; cin >> c;
            table[i][j]=c-'0';
        }

        for (int i=1; i<=n-1; i++) for (int j=1; j<=m-1; j++) {
            solve_box(i,j);
        }

        cout << ans << "\n";
        int idx=0;
        for (int i=0; i<ans; i++) {
            for (int j=0; j<3; j++) {
                cout << operations[idx].first << ' ' << operations[idx].second << ' ';
                idx++;
            }
            cout << "\n";
        }

        ans=0;
        operations.clear();
        fill(&table[0][0], &table[101][101], 0);
    }
}

/*
1
3 3
011
101
110
*/