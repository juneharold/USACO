#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int pfs[100005]={}; //1베이스
int sfs[100005]={};

int main()
{
    int n, q; cin >> n >> q;
    stack <int> s;
    string seq; cin >> seq;
    long long cnt=0;
    for (int i=0; i<n; i++) {
        int c=seq[i];
        if (s.empty() or s.top()<c) {
            cnt++;
            s.push(c);
        }
        else {
            s.push(c);
        }
        pfs[i+1]=cnt;
    }
    cnt=0;
    stack <int> bs;
    reverse(seq.begin(), seq.end());
    for (int i=0; i<n; i++) {
        int c=seq[i];
        if (bs.empty() or bs.top()<c) {
            cnt++;
            bs.push(c);
        }
        else {
            bs.push(c);
        }
        sfs[i+1]=cnt;
    }
    for (int i=0; i<=n; i++) cout << sfs[i] << " ";
    for (int i=0; i<q; i++) {
        int a, b; cin >> a >> b;
        int ans=(pfs[a-1])+(sfs[n-b]);
        cout << ans << "\n";
    }
}

/*
8 2
ABBAABCB
3 6
1 4

4 1
ABCD
1 2

4 1
ACCA
2 3
*/
