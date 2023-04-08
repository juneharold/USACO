#include <iostream>
#include <string>
using namespace std;

const int MAX=2e6+5;
int trie[MAX][26]={}, cnt[MAX]={}, idx=1;

void insert(string x) {
    int cur=0;
    for (int i=0; i<x.size(); i++) {
        if (trie[cur][x[i]-'A']==0) trie[cur][x[i]-'A']=idx++;
        cnt[trie[cur][x[i]-'A']]++;
        cur=trie[cur][x[i]-'A'];
    }
}

int main()
{
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N, K; cin >> N >> K;
        for (int i=1; i<=N; i++) {
            string a; cin >> a;
            insert(a);
        }

        int ans=0;
        for (int i=1; i<=idx; i++) {
            ans+=cnt[i]/K;
        }
        cout << "Case #" << t << ": " << ans << "\n";
        idx=1;
        fill(&trie[0][0], &trie[MAX-1][26], 0);
        fill(&cnt[0], &cnt[MAX-1], 0);
    }
}
