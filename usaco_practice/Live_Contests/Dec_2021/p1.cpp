#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define f first
#define s second

const long long MAX=2e5+5;
long long K, M, N, nhoj[MAX], min_dist[MAX];
pair<long long, long long> grass[MAX];

struct Event {
    long long pos, val, type;
};
vector<Event> A;
bool cmp (Event a, Event b) {return a.pos<b.pos;}

int main()
{
    cin >> K >> M >> N;
    for (long long i=1; i<=K; i++) cin >> grass[i].f >> grass[i].s;
    for (long long i=1; i<=M; i++) {
        cin >> nhoj[i];
    }

    sort(&grass[1], &grass[K+1]);
    sort(&nhoj[1], &nhoj[M+1]);

    fill(&min_dist[0], &min_dist[K+1], 1e9);

    long long j=0;
    for (long long i=1; i<=K; i++) {
        while (nhoj[j+1]<grass[i].f && j+1<=M) {
            j++;
        }
        if (j!=0) min_dist[i]=min(min_dist[i], abs(grass[i].f-nhoj[j]));
    }
    j=M+1;
    for (long long i=K; i>=1; i--) {
        while (nhoj[j-1]>grass[i].f && j-1>=1) {
            j--;
        }
        if (j!=M+1) min_dist[i]=min(min_dist[i], abs(grass[i].f-nhoj[j]));
    }

    for (long long i=1; i<=K; i++) {
        A.push_back({grass[i].f-min_dist[i], grass[i].s, +1});
        A.push_back({grass[i].f+min_dist[i], grass[i].s, -1});
    }
    sort(A.begin(), A.end(), cmp);

    set<long long> loc;
    long long cur_val=0;
    for (long long i=0; i<A.size(); i++) {
        long long j=i;
        while(j<A.size() && A[i].pos==A[j].pos) {
            if (A[j].type==1) cur_val+=A[j].val;
            else cur_val-=A[j].val;
            j++;
        }
        //cout << A[i].pos << " " << cur_val << "\n";
        loc.insert(cur_val);
        i=j-1;
    }

    //for (auto x: loc) cout << x << " ";

    auto it=--loc.end(); long long cnt=0, ans=0;
    while (cnt<N) {
        ans+=*it;
        cnt++;
        if (it==loc.begin()) break;
        it--;
    }
    cout << ans;
}
