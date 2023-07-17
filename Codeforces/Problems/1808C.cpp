#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

pair<bool, string> find_num(string l, string r, int Min, int Max) {
    string ret="";

    while (l[0]==r[0]) {
        if (l[0]-'0'<Min || Max<l[0]-'0') return {false, ret};
        ret+=l[0];
        l=l.substr(1, l.size()-1);
        r=r.substr(1, r.size()-1);
    }
    for (int i=l[0]-'0'+1; i<=r[0]-'0'-1; i++) {
        if (Min<=i && i<=Max) {
            for (int j=0; j<l.size(); j++) ret+=to_string(i);
            return {true, ret};
        }
    }
    string s2="";
    if (Min<=l[0]-'0' && l[0]-'0'<=Max) {
        s2+=l[0];
        bool bigger=false;
        for (int i=1; i<l.size(); i++) {
            for (int j=Max; j>=Min; j--) {
                if (bigger) {
                    s2+=to_string(j);
                    break;
                }
                else if (j>=l[i]-'0'){
                    s2+=to_string(j);
                    if (j>l[i]-'0') bigger=true;
                    break;
                }
            }
        }
        if (s2.size()==l.size()) return {true, ret+s2};
    }

    s2="";
    if (Min<=r[0]-'0' && r[0]-'0'<=Max) {
        s2+=r[0];
        bool smaller=false;
        for (int i=1; i<r.size(); i++) {
            for (int j=Min; j<=Max; j++) {
                if (smaller) {
                    s2+=to_string(j);
                    break;
                }
                else if (j<=r[i]-'0'){
                    s2+=to_string(j);
                    if (j<r[i]-'0') smaller=true;
                    break;
                }
            }
            //cout << "s2: " << s2 << endl;
        }
        if (s2.size()==r.size()) return {true, ret+s2};
    }
    return {false, ret};
}

void solve() {
    string l, r; cin >> l >> r;
    if (l==r) {
        cout << l << "\n";
        return;
    }
    if (r.size()>l.size()) {
        string ret="";
        for (int i=0; i<l.size(); i++) ret+='9';
        cout << ret << "\n";
        return;
    }

    //cout << endl << find_num(l, r, 4, 5).second;

    int cnt=10;
    string ans="";
    for (int a=0; a<10; a++) {
        for (int b=a; b<10; b++) {
            auto res=find_num(l, r, a, b);
            if (res.first && b-a<cnt) {
                cnt=b-a;
                ans=res.second;
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
/*
1
799 886
*/