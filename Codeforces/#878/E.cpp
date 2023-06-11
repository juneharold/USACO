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
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    vector<string> out;
    while (T--) {
        string s1, s2; cin >> s1 >> s2;
        set<int> A;
        for (int i=0; i<s1.size(); i++) {
            if (s1[i]!=s2[i]) A.insert(i);
        }

        int t, q; cin >> t >> q;
        queue<pair<int, int>> Q;
        for (int i=1; i<=q; i++) {
            if (!Q.empty() && Q.front().f==i) {
                A.insert(Q.front().s);
                Q.pop();
            }

            int type; cin >> type;
            if (type==1) {
                int pos; cin >> pos;
                pos--;
                if (A.find(pos)!=A.end()) {
                    A.erase(pos);
                    Q.push(make_pair(i+t, pos));
                }
            }
            if (type==2) {
                int a, pos1, b, pos2; cin >> a >> pos1 >> b >> pos2;
                pos1--; pos2--;
                char temp1, temp2;
                if (a==1 && b==1) {
                    temp1=s1[pos1], temp2=s1[pos2];
                    s1[pos2]=temp1;
                    s1[pos1]=temp2;
                }
                else if (a==1 && b==2) {
                    temp1=s1[pos1], temp2=s2[pos2];
                    s2[pos2]=temp1;
                    s1[pos1]=temp2;
                }
                else if (a==2 && b==1) {
                    temp1=s2[pos1], temp2=s1[pos2];
                    s1[pos2]=temp1;
                    s2[pos1]=temp2;
                }
                else if (a==2 && b==2) {
                    temp1=s2[pos1], temp2=s2[pos2];
                    s2[pos2]=temp1;
                    s2[pos1]=temp2;
                }

                if (s1[pos1]==s2[pos1] && A.find(pos1)!=A.end()) A.erase(pos1);
                if (s1[pos1]!=s2[pos1]) A.insert(pos1);
                if (s1[pos2]==s2[pos2] && A.find(pos2)!=A.end()) A.erase(pos2);
                if (s1[pos2]!=s2[pos2]) A.insert(pos2);
            }
            if (type==3) {
                if (A.empty()) out.push_back("YES");
                else out.push_back("NO");
            }
        }
    }
    for (auto ans: out) cout << ans << "\n";
}
