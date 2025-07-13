#include <bits/stdc++.h>
using namespace std;
const int nmax=200005;

int N;
vector<pair<int, int>> graph[nmax];
void input() {
    cin >> N;
    int rowsize=2*N+1, idx=0, cost, u, v;;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=rowsize-1; j++) {
            //cout << i << ' ' << j << ' ' << idx << endl;
            cin >> cost;
            ++idx;
            u=idx, v=idx+1;
            if (i%2==u%2) graph[u].push_back(make_pair(v, cost));
            else graph[v].push_back(make_pair(u, cost));
        }
        rowsize+=2;
    }
    idx++;
    for (int i=1; i<=N; i++) {
        rowsize-=2;
        for (int j=1; j<=rowsize-1; j++) {
            cin >> cost;
            ++idx;
            u=idx, v=idx+1;
            if (i%2==u%2) graph[u].push_back(make_pair(v, cost));
            else graph[v].push_back(make_pair(u, cost));
            //graph[idx].push_back(make_pair(idx+1, cost));
        }
    }
    idx=1, rowsize=2*N+1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=(rowsize+1)/2; j++) {
            cin >> cost;
            graph[idx].push_back(make_pair(idx+rowsize+(i==N ? 0 : 1), cost));
            idx+=2;
        }
        idx+=rowsize;
        rowsize+=2;
    }
    idx++;
    rowsize-=2;
    for (int i=1; i<=N-1; i++) {
        for (int j=1; j<=(rowsize-1)/2; j++) {
            cin >> cost;
            graph[idx].push_back(make_pair(idx+rowsize-1, cost));
        }
    }
}



int main()
{
    input();
    /*for (int i=1; i<=6; i++) {
        cout << "Node: " << i << "------------"<< endl;
        for (auto j: graph[i]) cout << "( " << j.first << ' ' << j.second << " ), ";
        cout << endl;
    }*/


}


