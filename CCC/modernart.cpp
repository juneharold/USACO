#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, M, K;
set<int> row, col;

int main()
{
    cin >> N >> M >> K;
    for (int i=0; i<K; i++) {
        char c; int a; cin >> c >> a;
        if (c=='R') {
            if (row.find(a)==row.end()) row.insert(a);
            else row.erase(row.find(a));
        }
        if (c=='C') {
            if (col.find(a)==col.end()) col.insert(a);
            else col.erase(col.find(a));
        }
    }

    int ans=0;

    for (auto r: row) {
        ans+=M;
    }
    for (auto c: col) {
        ans+=N;
        ans-=row.size()*2;
    }
    cout << ans;
}
