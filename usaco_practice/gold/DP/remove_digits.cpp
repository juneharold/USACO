#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=1e6+5;
int dp[MAX_N]={}, n;
vector<int> digits;

void find_digits (int num) {
    while (num>0) {
        digits.push_back(num%10);
        num/=10;
    }
}

int main()
{
    cin >> n;
    fill(&dp[0], &dp[MAX_N], 1e9);
    dp[0]=0;

    for (int i=1; i<=n; i++) {
        find_digits(i);
        for (auto digit: digits) {
            if (i-digit>=0) dp[i]=min(dp[i], dp[i-digit]+1);
        }
        digits.clear();
    }
    cout << dp[n];
}
