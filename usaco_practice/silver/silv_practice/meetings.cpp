#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define f first
#define s second

const int MAX=5e4+5;
int N, L, T, weight_sum=0, ans=0;
struct COW{
    int pos, w, dir;
};
COW cow[MAX];
bool cmp (COW a, COW b) {
    return a.pos<b.pos;
}
vector<pair<int, pair<int, int>>> A; //time, #of meeting, weight
multiset<int> candidate;

void find_T() {
    int pfs=0;
    for (int i=0; i<N; i++) {
        if (cow[i].dir==1) pfs++;
        else A.push_back({cow[i].pos, {pfs, cow[i-pfs].w}});
    }
    int sfs=0;
    for (int i=N-1; i>=0; i--) {
        if (cow[i].dir==-1) sfs++;
        else A.push_back({L-cow[i].pos, {sfs, cow[i+sfs].w}});
    }
    sort(A.begin(), A.end());
    int w_cnt=0;
    for (int i=0; i<N; i++) {
        w_cnt+=A[i].s.s;
        if (w_cnt>=weight_sum/2) {
            T=A[i].f;
            break;
        }
    }
}

int main()
{
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    cin >> N >> L;
    for (int i=0; i<N; i++) {
        cin >> cow[i].w >> cow[i].pos >> cow[i].dir;
        weight_sum+=cow[i].w;
    }
    if (weight_sum%2==1) weight_sum++;
    sort(cow, cow+N, cmp);

    find_T();

    for (int i=0; i<N; i++) {
        if (cow[i].dir==1) {
            candidate.insert(cow[i].pos+2*T);
        }
        else {
            while(!candidate.empty()) {
                auto first=candidate.begin();
                if (*first<cow[i].pos) candidate.erase(first);
                else break;
            }
            ans+=candidate.size();
        }
    }

    cout << ans;
}
