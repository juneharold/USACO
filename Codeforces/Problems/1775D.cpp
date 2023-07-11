#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const int nmax=300000;

int a[300005]={}, dist[600005]={}, minfactor[300005]={}, id[300005]={}, exist[300005]={};
vector<int> graph[600005], isprime(nmax+1, 1), primes;

void linear_sieve() {
    for (int i=1; i<=nmax; i++) minfactor[i]=i;
    for (int i=2; i<=nmax; i++) {
        if (isprime[i]==1) primes.push_back(i);
        for (int p: primes) {
            if (i*p>nmax) break;
            isprime[i*p]=0;
            minfactor[i*p]=p;
            if (i%p==0) break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    linear_sieve();
    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        id[a[i]]=i;
        if (exist[a[i]]) continue;
        int temp=a[i];
        while (temp>1) {
            graph[a[i]+nmax].push_back(minfactor[temp]);
            graph[minfactor[temp]].push_back(a[i]+nmax);
            int bef=temp;
            while (minfactor[bef]==minfactor[temp]) temp/=minfactor[temp];
        }
        exist[a[i]]=1;
    }
    int s, t; cin >> s >> t;

    if (s==t) {
        cout << "1\n" << s;
        exit(0);
    }
    if (a[s]==1 || a[t]==1) {
        cout << -1;
        exit(0);
    }
    if (a[s]==a[t]) {
        cout << "2\n" << s << ' ' << t;
        exit(0);
    }

    fill(&dist[0], &dist[600001], 1e9);
    dist[a[s]+nmax]=0;
    queue<int> q;
    q.push(a[s]+nmax);
    vector<int> from(600001, 0);
    while (!q.empty()) {
        int cur=q.front(); q.pop();
        for (int nx: graph[cur]) {
            if (dist[nx]>dist[cur]+1) {
                dist[nx]=dist[cur]+1;
                from[nx]=cur;
                q.push(nx);
            }
        }
    }

    if (dist[a[t]+nmax]==1e9) {
        cout << -1;
        exit(0);
    }
    vector<int> path;
    int cur=a[t]+nmax;
    while (true) {
        if (cur>nmax) path.push_back(id[cur-nmax]);
        if (cur==a[s]+nmax) break;
        cur=from[cur];
    }
    cout << dist[a[t]+nmax]/2+1 << "\n" << s << ' ';
    for (int i=path.size()-2; i>=1; i--) cout << path[i] << ' ';
    cout << t;
}
/*
5
2 2 6 3 2 
1 4

4
277200 277200 277200 277200
1 3
*/