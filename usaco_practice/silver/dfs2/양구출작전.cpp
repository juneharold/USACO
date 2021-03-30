#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair <char, int> SheWol[123460]={}; //first는 wolf or sheep, second는 마릿수 저장
int visit[123460]={};
vector <int> tree[123460];
long long sheep_num=0;
long long fucking_wolves[123460]={};
long long wolves=0;

void cnt_sheep(int cur, int wolf)
{
    visit[cur]=1;
    if (SheWol[cur].first=='S' and SheWol[cur].second>=wolf)
    {
        sheep_num+=SheWol[cur].second-wolf;
        wolves=0;
    }
    else if (SheWol[cur].first=='S' and SheWol[cur].second<wolf)
    {
        wolves-=SheWol[cur].second;
    }
    else
    {
        wolves+=SheWol[cur].second;
    }
    fucking_wolves[cur]=wolves;
    for (int j=0; j<tree[cur].size(); j++)
    {
        int next=tree[cur][j];
        if (visit[next]==0) cnt_sheep(next, fucking_wolves[cur]);
        /*
        만약 갈랫 섬에 돌아간다면 wolf 수는 리셋된다.
        아이디어:
        각 섬마다 wolf 누적합을 array에 저장함.
        */
        fucking_wolves[cur]=wolves;
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
    cnt_sheep(1, 0);
    for (int i=1; i<=N; i++) cout << fucking_wolves[i] << "\n";
    cout << sheep_num;
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
