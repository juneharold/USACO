#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int N, Q, P[100005], Color[100005], H[100005];
vector<int> adj[100005];

int LCA(int a, int b, int c) {
  int ret = 0;
  while (a != b) {
    if (H[a] > H[b]) {
      if (Color[a] == c) ret++;
      a = P[a];
    } else if (H[a] < H[b]) {
      if (Color[b] == c) ret++;
      b = P[b];
    } else {
      if (Color[a] == c) ret++;
      a = P[a];
      if (Color[b] == c) ret++;
      b = P[b];
    }
  }
  if (Color[a] == c) ret++;
  return ret;
}

void dfs(int cur, int bef) {
  H[cur] = H[bef]+1;
  for (int nxt: adj[cur]) {
    if (nxt == bef) continue;
    P[nxt] = cur;
    dfs(nxt, cur);
  }
}

int main() {
  cin >> N >> Q;
  for (int i=1; i<=N; i++) cin >> Color[i];
  for (int i=1; i<=N-1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, 0);

  int op, a, b, c;
  for (int i=1; i<=Q; i++) {
    cin >> op >> a >> b;

    if (op == 1) {
      Color[a] = b;
    } else {
      cin >> c;
      cout << LCA(a, b, c) << "\n";
    }
  }
}
