#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector < int > graph[100005];

int main()
{
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    long long ans=0;
    for (int i=0; i<100005; i++) {
        if (graph[i].size()>ans) ans=graph[i].size();
    }
    cout << ans+1;
    return 0;
}
