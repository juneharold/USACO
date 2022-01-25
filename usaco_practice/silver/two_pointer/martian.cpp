#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MAX=200005;
int N, K, R, dna[MAX], need[MAX];
multiset<int> have;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K >> R;
    for (int i=0; i<N; i++) cin >> dna[i];

    fill(&need[0], &need[MAX], 1e9);
    for (int i=0; i<R; i++) {
        int a, b; cin >> a >> b;
        need[a]=b;
    }

    int l=0, r=0, ans=1e9;
    set<int> pass;

    while(r<N) {
        have.insert(dna[r]);
        if (have.count(dna[r])>=need[dna[r]]) {
            pass.insert(dna[r]);
        }
        r++;

        int num_dna=have.count(dna[l]);
        while (need[dna[l]]==1e9 || num_dna>need[dna[l]]) {
            if (have.find(dna[l])!=have.end()) {
                have.erase(have.find(dna[l]));
                num_dna-=1;
            }
            l++;
        }

        if (pass.size()==R) ans=min(ans, r-l);

    }
    if (ans==1e9) cout << "impossible";
    else cout << ans;

}

/*
11 4 4
0 1 2 2 3 2 0 0 1 2 3
0 1
1 1
2 1
3 1
*/
