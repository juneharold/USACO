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
        while (!s.empty() && s.top() > c) s.pop();
        if (s.empty() or s.top()<c) {
            cnt++;
            s.push(c);
        }
        pfs[i+1]=cnt;
    }
    cnt=0;
    reverse(seq.begin(), seq.end());
    stack <int> bs;
    for (int i=0; i<n; i++) {
        int c=seq[i];
        while (!bs.empty() && bs.top() > c) bs.pop();
        if (bs.empty() or bs.top()<c) {
            cnt++;
            bs.push(c);
        }
        sfs[i+1]=cnt;
    }
    //for (int i=0; i<=n; i++) cout << pfs[i] << " ";
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
