#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

int M, S, fish[105][5][5][8]={}, smell[5][5]={}; 
int dx8[8]={0, -1, -1, -1, 0, 1, 1, 1}, dy8[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dx4[4]={-1, 0, 1, 0}, dy4[4]={0, -1, 0, 1};
pair<int, int> shark;

void fishmove(int idx) {
    for (int i=1; i<=4; i++) {
        for (int j=1; j<=4; j++) {
            for (int k=0; k<8; k++) {
                bool moved=false;
                for (int l=0; l<8; l++) { // l is for changing direction 
                    int ni=i+dx8[(k-l+8)%8], nj=j+dy8[(k-l+8)%8];
                    if (ni<1 || ni>4 || nj<1 || nj>4) continue;
                    if (smell[ni][nj]>0 || make_pair(ni, nj)==shark) continue;
                    fish[idx][ni][nj][(k-l+8)%8]+=fish[idx-1][i][j][k];
                    moved=true;
                    break;
                }
                if (!moved) fish[idx][i][j][k]+=fish[idx-1][i][j][k];
            }
        }
    }
}

void sharkmove(int idx) {
    int Maxcnt=0;
    pair<int, int> movement[4];
    movement[0]=shark;
    for (int i=3; i>=0; i--) {
        int nx1=shark.f+dx4[i], ny1=shark.s+dy4[i];
        if (nx1<1 || nx1>4 || ny1<1 || ny1>4) continue;
        for (int j=3; j>=0; j--) {
            int nx2=nx1+dx4[j], ny2=ny1+dy4[j];
            if (nx2<1 || nx2>4 || ny2<1 || ny2>4) continue;
            for (int k=3; k>=0; k--) {
                int nx3=nx2+dx4[k], ny3=ny2+dy4[k];
                if (nx3<1 || nx3>4 || ny3<1 || ny3>4) continue;
                int cnt=0;
                for (int l=0; l<8; l++) cnt+=fish[idx][nx1][ny1][l];
                if (make_pair(nx1, ny1)!=make_pair(nx2, ny2)) {
                    for (int l=0; l<8; l++) cnt+=fish[idx][nx2][ny2][l];
                }
                if (make_pair(nx3, ny3)!=make_pair(nx1, ny1) && make_pair(nx3, ny3)!=make_pair(nx2, ny2)) {
                    for (int l=0; l<8; l++) cnt+=fish[idx][nx3][ny3][l];
                }

                if (cnt>=Maxcnt) {
                    movement[1]={nx1, ny1};
                    movement[2]={nx2, ny2};
                    movement[3]={nx3, ny3};
                    Maxcnt=cnt;
                }
            }
        }
    }

    for (int i=1; i<4; i++) {
        int x=movement[i].f, y=movement[i].s;
        for (int j=0; j<8; j++) { //direction of fishes at x, y
            if (fish[idx][x][y][j]>0) {
                fish[idx][x][y][j]=0;
                smell[x][y]=3;
            }
        }
        shark=movement[i];
    }
}

void erase_smell() {
    for (int i=1; i<=4; i++) {
        for (int j=1; j<=4; j++) {
            if (smell[i][j]>0) smell[i][j]--;
        }
    }
}

void copy_fish(int idx) {
    for (int i=1; i<=4; i++) {
        for (int j=1; j<=4; j++) {
            for (int k=0; k<8; k++) {
                fish[idx][i][j][k]+=fish[idx-1][i][j][k];
            }
        }
    }
}

void practice(int idx) {
    fishmove(idx);
    sharkmove(idx);
    erase_smell();
    copy_fish(idx);
}

int main()
{
    cin >> M >> S;
    for (int i=1; i<=M; i++) {
        int fx, fy, d; cin >> fx >> fy >> d;
        fish[0][fx][fy][d-1]++;
    }
    cin >> shark.f >> shark.s;

    for (int i=1; i<=S; i++) {
        practice(i);
    }
    
    int ans=0;
    for (int i=1; i<=4; i++) {
        for (int j=1; j<=4; j++) {
            for (int k=0; k<8; k++) {
                ans+=fish[S][i][j][k];
            }
        }
    }
    cout << ans;
}