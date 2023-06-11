#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans=0;

void solve(vector<int> arr, int level) {
    if (level==N) {
        ans++;
        return;
    }
    for (int i=0; i<N; i++) {
        bool possible=true;
        for (int j=0; j<level; j++) {
            if (i==arr[j] || abs(level-j)==abs(i-arr[j])) possible=false;
        }
        if (possible) {
            arr[level]=i;
            solve(arr, level+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<int> chessboard(N+1, -1);
    solve(chessboard, 0);
    cout << ans;
}
