#include <iostream>
#include <algorithm>
using namespace std;

int visit[55][55]={};
int graph[55][55]={};
int dx[8]={1, -1, 0, 0, 1, 1, -1, -1};
int dy[8]={0, 0, 1, -1, 1, -1, 1, -1};

void dfs(int cury, int curx)
{
    visit[cury][curx]=1;
    for (int i=0; i<8; i++)
    {
        int NX=curx+dx[i], NY=cury+dy[i];
        if (graph[NY][NX]==1 and visit[NY][NX]==0)
        {
            visit[NY][NX]=1;
            dfs(NY, NX);
        }
    }
}

int main()
{
    while (true)
    {
        int w, h;
        cin >> w >> h;
        if (w==0 and h==0) break;
        for (int i=1; i<=h; i++)
        {
            for (int j=1; j<=w; j++)
            {
                cin >> graph[i][j];
            }
        }
        int counter=0;
        for (int i=1; i<=h; i++)
        {
            for (int j=1; j<=w; j++)
            {
                if (graph[i][j]==1 and visit[i][j]==0)
                {
                    counter++;
                    dfs(i, j);
                }
            }
        }
        /* testing if dfs() works
        for (int i=1; i<=h; i++)
        {
            for (int j=1; j<=w; j++)
            {
                cout << visit[i][j];
            }
            cout << "\n";
        }*/
        fill(&visit[0][0], &visit[54][55], 0);
        fill(&graph[0][0], &graph[54][55], 0);
        cout << counter << "\n";
    }
}

/*
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
0 0
*/
/*
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0
*/

