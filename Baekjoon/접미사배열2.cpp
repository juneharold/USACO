#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int n, sa[nmax]={}, group[nmax]={}, nextGroup[nmax]={}, k;

bool cmp(int a, int b) {
    if (group[a] == group[b]) {
        int a_next = (a + k < n) ? group[a + k] : -1;
        int b_next = (b + k < n) ? group[b + k] : -1;
        return a_next < b_next;
    }
    return group[a] < group[b];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    n=s.size();
    for (int i=0; i<n; i++) {
        sa[i]=i;
        group[i]=s[i]-'a';
    }
    k=1;
    while (k<n) {
        sort(&sa[0], &sa[n], cmp);
        nextGroup[sa[0]]=0;
        for (int i=1; i<n; i++) {
            if (group[sa[i]]==group[sa[i-1]] && max(sa[i], sa[i-1])+k<n && group[sa[i]+k]==group[sa[i-1]+k]) nextGroup[sa[i]]=nextGroup[sa[i-1]];
            else nextGroup[sa[i]]=nextGroup[sa[i-1]]+1;
        }
        for (int i=0; i<n; i++) group[i]=nextGroup[i];
        k*=2;
    }
    for (int i=0; i<n; i++) cout << sa[i] << "\n";
}
