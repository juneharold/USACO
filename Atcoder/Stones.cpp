/*
dp[i]=win possible if there are i stones and taro plays next 
dp[i-a[j]]=1인 경우, if Taro choose a[j], then Jiro can win. 
*/
#include <iostream>
#include <algorithm>
using namespace std;

int a[100005]={}, dp[100005]={};

int main()
{
    int N, K; cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> a[i];
    for (int i=1; i<=K; i++) {
        for (int j=1; j<=N; j++) {
            if (i-a[j]>=0 && !dp[i-a[j]]) dp[i]=1;
        }
    }
    if (dp[K]) cout << "First";
    else cout << "Second";
}