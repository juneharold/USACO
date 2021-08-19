#include <iostream>
#include <algorithm>
using namespace std;

#define f first
#define s second
#define ll long long
const ll MAX_N=5005, MAX_M=1e5+5, mod=1e9+7;
ll N, M, K, wl[MAX_N]={}, dp[MAX_N]={}, group[MAX_N]={}, lines[30]={};
pair<ll, ll> words[MAX_N];

long long exp(int base, int power){
   if(power==0) return 1;
   if(power==1) return (base+mod)%mod;
   long long ans=exp(base, power/2);
   ans=(ans*ans+mod)%mod;
   if(power%2==1) ans=(ans*base+mod)%mod;
   return (ans+mod)%mod;
}


int main()
{
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    cin >> N >> M >> K;
    for (ll i=1; i<=N; i++) {
        cin >> words[i].f >> words[i].s;
        wl[words[i].f]++;
    }
    for (ll i=1; i<=M; i++) {
        char e; cin >> e;
        lines[e-64]++;
    }

    dp[0]=1;
    for (ll i=1; i<=K; i++) {
        for (ll j=1; i-j>=0; j++) {
            dp[i]+=dp[i-j]*wl[j];
            dp[i]%=mod;
        }
    }

    for (ll i=1; i<=N; i++) {
        group[words[i].s]+=dp[K-words[i].f];
        group[words[i].s]%=mod;
    }

    ll answer=1;
    for (ll i=1; i<=26; i++) {
        if (lines[i]==0) continue;
        long long sum=0;
        for(int k=0; k<=N; k++){
            if(group[k]==0) continue;
            sum=(sum+exp(group[k], lines[i]))%mod;
        }
        answer=(sum*answer)%mod;
    }
    cout << answer;
}

/*
3 5 10
3 1
4 1
3 2
A
B
A
B
C
*/
