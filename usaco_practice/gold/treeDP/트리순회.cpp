#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int N, visit[27]={};
vector<int> graph[27];

void preorder(int cur) {
    visit[cur]=1;
    cout << (char)(cur+'A');
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx<0) continue;
        if (visit[nx]==0) preorder(nx);
    }
}

void inorder(int cur) {
    visit[cur]=1;
    int nx=graph[cur][0];
    if (nx>0 && visit[nx]==0) inorder(nx);
    cout << (char)(cur+'A');
    nx=graph[cur][1];
    if (nx>0 && visit[nx]==0) inorder(nx);
}

void postorder(int cur) {
    visit[cur]=1;
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx<0) continue;
        if (visit[nx]==0) postorder(nx);
    }
    cout << (char)(cur+'A');
}

int main()
{
    cin >> N;
    for (int i=0; i<N; i++) {
        char x, a, b; cin >> x >> a >> b;
        int X=x-'A', A=a-'A', B=b-'A';
        graph[X].push_back(A);
        graph[X].push_back(B);
    }

    preorder(0);
    cout << "\n";

    fill(&visit[0], &visit[26], 0);
    inorder(0);
    cout << "\n";

    fill(&visit[0], &visit[26], 0);
    postorder(0);
}
