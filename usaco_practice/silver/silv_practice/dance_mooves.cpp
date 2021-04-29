#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int n, k;
pair <int, set<int> > graph[100005]; //1베이스
set <int> ans[100005]; //1 베이스
pair <int, int> k_seq[200005]; //0베이스
int arr[100005]={};//1 베이스
int visit[100005]={};
vector <int> path;
int start;
int final[100005]={};

void cycle (int cur) {
    visit[cur]=1;
    path.push_back(cur);
    ans[start].insert(graph[cur].second.begin(), graph[cur].second.end());
    int next=graph[cur].first;
    if (next!=start) cycle(next);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i=0; i<k; i++) cin >> k_seq[i].first >> k_seq[i].second;
    for (int i=1; i<=n; i++) {
        graph[i].second.insert(i);
        arr[i]=i;
    }
    for (int i=0; i<k; i++) {
        int a=k_seq[i].first, b=k_seq[i].second;
        graph[arr[a]].second.insert(b);
        graph[arr[b]].second.insert(a);
        swap(arr[a], arr[b]);
    }
    for (int i=1; i<=n; i++) {
        graph[arr[i]].first=i;
    }
    for (int i=1; i<=n; i++) {
        if (visit[i]==0) {
            start=i;
            cycle(i);
            final[i]=ans[i].size();
        }
        for (int j=0; j<path.size(); j++) final[path[j]]=ans[i].size();
        path.clear();
        ans[i].clear();
    }
    for (int i=1; i<=n; i++) {
        cout << final[i] << "\n";
    }
}
/*
lol
*/
