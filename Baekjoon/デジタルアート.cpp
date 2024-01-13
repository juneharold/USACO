/*
rectangle's left, right, up, down defined by each colors. Hence there are 256^4 rectangles possible 
We can choose left and right of rectangle in O(256^2). And use sliding window vertically to keep track of fully enclosed colors. This takes O(256^3) in total
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> pii;
#define fs first
#define sc second

int grid[1005][1005]={};
vector<int> u(257, -1), d(257, -1), l(257, -1), r(257, -1);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int H, W, S; cin >> H >> W >> S;
    set<int> unique;
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            cin >> grid[i][j];
            unique.insert(grid[i][j]);
            if (u[grid[i][j]]==-1 || i>u[grid[i][j]]) u[grid[i][j]]=i;
            if (d[grid[i][j]]==-1 || i<d[grid[i][j]]) d[grid[i][j]]=i;
            if (l[grid[i][j]]==-1 || j<l[grid[i][j]]) l[grid[i][j]]=j;
            if (r[grid[i][j]]==-1 || j>r[grid[i][j]]) r[grid[i][j]]=j;
        }
    }

    vector<pii> color_ordered;
    for (int color: unique) {
        color_ordered.push_back({d[color], color});
        color_ordered.push_back({u[color], color});
    }
    sort(color_ordered.begin(), color_ordered.end());

    int mx_covered=0;
    for (int i=1; i<=256; i++) {
        for (int j=1; j<=256; j++) {
            if (l[i]==-1 || r[j]==-1 || l[i]>r[j] || r[j]-l[i]+1>S) continue;
            vector<pii> y;
            for (pii x: color_ordered) {
                if (l[i]<=l[x.sc] && r[x.sc]<=r[j]) y.push_back({x.fs, x.sc});
            }
            if (y.empty()) continue;

            vector<int> active(257, 0);
            active[y[0].sc]++;
            int bottom=0, top=0, cnt=0;
            while (bottom<=top && top<y.size()) {
                if ((y[top].fs-y[bottom].fs+1)*(r[j]-l[i]+1)<=S) {
                    mx_covered=max(mx_covered, cnt);
                }
                
                if (top+1<y.size() && (y[top+1].fs-y[bottom].fs+1)*(r[j]-l[i]+1)<=S) {
                    top++;
                    active[y[top].sc]++;
                    if (active[y[top].sc]==2) cnt++;
                }
                else if (bottom!=top) {
                    if (active[y[bottom].sc]==2) cnt--;
                    active[y[bottom].sc]--;
                    bottom++;
                } 
                else {
                    if (top==y.size()-1) break;
                    top++;
                    active[y[top].sc]++;
                    if (active[y[top].sc]==2) cnt++;
                    if (active[y[bottom].sc]==2) cnt--;
                    active[y[bottom].sc]--;
                    bottom++;
                }
            }
        }
    }
    cout << unique.size()-mx_covered;
}
