#include <iostream>
using namespace std;

char graph[105][105]={};
char graph2[105][105]={};
int visit_1[105][105]={};
int visit_2[105][105]={};
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

void dfs(int Y, int X, char color)
{
    visit_1[Y][X]=1;
    for (int i=0; i<4; i++)
    {
        int next_Y=Y+dy[i], next_X=X+dx[i];
        if (visit_1[next_Y][next_X]==0 and graph[next_Y][next_X]==color)
        {
            dfs(next_Y, next_X, color);
        }
    }
}

void dfs2(int Y, int X, char color)
{
    visit_2[Y][X]=1;
    for (int i=0; i<4; i++)
    {
        int next_Y=Y+dy[i], next_X=X+dx[i];
        if (visit_2[next_Y][next_X]==0 and graph2[next_Y][next_X]==color)
        {
            dfs2(next_Y, next_X, color);
        }
    }
}


int main()
{
    int N;
    cin >> N;
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            char a;
            cin >> a;
            // input for graph 1
            graph[i][j]=a;
            // input for graph 2
            if (a=='R')
            {
                graph2[i][j]='G';
            }
            else
            {
                graph2[i][j]=a;
            }
        }
    }
    // dfs-------------
    int counter1=0, counter2=0;
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            if (visit_1[i][j]==0)
            {
                char color=graph[i][j];
                counter1++;
                dfs(i, j, color);
            }
            if (visit_2[i][j]==0)
            {
                char color=graph2[i][j];
                counter2++;
                dfs2(i, j, color);
            }
        }
    }
    cout << counter1 << " " << counter2;
}
