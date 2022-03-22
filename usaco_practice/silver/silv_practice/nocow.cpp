#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
#define ll long long

vector<string> list[105], ans;
set<string> type[35];

int main()
{
    freopen("nocow.in", "r", stdin);
    freopen("nocow.out", "w", stdout);
    int N, K, num_type=0; cin >> N >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<4; j++) {
            string a; cin >> a;
        }
        int j=0, cnt=0;
        while (true) {
            string a; cin >> a;
            if (a=="cow.") break;
            list[i].push_back(a);
            type[j++].insert(a);
            cnt++;
        }
        num_type=cnt;
    }

    ll sum=1, cnt=0;
    for (int i=0; i<num_type; i++) sum*=type[i].size();

    for (int i=0; i<num_type; i++) {
        sum/=type[i].size();
        for (auto x: type[i]) {
            ll a=0;
            for (int j=0; j<N; j++) {
                bool applicable=true;
                for (int k=0; k<i; k++) if (list[j][k]!=ans[k]) applicable=false;
                if (applicable && list[j][i]==x) a++;
            }
            ll temp=sum-a;

            if (cnt+temp>=K) {
                ans.push_back(x);
                break;
            }
            else cnt+=temp;
        }
    }

    for (auto x: ans) cout << x << " ";
}
