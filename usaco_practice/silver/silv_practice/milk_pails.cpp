#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int X, Y, K, M, counter, ans;
vector <pair<int, int>> graph[105][105];
int visit[105][105][105]={};

void dfs(int a, int b, int k) {
    visit[a][b][k]=1;
    /*
    1) a를 X만큼 채우기/비우기
    2) b를 Y만큼 채우기/비우기.
    3) a/b 를 b/a 로 옴기기.
    */
    if (a!=X) graph[a][b].push_back({X, b});
    if (b!=Y) graph[a][b].push_back({a, Y});
    if (a!=0) graph[a][b].push_back({0, b});
    if (b!=0) graph[a][b].push_back({a, 0});
    int d1=min(Y, a+b);
    if (d1==Y) graph[a][b].push_back({a+b-Y, Y});
    else if (d1==a+b) graph[a][b].push_back({0, a+b});
    int d2=min(X, a+b);
    if (d2==X) graph[a][b].push_back({X, a+b-X});
    else if (d2==a+b) graph[a][b].push_back({a+b, 0});

    for (int i=0; i<graph[a][b].size(); i++) {
        counter=k+1;
        int next_a=graph[a][b][i].first, next_b=graph[a][b][i].second;
        int M_prime=next_a+next_b;
        if (counter<=K) {
            ans=min(ans, abs(M-M_prime));
            if (visit[next_a][next_b][counter]==0) dfs(next_a, next_b, counter);
        }
    }
}

int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin >> X >> Y >> K >> M;
    ans=M-0;
    dfs(0, 0, 0);
    cout << ans;
}


/*
14 50 2 32
1 200 300 105
100 22 300 110
*/
