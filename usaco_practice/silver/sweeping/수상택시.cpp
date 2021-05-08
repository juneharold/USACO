#include <iostream>
#include <algorithm>
using namespace std;

pair <long long, long long> ab[300005];

int main()
{
    long long n, m; cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> ab[i].second >> ab[i].first;
    }
    sort(ab, ab+n);
    long long ans=0, end=0;
    for (int i=0; i<n; i++) {
        if (ab[i].second<ab[i].first) continue;
        if (ab[i].first>=end) {
            ans+=(ab[i].second-ab[i].first)*2;
            end=ab[i].second;
        }
        else if (ab[i].second>=end) {
            ans+=(ab[i].second-end)*2;
            end=ab[i].second;
        }
    }
    cout << ans+m;
}

/*
3 10
2 8
6 4
5 3

2 10
2 8
6 4

3 10
2 8
4 2
7 5

2 10
7 5
5 3

3 10
9 1
5 4
9 1


3 10
3 1
3 8
5 2

4 10
3 2
4 2
5 4
6 7
*/
