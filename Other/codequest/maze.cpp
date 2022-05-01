#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long
#define db double

char graph[1000][1000];
int visit[1000][1000]={}, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};

int main()
{
    int T; cin >> T;
    while (T--) {
        //input
        int H, W, idx=0; cin >> H >> W;
        string dummy; getline(cin, dummy);
        pair<int, int> se[40];
        for (int i=1; i<=H; i++) {
            string s; getline(cin, s);
            for (int j=1; j<=(W-1)/3; j++) {
                graph[i][j]=s[3*j-3];
                if (i%2==0 && graph[i][j]!='|') {
                    se[idx]={i, j};
                    idx++;
                }
                char a=s[3*j-2], b=s[3*j-1];
                if (a==' ') graph[i][j]=' ';
                else if (a=='-') graph[i][j]='-';
                else {
                    graph[i][j]=' ';
                    se[idx]={i, j};
                    idx++;
                }
            }
            graph[i][(W-1)/3+1]=s[W-1];
        }
        for (int i=1; i<=H; i++) {
            for (int j=1; j<=(W-1)/3+1; j++) {
                cout << graph[i][j];
            }
            cout << endl;
        }

        for (int i=0; i<40; i++) cout << se[i].f << " " << se[i].s << endl;

        // bfs
        /*
        queue<pair<int, int>> q;
        q.push(se[0]);
        visit[se[0].f][se[0].s]=1;
        while (!q.empty()) {
            int x=q.front().f, y=q.front().s;
            q.pop();
            for (int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if (visit[])
            }
        }*/
    }
}

/*
2
11 16
+vv+--+--+--+--+
|        |     |
+--+  +--+  +--+
|  |     |     |
+  +--+  +--+  +
|              |
+  +--+--+  +--+
|     |        |
+--+  +  +--+  +
|           |  >
+--+--+--+--+--+

*/
/*
#include <bits/stdc++.h>
using namespace std;

int N, H, W, sy, sx, ey, ex;
char A[1005][1005];
int V[1005][1005];
int bfs() {
    queue<pair<int, int> > q;
    q.push({sy, sx});
    V[sy][sx] = 1;

    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();

        if (y == ey && x == ex) return V[y][x];

        if (y>2 && A[y-1][x] == ' ' && V[y-2][x] == 0) {
            V[y-2][x] = V[y][x] + 1;
            q.push({y-2, x});
        } if (y<H-2 && A[y+1][x] == ' ' && V[y+2][x] == 0) {
            V[y+2][x] = V[y][x] + 1;
            q.push({y+2, x});
        } if (x>2 && A[y][x-1] == ' ' && V[y][x-3] == 0) {
            V[y][x-3] = V[y][x] + 1;
            q.push({y, x-3});
        } if (x<W-3 && A[y][x+2] == ' ' && V[y][x+3] == 0) {
            V[y][x+3] = V[y][x] + 1;
            q.push({y, x+3});
        }
    }

    return -1;
}


int main() {
    cin >> N;

    while (N--) {
        cin >> H >> W;
        char t;
        for (int i=0; i<H; i++) {
            scanf("%c", &t);
            for (int j=0; j<W; j++) {
                V[i][j] = 0;
                scanf("%c", &t);
                A[i][j] = t;
                if (i == 0) {
                    if (t == 'v') {
                        sy = i+1;
                        sx = j-1;
                    } else if (t == '^') {
                        ey = i+1;
                        ex = j-1;
                    }
                } else if (i == H-1) {
                    if (t == 'v') {
                        ey = i-1;
                        ex = j-1;
                    } else if (t == '^') {
                        sy = i-1;
                        sx = j-1;
                    }
                } else if (j == 0) {
                    if (t == '<') {
                        ey = i;
                        ex = j+1;
                    } else if (t == '>') {
                        sy = i;
                        sx = j+1;
                    }
                } else if (j == W-1) {
                    if (t == '<') {
                        sy = i;
                        sx = j-2;
                    } else if (t == '>') {
                        ey = i;
                        ex = j-2;
                    }
                }
            }
        }

        cout << bfs() << "\n";
    }
}
*/
