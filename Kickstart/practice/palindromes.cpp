#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int pfs[100005][26]={};

int solve(string s, int a, int b) {
    bool ret=1;
    if ((b-a+1)%2==0) {
        int cnt=0;
        for (int j=0; j<26; j++) {
            if ((pfs[b][j]-pfs[a-1][j])%2==1) cnt++;
        }
        if (cnt>0) ret=0;
    }
    else {
        int cnt=0;
        for (int j=0; j<26; j++) {
            if ((pfs[b][j]-pfs[a-1][j])%2==1) cnt++;
        }
        if (cnt>1) ret=0;
    }
    return ret;
}

int main()
{
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N, Q; cin >> N >> Q;
        string S; cin >> S;
        for (int i=1; i<=N; i++) {
            for (int j=0; j<26; j++) {
                if (j==S[i-1]-'A') pfs[i][j]=pfs[i-1][j]+1;
                else pfs[i][j]=pfs[i-1][j];
            }
        }

        int ans=0;
        for (int i=1; i<=Q; i++) {
            int x, y; cin >> x >> y;
            ans+=solve(S, x, y);
        }
        cout << "Case #" << t << ": " << ans << "\n";
        fill(&pfs[0][0], &pfs[100001][26], 0);
    }
}
