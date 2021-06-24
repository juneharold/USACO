#include <iostream>
#include <queue>
using namespace std;

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};
int map[1005][1005]={};
int visit[1005][1005][2]={};

struct pos {
    int x, y, wall;
};

int main()
{
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        char a; cin >> a;
        map[i][j]=a-48;
    }
    queue<pos> q;
    q.push({1, 1, 0});
    visit[1][1][0]=1;
    while (!q.empty())
    {
       pos cur = q.front();
       q.pop();

       for (int i=0; i<4; i++)
       {
           pos next;
           next.x = cur.x+dx[i];
           next.y = cur.y+dy[i];
           next.wall = cur.wall;

           if (next.x<1 || next.x>n || next.y<1 || next.y>m) continue;
           if (visit[next.x][next.y][cur.wall]) continue;

           if (visit[next.x][next.y][0]==0 or visit[next.x][next.y][1]==0)
           if (map[next.x][next.y]==0)
           {
               visit[next.x][next.y][next.wall] = visit[cur.x][cur.y][cur.wall]+1;
               q.push({next.x, next.y, next.wall});
           }
           else if (map[next.x][next.y]==1 && cur.wall==0)
           {
               visit[next.x][next.y][1] = visit[cur.x][cur.y][cur.wall]+1;
               next.wall=1;
               q.push(next);
           }
       }
   }

   if (visit[n][m][0]==0 && visit[n][m][1]==0) cout << -1;
   else {
       int ans=min(visit[n][m][1], visit[n][m][0]);
       if (visit[n][m][0]==0) cout << visit[n][m][1];
       else if (visit[n][m][1]==0) cout << visit[n][m][0];
       else cout << ans;
   }
}
