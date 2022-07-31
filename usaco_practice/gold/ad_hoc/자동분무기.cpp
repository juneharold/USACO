#include <iostream>
#include <algorithm>
using namespace std;

int a[8][8]={}, b[8][8]={}, ans[8][8]={};

int calc(int x, int y, int type) {
    int ret=0;
    if (type==1) {
        for (int i=0; i<8; i++) ret+=a[i][y];
        for (int j=0; j<8; j++) ret+=a[x][j];
        return ret-a[x][y];
    }
    else {
        for (int i=0; i<8; i++) ret+=b[i][y];
        for (int j=0; j<8; j++) ret+=b[x][j];
        return ret-b[x][y];
    }
}

void add(int x, int y) {
    int ret=0;
    for (int i=0; i<8; i++) b[i][y]++;
    for (int j=0; j<8; j++) b[x][j]++;
    b[x][y]--;
}

int main()
{
    int M, K; cin >> M >> K;
    for (int i=0; i<8; i++) for (int j=0; j<8; j++) {
        cin >> a[i][j];
        a[i][j]-=M;
        //b[i][j]=M;
    }
    for (int i=0; i<8; i++) for (int j=0; j<8; j++) {
        if (abs(calc(i, j, 1))%2==1) {
            add(i, j);
            ans[i][j]=1;
        }
    }
    for (int i=0; i<8; i++) for (int j=0; j<8; j++) {
        if (ans[i][j]==1 && abs(calc(i, j, 2)-calc(i, j, 1))%4==2) {
            ans[i][j]=2;
        }
    }

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (ans[i][j]==2) cout << "- ";
            else if (ans[i][j]==1) cout << "+ ";
            else cout << ". ";
        }
        cout << "\n";
    }
}

/*
30
63
15 15 15 15 15 15 15 16
15 15 15 15 15 15 15 16
15 15 15 15 15 15 15 16
15 15 15 15 15 15 15 16
15 15 15 15 15 15 15 16
15 15 15 15 15 15 15 16
15 15 15 15 15 15 15 16
16 16 16 16 16 16 16 16
*/
