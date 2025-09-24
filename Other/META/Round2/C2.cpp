#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=805;

int R, C;
ll K;
vector<vector<int>> G;
map<int, vector<pii>> loc;
map<int, vector<vector<int>>> owner_prefix_sums;
const int THRESHOLD=500; 

void buildPFS(vector<vector<int>>& grid){
    for (int i=1; i<=R; i++)
        for (int j=1; j<=C; j++)
            grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
}

int query(const vector<vector<int>>& grid, int x1, int y1, int x2, int y2){
    x1=max(x1,1); y1=max(y1,1);
    x2=min(x2,R); y2=min(y2,C);
    if (x1>x2 || y1>y2) return 0;
    return grid[x2][y2]-grid[x1-1][y2]-grid[x2][y1-1]+grid[x1-1][y1-1];
}

ll total_pairs(int D){
    ll tot_all=0;
    for (int i=1; i<=R; i++){
        for (int j=1; j<=C; j++){
            if (G[i][j]==0) continue;
            int S=query(G,i-D,j-D,i+D,j+D);
            tot_all+=S-1;
        }
    }

    ll tot_same=0;
    for (auto& kv: loc){
        int owner=kv.first;
        int N_k=kv.second.size();
        if (N_k<=THRESHOLD){
            vector<vector<int>> Gk(R+2, vector<int>(C+2,0));
            for (auto& pos: kv.second){
                Gk[pos.fs][pos.sc]=1;
            }
            buildPFS(Gk);
            owner_prefix_sums[owner]=Gk;
            for (auto& pos: kv.second){
                int i=pos.fs, j=pos.sc;
                int Sk=query(Gk,i-D,j-D,i+D,j+D);
                tot_same+=Sk-1;
            }
        } else {
            tot_same+=(ll)N_k*(N_k-1);
        }
    }

    ll tot_diff=tot_all - tot_same;
    return tot_diff;
}

void solve(){
    cin >> R >> C >> K;
    G.assign(R+2, vector<int>(C+2,0));
    loc.clear();
    owner_prefix_sums.clear();

    for (int i=1; i<=R; i++){
        for (int j=1; j<=C; j++){
            int B; cin >> B;
            G[i][j]=1;
            loc[B].push_back({i,j});
        }
    }

    buildPFS(G);

    int left=1, right=max(R,C), ans=-1;
    while (left<=right){
        int mid=(left+right)/2;
        ll pairs=total_pairs(mid);
        if (pairs>=K){
            ans=mid;
            right=mid-1;
        } else {
            left=mid+1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("bunny_hopscotch_validation_input.txt", "r", stdin);
    freopen("Cout.txt", "w", stdout);
    int T=1; cin >> T;
    for (int t=1; t<=T; t++){
        cout << "Case #" << t << ": ";
        solve();
    }
}
