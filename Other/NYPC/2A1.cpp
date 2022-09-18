#include<iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second

int a[200005]={}, cur[1000005]={};

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];

    int ans=1, l=1, r=1;
    cur[a[1]]=1;
    while (l<=r && r<=N) {
        if (cur[a[r+1]]==0) {
            cur[a[r+1]]++;
            r++;
        }
        else if (l==r) {
            l++;
            r++;
        }
        else {
            cur[a[l]]--;
            l++;
        }
        if (l<=r && r<=N) ans=max(ans, r-l+1);
    }
    cout << ans;
}
/*
4
1 1 2 3
*/
