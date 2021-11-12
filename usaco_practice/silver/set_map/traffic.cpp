#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second

int x, n;
set<pair<int, int>> parts;
multiset<int> lengths;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> x >> n;
    parts.insert({0, x});
    lengths.insert(x);
    for (int i=0; i<n; i++) {
        int p; cin >> p;

        auto loc=parts.lower_bound({p, 0});
        loc--;
        int a=(*loc).f, b=(*loc).s;
        parts.erase(loc); lengths.erase(lengths.find(b-a));
        parts.insert({a, p}); lengths.insert(p-a);
        parts.insert({p, b}); lengths.insert(b-p);

        auto ans=lengths.end();
        cout << *--ans << " ";
    }
}
