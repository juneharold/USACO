#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

char s1[nmax], s2[2*nmax];
int pfs[27][nmax]={}, d[2*nmax]={};
vector<pii> alt;

void manacher(int n) {
    int l=1, r=1;
    for (int i=1; i<=n; i++) {
        int j=l+(r-i);
        if (l<=j-d[j]) d[i]=d[j];
        else d[i]=max(0, j-l);
        while (1<=i-d[i]-1 && i+d[i]+1<=n) {
            if (s2[i-d[i]-1]==s2[i+d[i]+1]) d[i]++;
            else break;
        }
        if (i+d[i]>r) {
            r=i+d[i];
            l=i-d[i];
        }
    }
}

ll answer(ll l, ll r) {
    for (int j=0; j<26; j++) {
        if (pfs[j][r]-pfs[j][l-1]==r-l+1) return 0;
    }
    ll ans=0;
    auto it=lower_bound(alt.begin(), alt.end(), make_pair(r, 0LL));
    if (it==alt.end() || (*it).sc>l) ans+=(r-l+1)*(r-l)/2-1;
    else if ((*it).sc<=l) ans+=((r-l)/2)*(((r-l)/2)+1);
    ll l2=2*(l-1)+1, r2=2*(r-1)+1;
    /*for (int i=1; i<=2*(r+1)-1; i++) cout << s2[i];
    cout << endl;
    cout << d[5] << ' ' << l2 << ' ' << r2 << endl;*/
    if (2*d[(l2+r2)/2]+1<r2-l2+1) ans+=r-l+1;
    return ans;
}
/*
6 1
adddad
1 5
*/

int cnt=0;

void solve() {
    int n, q; cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> s1[i];

    for (int i=1; i<=n; i++) {
        for (int j=0; j<26; j++) pfs[j][i]=pfs[j][i-1]+(s1[i]==j+'a');
        s2[2*(i-1)+1]=s1[i];
        s2[2*(i-1)]='#';
    }
    manacher(2*n-1);
    for (int i=1; i<n; ) {
        if (s1[i]!=s1[i+1]) {
            int j=i+2;
            while (j<=n) {
                if (((j-i)%2==0 && s1[j]==s1[i]) || ((j-i)%2==1 && s1[j]==s1[i+1])) j++;
                else break;
            }
            alt.push_back({j-1, i});
            i=j-1;
        }
        else i++;
    }

    int l, r;
    while (q--) {
        cnt++;
        cin >> l >> r;
        /*if (cnt==102) {
            cout << l << r ;
            for (int i=1; i<=n; i++) cout << s1[i];
            cout << endl;
        }*/
        cout << answer(l, r) << "\n";
    }

    for (int i=1; i<=2*n; i++) d[i]=0;
    alt.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
