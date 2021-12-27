#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

const int MAX=1e5+5;
int N, M, ans[MAX]={}, taken[MAX]={}, add=1;
pair<int, int> milks[MAX];

void recurse (int cow, int stolen) {
    if (stolen==milks[cow].f) {
        int nx=taken[milks[cow].s];
        if (nx==0) {
            taken[milks[cow].s]=cow;
        }
        else if (nx<cow) {
            add=0;
        }
        else {
            taken[milks[cow].s]=cow;
            recurse(nx, milks[cow].s);
        }
    }
    else if (stolen==milks[cow].s) {
        add=0;
    }
}

int main()
{
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> milks[i].f >> milks[i].s;
    }

    for (int i=N; i>=1; i--) {
        add=1;
        int a=taken[milks[i].f];
        if (a==0) {
            taken[milks[i].f]=i;
        }
        else {
            taken[milks[i].f]=i;
            recurse(a, milks[i].f);
        }
        ans[i]=ans[i+1]+add;
    }

    for (int i=1; i<=N; i++) cout << ans[i] << "\n";
}
