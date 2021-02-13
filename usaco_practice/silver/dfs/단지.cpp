#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int graph[30][30]={};
int visit[30][30]={};
int dx[8]={1, -1, 0, 0};
int dy[8]={0, 0, 1, -1};

void dfs(int cury, int curx, int k)
{
    visit[cury][curx]=k;
    for (int i=0; i<4; i++)
    {
        int NX=curx+dx[i], NY=cury+dy[i];
        if (graph[NY][NX]==1 and visit[NY][NX]==0)
        {
            visit[NY][NX]=1;
            dfs(NY, NX, k);
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
            graph[i][j]=a-'0';
        }
    }
    int k=1, counter=0;
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            if (graph[i][j]==1 and visit[i][j]==0)
            {
                counter++;
                dfs(i, j, k);
                k++;
            }
        }
    }
    cout << counter << "\n";
    int cnt_apt[30*30]={};
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            if (visit[i][j]!=0)
            {
                cnt_apt[visit[i][j]]++;
            }
        }
    }
    vector <int> ans;
    for (int i=1; i<30*30; i++)
    {
        if (cnt_apt[i]!=0)
        {
            ans.push_back(cnt_apt[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
}

/*
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

3
100
010
010
*/
