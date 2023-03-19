#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define f first
#define s second
int vst[100005]={};

int main()
{
    int N, K; cin >> N >> K;
    fill(&vst[0], &vst[100001], 1e9);
    vst[N]=0;
    deque<pair<int, int>> dq;
    dq.push_back({N, 0});
    while (!dq.empty()) {
        int cur=dq.front().f, Time=dq.front().s;
        dq.pop_front();
        if (Time>vst[cur]) continue;
        if (cur-1>=0 && Time+1<vst[cur-1]) {
            vst[cur-1]=Time+1;
            dq.push_back({cur-1, vst[cur-1]});
        }
        if (cur+1<=1e5 && Time+1<vst[cur+1]) {
            vst[cur+1]=Time+1;
            dq.push_back({cur+1, vst[cur+1]});
        }
        if (2*cur<=1e5 && Time<vst[2*cur]) {
            vst[2*cur]=Time;
            dq.push_front({2*cur, vst[2*cur]});
        }
    }
    cout << vst[K];
}