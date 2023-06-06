#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q; cin >> n >> q;
    string S; cin >> S;
    set<int> A;
    for (int i=0; i<n; i++) {
        if (i%2==0 && S[i]==')') A.insert(i);
        if (i%2==1 && S[i]=='(') A.insert(i);
    }
    for (int i=0; i<q; i++) {
        int x; cin >> x;
        x--;
        if (S[x]==')') {
            S[x]='(';
            if (x%2==1) A.insert(x);
            else A.erase(x);
        }
        else {
            S[x]=')';
            if (x%2==0) A.insert(x);
            else A.erase(x);
        }

        if (n%2==1) {
            cout << "NO\n";
            continue;
        }
        if (A.empty()) cout << "YES\n";
        else if (!A.empty() && ((*A.begin())%2==1 && (*--A.end())%2==0)) cout << "YES\n";
        else cout << "NO\n";
    }
}
/*
1 1
)
1
*/