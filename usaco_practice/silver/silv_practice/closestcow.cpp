#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long

const ll MAX=2e5+5;
ll K, M, N, nhoj[MAX]={}, interval_sum[MAX]={}, cow1_interval[MAX]={}, min_dist[MAX]={};
pair<ll, ll> grass[MAX];
vector<pair<double, ll>> grass_interval, tastysum;

void find_min_distance() {
    fill(&min_dist[0], &min_dist[K+1], 1e10);

    ll j=0;
    for (ll i=1; i<=K; i++) {
        while (j<M+1 && nhoj[j+1]<grass[i].f) {
            j++;
        }
        if (j!=0) min_dist[i]=min(min_dist[i], abs(grass[i].f-nhoj[j]));
    }
    j=M+1;
    for (ll i=K; i>=1; i--) {
        while (j>=1 && nhoj[j-1]>grass[i].f) {
            j--;
        }
        if (j!=M+1) min_dist[i]=min(min_dist[i], abs(grass[i].f-nhoj[j]));
    }
}

int main()
{
    cin >> K >> M >> N;
    for (ll i=1; i<=K; i++) cin >> grass[i].f >> grass[i].s;
    for (ll i=1; i<=M; i++) cin >> nhoj[i];
    nhoj[0]=-1e10; nhoj[M+1]=1e10;

    sort(&nhoj[0], &nhoj[M+2]);
    sort(&grass[1], &grass[K+1]);

    ll idx=1;
    for (ll i=1; i<=M+1; i++) {
        while (idx<=K+1 && grass[idx].f<nhoj[i]) {
            interval_sum[i]+=grass[idx].s;
            idx++;
        }
    }
    tastysum.push_back({interval_sum[1], 1}); tastysum.push_back({interval_sum[M+1], 1});

    find_min_distance();

    for (ll i=1; i<=K; i++) {
        grass_interval.push_back({grass[i].f-min_dist[i]+0.1, +grass[i].s});
        grass_interval.push_back({grass[i].f+min_dist[i]-0.1, -grass[i].s});
    }
    sort(grass_interval.begin(), grass_interval.end());

    idx=0;
    while (idx!=grass_interval.size() && grass_interval[idx].f<nhoj[1]) {
        idx++;
    }

    for (ll i=2; i<=M; i++) {
        ll temp=0;
        while (idx!=grass_interval.size() && grass_interval[idx].f<nhoj[i]) {
            temp+=grass_interval[idx].s;
            cow1_interval[i]=max(cow1_interval[i], temp);
            idx++;
        }
        tastysum.push_back({cow1_interval[i], 1});
    }

    for (ll i=2; i<=M; i++) {
        tastysum.push_back({interval_sum[i]-cow1_interval[i], 0});
    }

    sort(tastysum.begin(), tastysum.end());

    ll ans=0, cnt=0;
    idx=tastysum.size()-1;
    while (idx>=0 && cnt<N) {
        ans+=tastysum[idx].f;
        idx--;
        cnt++;
    }

    cout << ans;
}


/*
8 5 2
0 4
1 3
3 1
4 6
8 10
10 8
12 12
394810 14
2
3
5
7
11
*/
