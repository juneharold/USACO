#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/*
greedy - if k is answer, choose k smallest weights
sort, binary search and pick 1~mid elements 
put weight in bag with most weight remaining. 
*/

int main()
{
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    int lo=0, hi=m;
    while (lo<hi) {
        int mid=(lo+hi+1)/2;
        priority_queue<int> pq;
        for (int i=0; i<n; i++) pq.push(a[i]);
        bool possible=true;
        for (int i=mid-1; i>=0; i--) {
            if (pq.top()<b[i]) {
                possible=false;
                break;
            }
            int temp=pq.top()-b[i];
            pq.pop();
            pq.push(temp);
        }
        if (possible) lo=mid;
        else hi=mid-1;
    }
    cout << lo;
}