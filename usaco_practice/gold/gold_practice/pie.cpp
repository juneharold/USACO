#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
using namespace std;

const int MAX=1e5+5;
int N, D, visit[2*MAX]={};
struct pie{ int b, e, id; };
pie Bess[MAX], Elss[MAX];
queue<pie> q;
struct cmp1 { bool operator() (pie a, pie b){
    if (a.b==b.b && a.e==b.e) return a.id<b.id;
    if (a.b==b.b) return a.e<b.e;
    return a.b<b.b;
} };
struct cmp2 { bool operator() (pie a, pie b){
    if (a.e==b.e && a.b==b.b) return a.id<b.id;
    if (a.e==b.e) return a.b<b.b;
    return a.e<b.e;
} };
set<pie, cmp2> B;
set<pie, cmp1> E;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
    cin >> N >> D;
    for (int i=1; i<=N; i++) {
        cin >> Bess[i].b >> Bess[i].e;
        Bess[i].id=i;
        if (Bess[i].e==0) {
            q.push(Bess[i]);
            visit[Bess[i].id]=1;
        }
        else B.insert(Bess[i]);
    }
    for (int i=1; i<=N; i++) {
        cin >> Elss[i].b >> Elss[i].e;
        Elss[i].id=i+N;
        if (Elss[i].b==0) {
            q.push(Elss[i]);
            visit[Elss[i].id]=1;
        }
        else E.insert(Elss[i]);
    }

    while (!q.empty()) {
        int cur=q.front().id, b=q.front().b, e=q.front().e;
        q.pop();

        if (cur<=N) { // use set E
            // b-D ~ b
            auto start=E.lower_bound({b-D, 0, 0});
            auto end=E.upper_bound({b, (int)1e9, (int)1e9});

            for (auto it=start; it!=end; it++) {
                if (visit[(*it).id]==0) {
                    visit[(*it).id]=visit[cur]+1;
                    q.push({*it});
                }
            }
            E.erase(start, end);
        }
        else {
            // e-D ~ e
            auto start=B.lower_bound({0, e-D, 0});
            auto end=B.upper_bound({(int)1e9, e, (int)1e9});

            for (auto it=start; it!=end; it++) {
                if (visit[(*it).id]==0) {
                    visit[(*it).id]=visit[cur]+1;
                    q.push({*it});
                }
            }
            B.erase(start, end);
        }
    }

    for (int i=1; i<=N; i++) {
        if (visit[i]==0) cout << -1 << "\n";
        else cout << visit[i] << "\n";
    }
}
