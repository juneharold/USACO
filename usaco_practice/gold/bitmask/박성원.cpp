/*
dp[i][j]=i개의 숫자를 사용, k로 나누었을때 나머지 j, 순열의 갯수
find dp[(1<<N)-1][0]

int ni=(i|(1<<a)), nj=(j*(10^num[a].size())%k+num[a]%k)%k
dp[ni][nj]+=dp[i][j]

*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long

ll N, K, dp[(1<<15)][105]={}, mod10[51]={}, numdiv[15]={};
string num[15]={};

int rem(string s, int divisor) {
    int ret=0;
    for (int i=0; i<s.size(); i++) {
        ret*=10;
        ret+=s[i]-'0';
        ret%=divisor;
    }
    return ret;
}

ll GCD(ll x, ll y){
    if (y==0) return x;
    return GCD(y, x%y);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) cin >> num[i];
    cin >> K;
    for (int i=0; i<N; i++) dp[(1<<i)][rem(num[i],K)]=1;

    //use memoization
    mod10[0]=1%K;
    for (int i=1; i<=50; i++) mod10[i]=(mod10[i-1]*10)%K;
    for (int i=0; i<N; i++) numdiv[i]=rem(num[i], K);

    for (int i=0; i<(1<<N); i++) {
        for (int j=0; j<K; j++) {
            if (dp[i][j]==0) continue;
            for (int a=0; a<N; a++) {
                if (i&(1<<a)) continue;
                int ni=(i|(1<<a)), nj=(j*mod10[num[a].size()]%K+numdiv[a])%K;
                dp[ni][nj]+=dp[i][j];
            }
        }
    }

    //find answer
    ll top=dp[(1<<N)-1][0], bottom=1;
    for (int i=1; i<=N; i++) bottom*=i;
    ll div=GCD(bottom,top);
    cout << top/div << "/" << bottom/div;
}