#include <iostream>
#include <stack>
#include <string>
using namespace std;

int pfs[100005]={}; //0베이스

int main()
{
    int n, q; cin >> n >> q;
    stack <int> s;
    string seq; cin >> seq;
    long long cnt=0;
    for (int i=0; i<n; i++) {
        int c=seq[i];
        if (s.empty()) {
            cnt++;
            s.push(c);
        }
        else if (s.top()<c) {
            cnt++;
            s.push(c);
        }
        else {
            s.push(c);
        }
        pfs[i+1]=cnt;
    }
    for (int i=0; i<q; i++) {
        int a, b; cin >> a >> b;
        int ans;
        //cout << seq[b] << seq[a-2] << " ";
        if (a==1 or seq[b]>seq[a-2]) {
            ans=cnt-(pfs[b]-pfs[a-1])+1;
        }
        else {
            ans=cnt-(pfs[b]-pfs[a-1]);
        }
        cout << ans << "\n";
    }
}

/*
4 1
ABCD
1 2

4 1
ACCA
2 3
*/
