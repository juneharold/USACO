#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int N, visit[1000005]={}, binary[1000005]={}, height[1000005]={};
vector<int> tree[1000005];

pair<int, int> solve(int cur) {
    if (cur<0) return make_pair(-cur, 0);

    pair<int, int> a=solve(tree[cur][0]), b=solve(tree[cur][1]);

    if (a>b) swap(a, b);

}

/*
int find_depth(int cur) {
    if (cur<0) return 0;
    if (height[cur]!=0) return height[cur];
    for (auto nx: tree[cur]) {
        height[cur]=max(height[cur], find_depth(nx));
    }
    return height[cur]+1;
}

int solve(int cur) {
    if (cur<0) return -cur;
    visit[cur]=1;
    int a=solve(tree[cur][0]), da=find_depth(tree[cur][0]);
    int b=solve(tree[cur][1]), db=find_depth(tree[cur][1]);

    if (da==0 && db==0) {

    }


}*/

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) {
        int a, b; cin >> a >> b;
        tree[i].push_back(a);
        tree[i].push_back(b);
    }

    //cout << find_depth(1) << " " << find_depth(2);
}
