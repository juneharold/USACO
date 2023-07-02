#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, L; cin >> N >> L;
    deque<pair<int, int>> dq;
    for (int i=0; i<N; i++) {
        int a; cin >> a;
        while (!dq.empty() && dq.front().s<=i-L) {
            dq.pop_front();
        }
        while (!dq.empty() && dq.back().f>=a) {
            dq.pop_back();
        }
        dq.push_back({a, i});
        cout << dq.front().f << ' ';
    }
}