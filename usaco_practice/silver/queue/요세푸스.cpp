#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    queue <int> q;
    vector <int> yosepus;
    for (int i=1; i<=n; i++) q.push(i);
    while (q.size()>0) {
        for (int i=0; i<k-1; i++) {
            q.push(q.front());
            q.pop();
        }
        yosepus.push_back(q.front());
        q.pop();
    }
    cout << "<";
    for (int i=0; i<n-1; i++) cout << yosepus[i] << ", ";
    cout << yosepus[n-1] << ">";
    return 0;
}
