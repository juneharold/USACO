#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long
#define db double



int main()
{
    int T; cin >> T;
    string s; getline(cin, s);
    while (T--) {
        int N, M; cin >> N >> M;
        map<string, int> m;
        for (int i=1; i<=N; i++) {
            string name; getline(cin, name);
            m[name]++;
        }
        for (int i=1; i<=M; i++) {
            string name; getline(cin, name);
            m[name]++;
        }
        for (auto x: m) {
            if (x.s==1) cout << x.f << "\n";
        }
    }
}
