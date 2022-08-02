#include <iostream>
#include <string>
using namespace std;

string s[4];

bool check(int idx, char a) {
    for (int i=0; i<s[idx].size(); i++) {
        if (s[idx][i]==a) return true;
    }
    return false;
}

void solve(string x) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                for (int l=0; l<4; l++) {
                    if (i==j || j==k || k==l || l==i || j==l || i==k) continue;
                    if (check(i, x[0]) && check(j, x[1]) && check(k, x[2]) && check(l, x[3])) {
                        cout << "YES\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n";
    return;
}

int main()
{
    int N; cin >> N;
    for (int i=0; i<4; i++) {
        cin >> s[i];
        s[i]+="1";
    }
    for (int i=0; i<N; i++) {
        string x; cin >> x;
        int temp=x.size();
        for (int j=0; j<4-temp; j++) x+="1";
        solve(x);
    }
}
