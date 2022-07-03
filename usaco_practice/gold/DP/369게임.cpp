#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long
const ll mod=20150523;
ll dp[100005][3][2][2]={};

ll solve(string A) {
    //basecase
    for (int x=0; x<=A[0]-'0'; x++) {
        if (x==A[0]-'0') dp[0][x%3][(x!=0 && x%3==0)][1]++;
        else dp[0][x%3][(x!=0 && x%3==0)][0]++;
    }
    //dp
    for (int i=0; i<A.size()-1; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<2; k++) {
                for (int l=0; l<2; l++) {
                    for (int x=0; x<10; x++) {
                        if (l==1 && x>A[i+1]-'0') continue;
                        dp[i+1][(j+x)%3][k||(x!=0 && x%3==0)][l&&(x==A[i+1]-'0')]+=dp[i][j][k][l]+mod;
                        dp[i+1][(j+x)%3][k||(x!=0 && x%3==0)][l&&(x==A[i+1]-'0')]%=mod;
                    }
                }
            }
        }
    }
    ll ret=dp[A.size()-1][0][0][0]+dp[A.size()-1][0][1][0]+dp[A.size()-1][0][0][1]+dp[A.size()-1][0][1][1];
    ret+=dp[A.size()-1][1][1][0]+dp[A.size()-1][2][1][0];
    ret+=dp[A.size()-1][1][1][1]+dp[A.size()-1][2][1][1];
    return (ret+mod)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s1, s2; cin >> s1 >> s2;
    ll ans=solve(s2);
    fill(&dp[0][0][0][0], &dp[100001][3][2][2], 0);
    ans-=solve(s1);
    // s1에 박수치는지 확인
    bool clap=false;
    ll sum=0;
    for (ll i=0; i<s1.size(); i++) {
        if (s1[i]-48!=0 && (s1[i]-48)%3==0) clap=true;
        sum+=s1[i]-48;
    }
    if (sum%3==0) clap=true;

    if (clap) cout << (ans+1+mod)%mod;
    else cout << (ans+mod)%mod;
}

/*
1 420
*/
