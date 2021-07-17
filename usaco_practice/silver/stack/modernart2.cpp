#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N=1e5+5;
int n;
int colors[MAX_N]={};
int S[MAX_N]={}, E[MAX_N]={};

int main()
{
    //freopen("art2.in", "r", stdin);
    //freopen("art2.out", "w", stdout);
    cin >> n;
    for (int i=0; i<=n+1; i++) S[i]=1e9;
    colors[0]=0; colors[n+1]=0;
    S[0]=0; E[0]=0;
    for (int i=0; i<=n+1; i++) {
        if (1<=i && i<=n) cin >> colors[i];
        S[colors[i]]=min(i, S[colors[i]]);
        E[colors[i]]=max(i, E[colors[i]]);
    }

    stack<int> stk;
    int ans=0;
    for (int i=0; i<=n+1; i++) {
        if (i==S[colors[i]]) {
            stk.push(colors[i]);
            if (stk.size()>ans) ans=stk.size();
        }
        if (i==E[colors[i]] && stk.top()==colors[i]) {
            stk.pop();
        }

    }
    if (!stk.empty()) {
        cout << -1;
        exit(0);
    }
    cout << ans-1;
}

/*
5
1
2
1
2
3

7
0
1
4
5
1
3
3
*/
