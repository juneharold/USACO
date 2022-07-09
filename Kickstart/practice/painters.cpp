#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int S, ra, pa, rb, pb, C;
int dr1[3]={0, 0, 1}, dp1[3]={-1, 1, 1}, dr2[3]={0, 0, -1}, dp2[3]={-1, 1, -1};

int idx (pii x) {
    int ret=((x.f-1)*(x.f-1)+x.s)-1;
    return ret;
}

bool trapped(string room, pii x) {
    if (x.s%2==1) {
        for (int i=0; i<3; i++) {
            pii nx{x.f+dr1[i], x.s+dp1[i]};
            if (nx.f<1 || S<nx.f || nx.s<1 || 2*nx.f-1<nx.s) continue;
            if (idx(nx)>=0 && idx(nx)<room.size() && room[idx(nx)]=='0') return false;
        }
    }
    else {
        for (int i=0; i<3; i++) {
            pii nx{x.f+dr2[i], x.s+dp2[i]};
            if (nx.f<1 || S<nx.f || nx.s<1 || 2*nx.f-1<nx.s) continue;
            if (idx(nx)>=0 && idx(nx)<room.size() && room[idx(nx)]=='0') return false;
        }
    }
    return true;
}

int solve(string room, pii A, pii B, int turn, int score) {
    //cout << A.f << ' ' << A.s << ' ' << B.f << ' ' << B.s << ' ' << score << endl;
    if (trapped(room, A) && trapped(room, B)) return score;
    if (turn==0 && trapped(room, A)) return solve(room, A, B, 1, score);
    if (turn==1 && trapped(room, B)) return solve(room, A, B, 0, score);

    if (turn==0) { // A의 차례
        int ret=-36;
        if (A.s%2==1) {
            for (int i=0; i<3; i++) {
                pii nx{A.f+dr1[i], A.s+dp1[i]};
                if (nx.f<1 || S<nx.f || nx.s<1 || 2*nx.f-1<nx.s) continue;
                if (idx(nx)<0 || idx(nx)>=room.size()) continue;
                if (room[idx(nx)]=='0') {
                    string nxtroom=room;
                    nxtroom[idx(nx)]='1';
                    ret=max(ret, solve(nxtroom, nx, B, 1-turn, score+1));
                }
            }
        }
        else {
            for (int i=0; i<3; i++) {
                pii nx{A.f+dr2[i], A.s+dp2[i]};
                if (nx.f<1 || S<nx.f || nx.s<1 || 2*nx.f-1<nx.s) continue;
                if (idx(nx)<0 || idx(nx)>=room.size()) continue;
                if (room[idx(nx)]=='0') {
                    string nxtroom=room;
                    nxtroom[idx(nx)]='1';
                    ret=max(ret, solve(nxtroom, nx, B, 1-turn, score+1));
                }
            }
        }
        return ret;
    }
    else { //B의 차례
        int ret=36;
        if (B.s%2==1) {
            for (int i=0; i<3; i++) {
                pii nx{B.f+dr1[i], B.s+dp1[i]};
                if (nx.f<1 || S<nx.f || nx.s<1 || 2*nx.f-1<nx.s) continue;
                if (idx(nx)<0 || idx(nx)>=room.size()) continue;
                if (room[idx(nx)]=='0') {
                    string nxtroom=room;
                    nxtroom[idx(nx)]='1';
                    ret=min(ret, solve(nxtroom, A, nx, 1-turn, score-1));
                }
            }
        }
        else {
            for (int i=0; i<3; i++) {
                pii nx{B.f+dr2[i], B.s+dp2[i]};
                if (nx.f<1 || S<nx.f || nx.s<1 || 2*nx.f-1<nx.s) continue;
                if (idx(nx)<0 || idx(nx)>=room.size()) continue;
                if (room[idx(nx)]=='0') {
                    string nxtroom=room;
                    nxtroom[idx(nx)]='1';
                    ret=min(ret, solve(nxtroom, A, nx, 1-turn, score-1));
                }
            }
        }
        return ret;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> S >> ra >> pa >> rb >> pb >> C;
        string room;
        for (int i=0; i<S*S; i++) room+='0';
        room[idx({ra, pa})]='1'; // 1은 칠해짐.
        room[idx({rb, pb})]='1';
        for (int i=0; i<C; i++) {
            int r, p; cin >> r >> p;
            room[idx({r, p})]='1';
        }

        cout << "Case #" << t << ": " << solve(room, {ra, pa}, {rb, pb}, 0, 0) << "\n";
    }
}

/*
1
3 3 3 3 1 0
*/
