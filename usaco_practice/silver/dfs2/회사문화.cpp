#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compliment[100005]={};
int save[100005]={};
vector <int> tree[100005];
long long pfs=0;

void dfs(int cur, int pfs)
{
    pfs+=save[cur];
    compliment[cur]+=pfs;
    for (int j=0; j<tree[cur].size(); j++)
    {
        int next=tree[cur][j];
        dfs(next, pfs);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        int a; cin >> a;
        if (a==-1) continue;
        tree[a].push_back(i);
    }
    for (int i=0; i<m; i++)
    {
        int num, w;
        cin >> num >> w;
        save[num]+=w;
    }

    dfs(1, pfs);

    for (int i=1; i<=n; i++) cout << compliment[i] << " ";
    return 0;
}
