#include <iostream>
#include <algorithm>
using namespace std;

#define f first
#define s second

const int MAX=1e3+2;
int N, B, visit[MAX][MAX]={}, snow[MAX]={};
pair<int, int> boots[MAX];

void solve(int a, int cur) {
    visit[a][cur]=1;
    int d1=boots[a].f, s1=boots[a].s;

    //a신발로 갈 수 있는 칸들.
    for (int i=0; i<=s1; i++) {
        int nx=cur+i;
        if (nx>N) continue;
        if (snow[nx]<=d1 && visit[a][nx]==0) solve(a, nx);
    }
}

int main()
{
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin >> N >> B;
    for (int i=1; i<=N; i++) cin >> snow[i];
    for (int i=1; i<=B; i++) cin >> boots[i].f >> boots[i].s;

    for (int i=1; i<=B; i++) {
        solve(i, 1);
        if (visit[i][N]==1) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}
