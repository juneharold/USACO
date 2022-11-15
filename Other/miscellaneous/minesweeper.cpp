#include <iostream>
#include <algorithm>
using namespace std;

char field[105][105]={};
int di[8]={1, 1, 1, -1, -1, -1, 0, 0}, dj[8]={0, 1, -1, 0, 1, -1, 1, -1};

int main()
{
    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) cin >> field[i][j];

    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        if (field[i][j]=='*') continue;
        int target, cnt=0;
        if (field[i][j]=='.') target=0;
        else target=field[i][j]-'0';

        for (int k=0; k<8; k++) {
            int ni=i+di[k], nj=j+dj[k];
            if (ni<1 || ni>N || nj<1 || nj>M) continue;
            if (field[ni][nj]=='*') cnt++;
        }

        if (target!=cnt) {
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
}

/*
2 2
**
**
*/
