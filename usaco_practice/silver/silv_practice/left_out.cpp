#include <iostream>
#include <algorithm>
using namespace std;

int N;
char grid[1005][1005]={};

int count(int i1, int i2, int j1, int j2, char b) {
    int total=0;
    for (int i=i1; i<=i2; i++) for (int j=j1; j<=j2; j++) if (grid[i][j]==b) total++;
    return total;
}

void convert(int i, int j) {
    if (grid[i][j]=='R') grid[i][j]='L';
    else grid[i][j]='R';
}

int main()
{
    freopen("leftout.in", "r", stdin);
    freopen("leftout.out", "w", stdout);

    cin >> N;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin >> grid[i][j];

    //convert to 'L'
    for (int j=1; j<=N; j++) {
        if (grid[1][j]=='R') {
            for (int i=1; i<=N; i++) convert(i, j);
        }
    }
    for (int i=1; i<=N; i++) {
        if (grid[i][1]=='R') {
            for (int j=1; j<=N; j++) convert(i, j);
        }
    }

    if (count(2, N, 2, N, 'L')==0) {
        cout << "1 1\n";
        return 0;
    }

    if (count(1, N, 1, N, 'R')==N-1) {
        for (int i=1; i<=N; i++) {
            if (count(i, i, 2, N, 'R')==N-1) {
                cout << i << " 1\n";
            }
        }
        for (int j=1; j<=N; j++) {
            if (count(2, N, j, j, 'R')==N-1) {
                cout << "1 " << j << "\n";
            }
        }
    }
    else if (count(2, N, 2, N, 'R')!=1) {
        cout << "-1\n";
    }
    else if (count(2, N, 2, N, 'R')==1) {
        for (int i=2; i<=N; i++) for (int j=2; j<=N; j++) if (grid[i][j]=='R') {
            cout << i << " " << j << "\n";
        }
    }
}
