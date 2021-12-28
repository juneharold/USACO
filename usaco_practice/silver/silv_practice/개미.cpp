#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

int N, L;
struct ant {
    int pos, dir, num;
};
ant A[100005];
bool cmp (ant a, ant b) {
    if (a.pos==b.pos) return a.dir<b.dir;
    return a.pos<b.pos;
}

int main()
{
    cin >> N >> L;
    pair<int, int> ans={0, 0};

    for (int i=1; i<=N; i++) {
        int v; cin >> v;
        A[i].pos=abs(v);
        if (v>0) A[i].dir=1;
        else A[i].dir=-1;
        A[i].num=i;

        if (v>0 && L-v>ans.f) {
            ans.f=L-v;
            ans.s=i;
        }
        else if (v<0 && abs(v)>ans.f) {
            ans.f=abs(v);
            ans.s=i;
        }
    }


    sort(&A[1], &A[N+1], cmp);

    for (int i=1; i<=N; i++) if (A[i].num==ans.s) {
        if (A[i].dir>0) {
            int cnt=0;
            for (int j=i+1; j<=N; j++) if (A[j].dir<0) cnt++;
            for (int j=i+1; j<=i+cnt; j++) ans.s=A[j].num;
        }
        else {
            int cnt=0;
            for (int j=i-1; j>=1; j--) if (A[j].dir>0) cnt++;
            for (int j=i-1; j>=i-cnt; j--) ans.s=A[j].num;
        }
        break;
    }
    cout << ans.s << " " << ans.f;
}
