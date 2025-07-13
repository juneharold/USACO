#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve(){
    ll n,k,x;
    cin >> n >> k >> x;
    x--;
    vector <ll> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];
    ll l = 0, h = 1e6, ans;
    while(l<=h){
        vector <ll> cnt;
        ll mid = (l+h)/2;
        for(int i=0;i<n;i++){
            if(a[i]>mid){
                cnt.push_back((a[i]-mid)*b[i]);
            }
        }
        sort(cnt.begin(),cnt.end());
        ll tot = max((ll)cnt.size()-x,0ll);
        ll sum = 0;
        for(int i=0;i<tot;i++){
            sum+=cnt[i];
        }
        if(sum<k){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int repeat = 1;
    while(repeat--){
        solve();
    }
}