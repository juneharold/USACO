#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const long long MAX_N=2e5+5;
long long k[MAX_N]={};
long long area[MAX_N]={};
stack<pair<long long, long long>> stk; //consider as stack
long long ans=0;

int main()
{
    long long n; cin >> n;
    for (long long i=0; i<n; i++) {
        cin >> k[i];
        while (!stk.empty() && stk.top().first>=k[i]) {
            stk.pop();
        }
        if (stk.empty()) {
            stk.push({k[i], i});
            area[i]=(i+1)*k[i];
            continue;
        }

        long long width=i-stk.top().second;
        area[i]=width*k[i];
        stk.push({k[i], i});
    }
    while (!stk.empty()) stk.pop();

    for (long long i=n-1; i>=0; i--) {
        while (!stk.empty() && stk.top().first>=k[i]) {
            stk.pop();
        }
        if (stk.empty()) {
            stk.push({k[i], i});
            area[i]=(n-i)*k[i];
            continue;
        }
        long long width=stk.top().second-i;
        area[i]+=(width-1)*k[i];
        stk.push({k[i], i});
    }
    //for (long long i=0; i<n; i++) cout << area[i] << " ";
    for (long long i=0; i<n; i++) if (area[i]>ans) ans=area[i];
    cout << ans;
}

/*
8
4 1 5 3 3 2 4 1

8
1 1 1 1 1 1 1 1

8
1 2 3 4 5 6 7 8
long long main()
{
    long long n; cin >> n;
    for (long long i=0; i<n; i++) cin >> k[i];

    long long cur_min=k[0];
    ans=k[0];

    for (long long i=1; i<n; i++) {
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
*/
