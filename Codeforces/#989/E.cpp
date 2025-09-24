#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=5e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<vector<int>> generate_permutations(int n, int k) {
    vector<vector<int>> permutations;
    vector<int> perm(n);
    for (int i=0; i<n; i++) perm[i]=i+1;
    do {
        permutations.push_back(perm);
        if (permutations.size()==k) break;
    } while (next_permutation(perm.begin(), perm.end()));
    return permutations;
}


void k_even(int n, int k) {
    vector<vector<int>> permutations=generate_permutations(n, k);
    set<vector<int>> s;
    for (auto a: permutations) {
        vector<int> temp(n);
        for (int i=0; i<n; i++) temp[i]=n+1-a[i];
        if (s.find(temp)==s.end()) s.insert(a);
        if (s.size()==k/2) break;
    } 
    
    if (s.size()!=k/2) cout << "NO\n";
    else {
        cout << "YES\n";
        for (auto a: s) {
            for (int i=0; i<n; i++) cout << a[i] << ' ';
            cout << "\n";
            for (int i=0; i<n; i++) cout << n+1-a[i] << ' ';
            cout << "\n";
        }
    }
}

void k_odd(int n, int k) {
    if (n%2==0) {
        cout << "NO\n";
        return;
    }
    
    set<vector<int>> s;
    vector<int> temp1(n), temp2(n), temp3(n);
    for (int i=0; i<n; i++) temp1[i]=i+1;
    for (int i=0; i<n; i++) temp2[(i+(n+1)/2)%n]=i+1;
    int mxsum=0;
    for (int i=0; i<n; i++) mxsum=max(mxsum, temp1[i]+temp2[i]);
    for (int i=0; i<n; i++) temp3[i]=mxsum-(temp1[i]+temp2[i])+1;
    s.insert(temp1);
    s.insert(temp2);
    s.insert(temp3);

    vector<vector<int>> permutations=generate_permutations(n, k);

    int cnt=(k-3)/2;
    for (auto a: permutations) {
        vector<int> temp(n);
        for (int i=0; i<n; i++) temp[i]=n+1-a[i];
        if (s.find(temp)==s.end() && s.find(a)==s.end()) {
            s.insert(a);
            cnt--;
        }
        if (cnt==0) break;
    } 

    if (cnt!=0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto a: s) {
        vector<int> b(n);
        for (int i=0; i<n; i++) b[i]=n+1-a[i];
        if (a==temp1 || b==temp1) continue;
        if (a==temp2 || b==temp2) continue;
        if (a==temp3 || b==temp3) continue;
        for (int i=0; i<n; i++) cout << a[i] << ' ';
        cout << "\n";
        for (int i=0; i<n; i++) cout << b[i] << ' ';
        cout << "\n";
    }
    for (int i=0; i<n; i++) cout << temp1[i] << ' ';
    cout << "\n";
    for (int i=0; i<n; i++) cout << temp2[i] << ' ';
    cout << "\n";
    for (int i=0; i<n; i++) cout << temp3[i] << ' ';
    cout << "\n";
}

ll fact[nmax];

void solve() {
    int n, k; cin >> n >> k;
    if (n==1 && k==1) {
        cout << "YES\n";
        cout << "1\n";
        return;
    }
    //cout << k << ' ' << fact[n] << ' ';
    if (k>fact[n]) {
        cout << "NO\n";
        return;
    }

    if (k%2==0) k_even(n, k);
    else k_odd(n, k);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fact[0]=1;
    for (ll i=1; i<=5e5; i++) fact[i]=min((ll)1e9, fact[i-1]*i);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
