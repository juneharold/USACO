#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    string s; cin >> s;
    if (s.size()==1) {
        cout << s << "\n";
        return;
    }
    vector<int> cnt(10, 0);
    int sum=0;
    for (int i=0; i<s.size(); i++) {
        cnt[s[i]-'0']++;
        sum+=s[i]-'0';
    }

    for (int i=1; i<=sum; i++) {
        vector<int> ncnt=cnt;
        int num=i, temp=sum;
        string ans="";
        while (num>9) {
            ans+=to_string(num);
            int nx=0;
            while (num>0) {
                temp-=num%10;
                ncnt[num%10]--;
                nx+=num%10;
                num/=10;
            }
            num=nx;
        }
        ans+=to_string(num);
        temp-=num;
        ncnt[num%10]--;
        bool skip=false;
        for (int j=0; j<10; j++) {
            if (ncnt[j]<0) skip=true;
        }
        if (skip) continue;

        if (i==temp) { // found answer
            string ss="";
            for (int j=9; j>=0; j--) {
                for (int k=0; k<ncnt[j]; k++) ss+=j+'0';
            }
            ss+=ans;
            cout << ss << "\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
