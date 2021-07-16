#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N=2e5+5;
int n;
int arr[MAX_N]={};
int inpos_to_smlval[MAX_N]={};
stack<pair<int, int>> s; //first is value, second is initial position

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=n; i>=1; i--) {
        while (!s.empty()) {
            if (arr[i]<s.top().first) {
                inpos_to_smlval[s.top().second]=i;
                s.pop();
            }
            else {
                break;
            }
        }
        s.push(make_pair(arr[i], i));
    }
    while (!s.empty()) {
        inpos_to_smlval[s.top().second]=0;
        s.pop();
    }

    for (int i=1; i<=n; i++) {
        cout << inpos_to_smlval[i] << " ";
    }
}
