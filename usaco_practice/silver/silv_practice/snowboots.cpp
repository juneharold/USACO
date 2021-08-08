#include <iostream>
#include <algorithm>
using namespace std;

#define f first
#define s second

const int MAX=255;
int N, B, visit[MAX][MAX]={}, snow[MAX]={}, ans=1e9;
pair<int, int> boots[MAX];

void solve(int a, int cur) {
    visit[a][cur]=1;
    int d1=boots[a].f, s1=boots[a].s;
    if (cur==N) ans=min(ans, a);

    //a신발로 갈 수 있는 칸들.
    for (int i=0; i<=s1; i++) {
        int nx=cur+i;
        if (nx>N) continue;
        if (snow[nx]<=d1 && visit[a][nx]==0) solve(a, nx);
    }

    // 다른 신발로 갈 수 있는 칸들.
    for (int k=1; a+k<=B; k++) {
        int d2=boots[a+k].f, s2=boots[a+k].s;
        if (snow[cur]<=d2 && visit[a+k][cur]==0) solve(a+k, cur);
    }
}

int main()
{
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin >> N >> B;
    for (int i=1; i<=N; i++) cin >> snow[i];
    for (int i=1; i<=B; i++) cin >> boots[i].f >> boots[i].s;

    solve(1, 1);

    cout << ans-1;
}

/*
2 2
0 0
3 1
0 1

*/
