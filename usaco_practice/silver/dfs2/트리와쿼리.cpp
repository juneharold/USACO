#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int visit[1000000]={};
int size[1000000]={};
vector <int> tree[1000000];

void cnt_child(int cur)
{
    visit[cur]=1;
    for (int j=0; j<tree[cur].size(); j++)
    {
        int next=tree[cur][j];
        if (visit[next]==0)
        {
            cnt_child(next);
        }
    }
    for (int j=0; j<tree[cur].size(); j++)
    {
        int next=tree[cur][j];
        size[cur]+=size[next];
    }
    size[cur]++;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, R, Q; cin >> N >> R >> Q;
    for (int i=0; i<N-1; i++)
    {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cnt_child(R);
    for (int i=0; i<Q; i++)
    {
        int q; cin >> q;
        // q의 부모 찾기
        cout << size[q] << "\n";
    }
    return 0;
}
