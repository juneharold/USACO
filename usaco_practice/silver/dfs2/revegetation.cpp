#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> graph[100005];
int visit[100005];

void dfs(int cur)
{
    visit[cur]=1;
    for (int j=0; j<graph[cur].size(); j++)
    {
        int next=graph[cur][j];
        if (visit[next]==0) dfs(next);
    }
}

void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

int main()
{
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        char a;
        int num1, num2;
        cin >> a >> num1 >> num2;
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);
    }
    for (int i=1; i<=n; i++)
    {
        if (visit[i]==0)
        {
            dfs(i);
        }
    }
    decToBinary(ans);
    return 0;
}
