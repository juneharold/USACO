#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <map>
using namespace std;
int const nmax=1e5+5;
#define fs first
#define sc second

int segtree[4*nmax]={}, lazy[4*nmax]={};
void propagate(int n, int a, int b) {
    if (lazy[n]!=2e9) segtree[n]=lazy[n];
    if (a!=b) {
        lazy[2*n]=min(lazy[n], lazy[2*n]);
        lazy[2*n+1]=min(lazy[n], lazy[2*n+1]);
    }
    lazy[n]=2e9;
}
void update(int n, int a, int b, int qa, int qb, int v) {
    propagate(n, a, b);
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) {
        lazy[n]=v;
        propagate(n, a, b);
        return;
    }
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n]=min(segtree[2*n], segtree[2*n+1]);
}
int query(int n, int a, int b, int qa, int qb) {
    propagate(n, a, b);
    if (b<qa || qb<a) return 1e9;
    if (qa<=a && b<=qb) return segtree[n];
    int mid=(a+b)/2;
    return min(query(2*n, a, mid, qa, qb), query(2*n+1, mid+1, b, qa, qb));
}

int dp1[nmax]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    //auto start = std::chrono::high_resolution_clock::now();
    vector<int> c(N+1);
    for (int i=1; i<=N; i++) cin >> c[i];

    map<int, int> mp;
    for (int i=1; i<=N; i++) mp[c[i]]=1;
    int idx=0;
    for (auto a: mp) mp[a.fs]=++idx;
    
    fill(&lazy[0], &lazy[4*N+4], 2e9);
    int lo=0, hi=1e9;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        fill(&dp1[0], &dp1[N+1], 0);
        update(1, 1, N, 1, N, 1e9);
        for (int i=1; i<=N; i++) {
            dp1[i]=i-1;
            auto it=mp.upper_bound(c[i]+mid);
            if (it!=mp.begin()) {
                it--;
                dp1[i]=min(dp1[i], i-1+query(1, 1, N, 1, (*it).sc));
            }
            update(1, 1, N, mp[c[i]], mp[c[i]], dp1[i]-i);
        }
        update(1, 1, N, 1, N, 1e9);
        bool possible=false;
        for (int i=N; i>=1; i--) {
            int dp2=N-i;
            auto it=mp.upper_bound(c[i]+mid);
            if (it!=mp.begin()) {
                it--;
                dp2=min(dp2, -i-1+query(1, 1, N, 1, (*it).sc));
            }
            update(1, 1, N, mp[c[i]], mp[c[i]], dp2+i);

            if (dp2+dp1[i]<=M) {
                possible=true;
                break;
            }
        }
        if (possible) hi=mid;
        else lo=mid+1;
    }
    cout << lo;
    /*
    // Record end time
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    return 0;*/
}