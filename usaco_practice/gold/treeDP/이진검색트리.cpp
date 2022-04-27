#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int node[10005]={};
pair<int, int> child[10005]={};

void dfs1(int cur, int idx) {
    if (node[idx]>node[cur]) {
        if (child[cur].s==0) child[cur].s=idx;
        else dfs1(child[cur].s, idx);
    }
    else {
        if (child[cur].f==0) child[cur].f=idx;
        else dfs1(child[cur].f, idx);
    }
}

void dfs2(int cur) {
    if (child[cur].f!=0) dfs2(child[cur].f);
    if (child[cur].s!=0) dfs2(child[cur].s);
    cout << node[cur] << "\n";
}

int main()
{
    fill(&child[1], &child[10001], make_pair(0, 0));
    int x, idx=1;
    while (cin >> x) node[idx++]=x;
    idx--;

    for (int i=2; i<=idx; i++) {
        dfs1(1, i);
    }

    dfs2(1);
}
