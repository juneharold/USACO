#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

pair<pair<int, int>, int> tank[501];
vector<pair<pair<int, char>, int>> ans;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.f.s==b.f.s) return a.f.f<b.f.f;
    return a.f.s<b.f.s;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> tank[i].f.f >> tank[i].f.s;
        tank[i].s=i;
    }

    sort(&tank[1], &tank[N+1]);
    vector<pair<int, int>> up, down;
    for (int i=1; i<=N; i++) {
        if (tank[i].f.f>i) up.push_back({tank[i].s, abs(i-tank[i].f.f)});
        if (tank[i].f.f<i) down.push_back({tank[i].s, abs(i-tank[i].f.f)});
    }
    reverse(down.begin(), down.end());
    for (auto x: up) ans.push_back({{x.f, 'U'}, x.s});
    for (auto x: down) ans.push_back({{x.f, 'D'}, x.s});

    sort(&tank[1], &tank[N+1], cmp);
    vector<pair<int, int>> right, left;
    for (int i=1; i<=N; i++) {
        if (tank[i].f.s>i) left.push_back({tank[i].s, abs(i-tank[i].f.s)});
        if (tank[i].f.s<i) right.push_back({tank[i].s, abs(i-tank[i].f.s)});
    }
    reverse(right.begin(), right.end());
    for (auto x: left) ans.push_back({{x.f, 'L'}, x.s});
    for (auto x: right) ans.push_back({{x.f, 'R'}, x.s});

    int cnt=0;
    for (auto x: ans) cnt+=x.s;
    cout << cnt << "\n";
    for (auto x: ans) for (int i=0; i<x.s; i++) cout << x.f.f << ' ' << x.f.s << "\n";
}

/*
7
1 1
2 1
2 2
3 2
4 2
6 2
4 3
result:
6 R 1
7 R 2
5 R 1
4 R 1
3 R 1
*/
