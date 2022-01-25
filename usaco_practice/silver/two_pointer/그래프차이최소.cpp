#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, w[55][55], num[2602], visit[55]={};
set<int> val;

void dfs (int cur, int MAX, int MIN) {
    visit[cur]=1;
    for (int nx=0; nx<N; nx++) {
        if (nx==cur || w[cur][nx]>MAX || w[cur][nx]<MIN) continue;
        if (visit[nx]==0) {
            dfs(nx, MAX, MIN);
        }
    }
}

int main()
{
    cin >> N;
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
        cin >> w[i][j];
        val.insert(w[i][j]);
    }

    int idx=0;
    for (auto it=val.begin(); it!=val.end(); it++) {
        num[idx]=(*it);
        idx++;
    }

    int l=0, r=0, ans=1e9;

    while (r<idx && l<idx) {
        int Max=num[r], Min=num[l];
        //cout << l << " " << r << "\n";

        bool valid=true;

        for (int c=0; c<N; c++) {
            dfs(c, Max, Min);
            for (int i=0; i<N; i++) {
                if (visit[i]==0) valid=false;
                visit[i]=0;
            }
        }

        if (valid==true) {
            ans=min(ans, Max-Min);
            if (ans==0) break;
            l++;
        }
        else {
            r++;
        }
    }
    cout << ans;

}

/*
4
0 11 13 13
10 0 12 13
10 10 0 11
12 10 10 0

3
0 1 1
0 0 0
1 1 0

3
0 0 0
0 0 0
0 0 0
*/
