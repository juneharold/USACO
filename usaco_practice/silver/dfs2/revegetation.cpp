#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector < pair <int, int> > graph[100005];
int visit[100005];
long long counter=0; // counts the number of connected components
int check=1;

void dfs(int cur, int color)
{
    visit[cur]=color;
    for (int j=0; j<graph[cur].size(); j++)
    {
        int next=graph[cur][j].first;
        if (visit[next]==0 and graph[cur][j].second=='S') {
            dfs(next, visit[cur]);
        }
        else if (visit[next]==0 and graph[cur][j].second=='D') {
            dfs(next, 3-visit[cur]); // 색깔을 1와 2로 나눔.
        }
        else if (visit[cur]+visit[next]==3 and graph[cur][j].second=='S') {
            check=0;
            break;
        }
        else if (visit[cur]==visit[next] and graph[cur][j].second=='D') {
            check=0;
            break;
        }
    }
    if (check==0) return;
}

void ToBinary(long long number)
{
    // array to store binary number
    int binaryNum[32];
    // counter for binary array
    int i = 0;
    while (number > 0) {
        // storing remainder in binary array
        binaryNum[i] = number % 2;
        number = number / 2;
        i++;
    }
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

int main()
{
    //freopen("revegetate.in", "r", stdin);
    //freopen("revegetate.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        char a;
        int num1, num2;
        cin >> a >> num1 >> num2;
        graph[num1].push_back(make_pair(num2, a));
        graph[num2].push_back(make_pair(num1, a));
    }
    for (int i=1; i<=n; i++)
    {
        if (visit[i]==0)
        {
            dfs(i, 1);
            if (check==1) counter++;
        }
    }
    long long ans=1;
    for (int i=0; i<counter; i++) ans*=2;
    //cout << ans;
    if (ans==1) cout << 0;
    else ToBinary(ans);
}

/*
3 2
S 1 2
D 3 2

9 8
S 1 2
D 3 2
D 3 4
S 2 4
S 5 6
D 7 8
D 8 9
D 7 9
*/
