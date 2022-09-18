#include<iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second

ll K, A, B;

ll find_Nth(ll len, ll N) {
    cout << len << ' ' << N << endl;
    if (len==2) {
        if (K%2==0) return N-1;
        else return 2-N;
    }
    if (N<=len/2) return find_Nth(len/2, N);
    else {
        ll nx=(len/2+1)-(N-len/2);
        return find_Nth(len/2, nx);
    }
}

ll solve(ll len, ll N) {
    ll ret=0;
    for (int i=1; (1<<i)<=len; i++) {
        if ((1<<i)&N) {
            ret+=(1<<(i-1));
        }
    }
    ret+=find_Nth(len, N);
    return ret;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        cin >> K >> A >> B;
        ll leng=1;
        while (leng<B) leng*=2;
        //ll bb=max((ll)0, solve(leng, B)), aa=max((ll)0, solve(leng, A-1));
        cout << find_Nth(leng, B) << endl;
        //cout << bb << ' ' << aa << "\n";
        //cout << solve(len, B)-solve(len, A) << "\n";
    }
}
/*
1
2 1 4

1
3 4 7

3
2 1 4
3 4 7
1000000000000 12345678

Input
5
3 1 6
10 13 28
7 9 52
19 82 444
100000000001 12345678912 12345678999

Output
3
8
22
181
45
*/
