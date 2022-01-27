#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define f first
#define s second

int pfsx[200005][30]={}, pfsy[200005][30]={};
pair<int, int> locx[200005]={}, locy[200005]={};

void solve() {
    bool solved=false;
    string X, Y, W;
    cin >> X >> Y >> W;
    fill(&pfsx[0][0], &pfsx[X.size()+1][27], 0);
    fill(&pfsy[0][0], &pfsy[Y.size()+1][27], 0);

    //pfs
    pfsx[0][X[0]-'a']=1; pfsy[0][Y[0]-'a']=1;
    for (int i=1; i<X.size(); i++) for (int j=0; j<26; j++) {
        if (X[i]-'a'==j) pfsx[i][j]=pfsx[i-1][j]+1;
        else pfsx[i][j]=pfsx[i-1][j];
    }
    for (int i=1; i<Y.size(); i++) for (int j=0; j<26; j++) {
        if (Y[i]-'a'==j) pfsy[i][j]=pfsy[i-1][j]+1;
        else pfsy[i][j]=pfsy[i-1][j];
    }

    // greedy
    int x_ind=0;
    for (int i=0; i<W.size(); i++) {
        while (x_ind<X.size()) {
            if (X[x_ind]==W[i]) {
                locx[i].f=x_ind;
                x_ind++;
                break;
            }
            else x_ind++;
        }
    }
    x_ind=X.size()-1;
    for (int i=W.size()-1; i>=0; i--) {
        while (x_ind>=0) {
            if (X[x_ind]==W[i]) {
                locx[i].s=x_ind;
                x_ind--;
                break;
            }
            else x_ind--;
        }
    }

    int y_ind=0;
    for (int i=0; i<W.size(); i++) {
        while (y_ind<Y.size()) {
            if (Y[y_ind]==W[i]) {
                locy[i].f=y_ind;
                y_ind++;
                break;
            }
            else y_ind++;
        }
    }
    y_ind=Y.size()-1;
    for (int i=W.size()-1; i>=0; i--) {
        while (y_ind>=0) {
            if (Y[y_ind]==W[i]) {
                locy[i].s=y_ind;
                y_ind--;
                break;
            }
            else y_ind--;
        }
    }

    //solve
    for (int i=0; i<W.size()-1; i++) {
        int x1=locx[i].f, x2=locx[i+1].s, y1=locy[i].f, y2=locy[i+1].s;
        for (int j=0; j<26; j++) {
            int x_cnt, y_cnt;
            if (x2==0) x_cnt=0;
            else x_cnt=pfsx[x2-1][j]-pfsx[x1][j];
            if (y2==0) y_cnt=0;
            else y_cnt=pfsy[y2-1][j]-pfsy[y1][j];

            if (x_cnt>0 && y_cnt>0) {
                solved=true;
            }
        }
    }

    //checking before W[0]
    int x1=0, x2=locx[0].s, y1=0, y2=locy[0].s;
    for (int j=0; j<26; j++) {
        int x_cnt, y_cnt;
        if (x2==0) x_cnt=0;
        else x_cnt=pfsx[x2-1][j];
        if (y2==0) y_cnt=0;
        else y_cnt=pfsy[y2-1][j];

        if (x_cnt>0 && y_cnt>0) {
            solved=true;
        }
    }

    // checking after W[W.size()-1]
    x1=locx[W.size()-1].f; x2=X.size(); y1=locy[W.size()-1].f; y2=Y.size();
    for (int j=0; j<26; j++) {
        int x_cnt, y_cnt;
        if (x2==0) x_cnt=0;
        else x_cnt=pfsx[x2-1][j]-pfsx[x1][j];
        if (y2==0) y_cnt=0;
        else y_cnt=pfsy[y2-1][j]-pfsy[y1][j];

        if (x_cnt>0 && y_cnt>0) {
            solved=true;
        }
    }

    cout << solved << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int t=0; t<T; t++) {
        solve();
    }
}

/*
1
abcd
ad
ad
정답: 0

1
abcdc
dcee
d
정답: 1

2
ababca
cbabba
baa
aaabbbccc
caacbbc
ccc

1
babb
abab
ab
정답: 1
*/
