#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int grid[31][31]={};

int main()
{
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int R, C, in[26]={}; cin >> R >> C;
        for (int i=0; i<R; i++) for (int j=0; j<C; j++) {
            char c; cin >> c;
            grid[i][j]=c-65;
            in[grid[i][j]]++;
        }
        int numtype=0;
        for (int i=0; i<26; i++) if (in[i]!=0) numtype++;

        queue<int> q;
        vector<int> ans;
        for (int i=0; i<R; i++) for (int j=0; j<C; j++) {
            if (i==R-1 || (i<R-1 && grid[i][j]==grid[i+1][j])) {
                in[grid[i][j]]--;
                if (in[grid[i][j]]==0) {
                    q.push(grid[i][j]);
                    ans.push_back(grid[i][j]);
                }
            }
        }
        
        while (!q.empty()) {
            int x=q.front(); q.pop();
            for (int i=0; i<R; i++) for (int j=0; j<C; j++) {
                if (i!=0 && grid[i][j]==x) {
                    in[grid[i-1][j]]--;
                    if (in[grid[i-1][j]]==0) {
                        q.push(grid[i-1][j]);
                        ans.push_back(grid[i-1][j]);
                    }
                }
            }
        }

        cout << "Case #" << t << ": ";
        if (ans.size()!=numtype) cout << "-1";
        else for (int a: ans) cout << (char)(a+65);
        cout << "\n";
    }
}
