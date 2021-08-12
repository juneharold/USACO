#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MAX=1e4+5;
int N, M, K, parent[MAX]={}, A[MAX]={};
set<int> target;

int Find (int x) {
    if (parent[x]==x) return x;
    else return parent[x]=Find(parent[x]);
}

void Union (int a, int b) {
    a=Find(a);
    b=Find(b);
    if (a==b) return;
    if (A[b]<A[a]) swap(a, b);
    parent[b]=a;
}

int main()
{
    cin >> N >> M >> K;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
        parent[i]=i;
    }

    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        Union(a, b);
    }

    for (int i=1; i<=N; i++) {
        target.insert(Find(i));
    }

    long long sum=0;
    for (auto i: target) {
        sum+=A[i];
    }

    if (sum<=K) cout << sum;
    else cout << "Oh no";
}
