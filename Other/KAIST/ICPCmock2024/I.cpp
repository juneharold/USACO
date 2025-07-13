#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll dp[1<<18][3],a[1<<18][3],b[1<<18][3];
ll pw(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b==1)return a;
    ll temp=pw(a,b/2,mod);
    temp=(temp*temp)%mod;
    if(b%2)temp=(temp*a)%mod;
    return temp;
}
ll inv(ll k)
{
    return pw(k,mod-2,mod);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)cin>>a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)cin>>b[i][j];
    }
    dp[0][2]=1;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll temp=(a[i][0]+a[i][1]+a[i][2])*(b[i][0]+b[i][1]+b[i][2]);
        temp%=mod;
        temp=inv(temp);
        ll a_win=0;
        ll b_win=0;
        ll draw=0;
        for(int j=0;j<3;j++)
        {
            a_win+=a[i][j]*b[i][(j+1)%3];
            b_win+=a[i][(j+1)%3]*b[i][j];
            draw+=a[i][j]*b[i][j];
            a_win%=mod;
            b_win%=mod;
            draw%=mod;
        }
        a_win*=temp;
        b_win*=temp;
        draw*=temp;
        a_win%=mod;
        b_win%=mod;
        draw%=mod;
        ans+=(dp[i-1][0]*draw)%mod;
        ans%=mod;
        dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])*a_win;
        dp[i][0]%=mod;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])*b_win;
        dp[i][1]%=mod;
        dp[i][2]=(dp[i-1][2]*draw)%mod;
    }
    cout<<ans;
}