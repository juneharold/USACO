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
#include <numeric>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=1e6+5, sqrmax=635, MOD=1e9+7;

int cnt[nmax]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> A;
    int x; cin >> x;
    cnt[x]=1;
    A.push_back(x);
    for (int i=1; i<1000; i++) {
        cout << "+ 1\n";
        cout.flush();
        cin >> x;
        if (cnt[x]==1) {
            cout << "! " << A.size();
            cout.flush();
            return 0;
        }
        else {
            cnt[x]=1;
            A.push_back(x);
        }
    }
    for (int i=1; i<=1020; i++) {
        cout << "+ 1000\n";
        cout.flush();
        cin >> x;
        if (cnt[x]==1) {
            int idx=-1;
            for (int j=0; j<A.size(); j++) {
                if (A[j]==x) idx=j;
            }
            cout << "! " << (i+1)*1000-(idx+1);
            cout.flush();
            return 0;
        }
    }
}
