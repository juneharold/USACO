#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int A[nmax]={}, pfs[1000005]={};

void solve() {
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
        pfs[A[i]]++;
    }
    for (int i=1e6; i>=1; i--) pfs[i]+=pfs[i+1];

    ll ans=0;
    for (int i=1e6; i>=1; i--) {
        int cnt=0;
        for (int k=1; i*k<=1e6; k++) {
            // count elements between i*k (inclusive) and i*(k+1) (exclusive)
            int temp=pfs[i*k]-pfs[min(i*(k+1), 1000001)];
            if (temp%2) cnt++;
        }
        if (cnt>2) continue;
        int bef=1;
        if (cnt==2) bef=0;
        for (int k=1; i*k<=1e6; k++) {
            // count elements between i*k (inclusive) and i*(k+1) (exclusive)
            int temp=pfs[i*k]-pfs[min(i*(k+1), 1000001)];
            if (temp%2 && bef%2)  {
                ans+=temp;
                //cout << i << ' ' << k << ' ' << temp << endl;
                break;
            }
            bef=temp;
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}


/*
N=2 
10 7
bessie can pick 10, 9, 8 from larger pile

N, a[i]<=100
try 1~a[i] at every i

s[1]=4 
left with:
# 4~7 = 3
# 8~11 = 2
# 12~15 = 1
then elsie win

or
left with:
# 4~7 = 2
# 8~11 = 2
# 12~15 = 2
Since whichever group elsie picks (there is even number), bessie can pick the same, making bessie win in the end. 

Winning condition: there are no odd size groups after bessie's first pick 
proof is trivial 

a[i]<=10^6
try every x=1~10^6 
can try every k x*k<=10^6 --> O(nlogn)
count number of elements in groups: k=1~m
--> can pick from odd group, and there should be no odd group in k from 1~m
--> two odd groups in a row  ** or ** one odd group k=1
*/