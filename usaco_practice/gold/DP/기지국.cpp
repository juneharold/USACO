#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=1e4+5;
int n;
int dp[MAX_N]={};
pair<int, int> loc[MAX_N];

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> loc[i].first >> loc[i].second;
        loc[i].second=abs(loc[i].second);
    }
    sort(&loc[1], &loc[n+1]);

    fill(&dp[1], &dp[MAX_N], 1e9);
    dp[0]=0;

    for (int i=1; i<=n; i++){
       int up=0;
       for (int j=i; j>=1; j--){
           up=max(up, loc[j].second);
           int area=max(loc[i].first-loc[j].first, up*2);
           dp[i]=min(dp[i], dp[j-1]+area);
       }
   }
   cout << dp[n];
}
