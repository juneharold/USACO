#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, p[55]={}, cntleafs[55]={};
vector<int> nxt[55];

void dfs(int cur) {
    if (nxt[cur].size()==0) {
        cntleafs[cur]=1;
    }
    else {
        for (int nx: nxt[cur]) {
            dfs(nx);
            cntleafs[cur]+=cntleafs[nx];
        }
    }
}

int main()
{
    cin >> N;
    int start;
    for (int i=0; i<=N-1; i++) {
        cin >> p[i];
        if (p[i]==-1) {
            start=i;
            continue;
        }
        nxt[p[i]].push_back(i);
    }
    dfs(start);
    int erase; cin >> erase;
    if (nxt[p[erase]].size()==1) cout << cntleafs[start]-cntleafs[erase]+1;
    else cout << cntleafs[start]-cntleafs[erase];
}

/*
4
-1 0 1 2
2
*/