#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

/*
x and x+1 will have similar multiset of digits
split x into 3 parts. 
E.g:
133, 7, 99

the first part will not change for x+1, 
second part will increase by 1, 
third part will become something like 100

so for two different numbers will have same S(x), *if*
- first part is a permutation of one another
- their second and third part are same

*Only if?*
- No!
- counterexample: 199, 901 have same S(x) despite not satisfying conditions above

so we will only consider the numbers with first part non-decreasing 
-> to avoid obvious double counting 
plus we will keep a sorted array of (S(x), x) to know which numbers have same S(x) and remove them 

also, for sorting, some numbers' first part will have leading 0s. 
In this case, move thae smallest nonzero digit to the left (i.e. the first nonzero digit since it is non-decresing)

Lastly, before answering each TC, we will sort by (x, S(x)) then use binary search. 
*/

vector<pair<int, string>> v2;

void solve() {
    int n; cin >> n;
    int lo=0, hi=v2.size()-1;
    while (lo<hi) {
        int mid=(lo+hi+1)/2;
        if (v2[mid].fs<=n) lo=mid;
        else hi=mid-1;
    }
    cout << lo << "\n";
}

vector<pair<string, int>> v; // contains (S(x), x)

string S(int x) {
    string s1=to_string(x);
    string s2=to_string(x+1);
    s1+=s2;
    sort(s1.begin(), s1.end());
    return s1;
}

void add_number(string s) {
    if (s[0]=='0') {
        for (int i=0; i<s.size(); i++) {
            if (s[i]!='0') {
                swap(s[0], s[i]);
                break;
            }
        }
    }
    int x=stoi(s);
    v.push_back({S(x), x});
}

void recurse(string cur, int prev, bool flag) {
    if (cur.size()==9) return;

    if (flag) {
        string nx=cur;
        nx+='9';
        add_number(nx);
        recurse(nx, 9, true);
    }
    else {
        for (int i=0; i<prev; i++) {
            string nx=cur;
            nx+=(char)(i+'0');
            add_number(nx);
            recurse(nx, i, true);
        }
        for (int i=prev; i<10; i++) {
            string nx=cur;
            nx+=(char)(i+'0');
            add_number(nx);
            recurse(nx, i, false);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    recurse("", 0, false);
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        if (i>0 && v[i].fs==v[i-1].fs) continue;
        v2.push_back({v[i].sc, v[i].fs});
    }
    sort(v2.begin(), v2.end());

    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
