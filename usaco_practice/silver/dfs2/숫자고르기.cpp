/*
1) 싸이클 만들기
2) 싸이클 이루는 노드의 합 + 노드의 주소
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int graph[105]={};
int visit[105]={};
vector <int> path;
set <int> in_cycle;
int counter=0;

void cycle(int cur)
{
    visit[cur]=1;
    path.push_back(cur);
    int next=graph[cur];
    if (visit[next]==1) {
        int add=0;
        //cout << "cur:" << cur << "\n";
        int indicator=0;
        for (int j=0; j<path.size(); j++)
        {
            if (path[j]==next or indicator==1) //if path after next
            {
                indicator=1;
                add+=1;
                in_cycle.insert(path[j]);
            }
        }
        counter+=add;
    }
    if (visit[next]==0) cycle(next);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    for (int i=1; i<=n; i++) cin >> graph[i];
    for (int i=1; i<=n; i++) {
        if (visit[i]==0) cycle(i);
        path.clear();
    }
    cout << counter << "\n";
    for (auto it=in_cycle.begin(); it!=in_cycle.end(); it++) cout << *it << "\n";
}

/*
7
3
1
1
5
5
4
6

3
3
1
1
*/
