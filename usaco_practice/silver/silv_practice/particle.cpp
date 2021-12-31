#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second

const int MAX=1e5+5;
int N, ans=0, Y1[MAX], Y2[MAX];
pair<int, int> pos[MAX]={};

int main()
{
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> pos[i].f >> pos[i].s;
    }

    sort(pos, pos+N);
    fill(&Y1[0], &Y1[N], 1e9+1);
    fill(&Y2[0], &Y2[N], -1e9-1);

    Y1[0]=pos[0].s; Y2[N-1]=pos[N-1].s;
    for (int i=1; i<N; i++) {
        Y1[i]=min(Y1[i-1], pos[i].s);
    }
    for (int i=N-2; i>=0; i--) {
        Y2[i]=max(Y2[i+1], pos[i].s);
    }

    for (int i=0; i<N-1; i++) {
        if (Y1[i]>Y2[i+1]) ans++;
    }
    cout << ans+1;
}

/*
7
1 0
0 1
-1 0
0 -1
0 0
1 1
-1 3
*/
