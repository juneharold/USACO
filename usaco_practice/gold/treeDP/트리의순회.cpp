#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int N, in[100005]={}, post[100005]={}, idx[100005]={};
pair<int, int> child[100005]={};

void preorder(int ins, int ine, int pos, int poe) {
    if (ins>ine || pos>poe) return;
    int root=post[poe];
    cout << root << " ";
    preorder(ins, idx[root]-1, pos, pos+idx[root]-ins-1);
    preorder(idx[root]+1, ine, pos+idx[root]-ins, poe-1);
}


int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> in[i];
        idx[in[i]]=i;
    }
    for (int i=1; i<=N; i++) cin >> post[i];

    preorder(1, N, 1, N);
}
