#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=2e5+5;
int k[MAX_N]={};
vector<int> stk; //consider as stack
long long ans=0;

/*
8
4 1 5 3 3 2 4 1 */
int main()
{
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> k[i];

    int cur_min=k[0];
    ans=k[0];

    for (int i=1; i<n; i++) {
        if (k[i]>=cur_min) {
            stk.push_back(k[i]);
            if (stk.size()*cur_min>ans) ans=stk.size()*cur_min;
        }
        else {
            if (stk.size()*cur_min>(stk.size()+1)*k[i]) {
                stk.clear();
                stk.push_back(k[i]);
                cur_min=k[i];
            }
            else {
                stk.push_back(k[i]);
                cur_min=k[i];
                if (stk.size()*cur_min>ans) ans=stk.size()*cur_min;
            }
        }
    }
    cout << ans;
}
