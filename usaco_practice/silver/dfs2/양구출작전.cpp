#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair <char, int> SheWol[123460]={}; //first는 wolf or sheep, second는 마릿수 저장
int visit[123460]={};
long long size[123460]={};
vector <int> tree[123460];

void cnt_sheep(int cur)
{
    visit[cur]=1;
    for (int j=0; j<tree[cur].size(); j++)
    {
        int next=tree[cur][j];
        if (visit[next]==0)
        {
            cnt_sheep(next);
        }
    }
    for (int j=0; j<tree[cur].size(); j++)
    {
        int next=tree[cur][j];
        size[cur]+=size[next];
    }
    if (SheWol[cur].first=='W' and SheWol[cur].second>size[cur])
    {
        size[cur]=0;
    }
    else if (SheWol[cur].first=='W' and SheWol[cur].second<size[cur])
    {
        size[cur]-=SheWol[cur].second;
    }
    else if (SheWol[cur].first=='S')
    {
        size[cur]+=SheWol[cur].second;
    }
}

int main()
{
    int N; cin >> N;
    for (int i=2; i<=N; i++)
    {
        char t; int a, p;
        cin >> t >> a >> p;
        tree[i].push_back(p);
        tree[p].push_back(i);
        SheWol[i].first=t;
        SheWol[i].second=a;
    }
    cnt_sheep(1);
    cout << size[1];
    return 0;
}

/*
7
W 10 1
W 40 2
W 10 2
S 100 3
S 50 3
S 20 4
*/
