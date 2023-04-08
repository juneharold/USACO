#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

const ll mod=1e9+7;
ll kpower[100005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll T; cin >> T;
    for (ll t=1; t<=T; t++) {
        ll N, K; cin >> N >> K;
        string S; cin >> S;
        kpower[0]=1;
        for (ll i=1; i<=N; i++) {
            kpower[i]=kpower[i-1]*K;
            kpower[i]%=mod;
        }

        ll ans=0, NN=N;
        if (N%2==0) NN--;
        for (ll i=1; i<=NN/2+1; i++) {
            ll smaller=S[i-1]-97;
            ans+=smaller*kpower[NN/2+1-i];
            ans%=mod;
        }

        string temp="";
        for (ll i=1; i<=NN/2+1; i++) {
            temp+=S[i-1];
        }
        if (N%2==0) NN++;
        for (ll i=NN/2; i>=1; i--) {
            temp+=S[i-1];
        }

        if (temp<S) ans++;
        cout << "Case #" << t << ": "<< ans%mod << "\n";
    }
}
