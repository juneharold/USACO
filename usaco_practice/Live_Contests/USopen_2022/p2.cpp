#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;
#define f first
#define s second
#define ll long long

string S, T;
int possible[30][30]={};

int main()
{
    cin >> S >> T;
    //cout << endl;
    for (int i=0; i<18; i++) {
        for (int j=0; j<18; j++) {
            string a="", b="";
            for (int k=0; k<S.size(); k++) {
                if (S[k]-97==i || S[k]-97==j) a+=S[k];
            }
            for (int k=0; k<T.size(); k++) {
                if (T[k]-97==i || T[k]-97==j) b+=T[k];
            }
            if (a==b) possible[i][j]=1;
            //cout << possible[i][j] << " ";
        }
        //cout << endl;
    }


    int Q; cin >> Q;
    for (int i=0; i<Q; i++) {
        string q; cin >> q;
        bool ret=true;
        for (int j=0; j<q.size(); j++) {
            for (int k=j; k<q.size(); k++) {
                int x=q[j]-97, y=q[k]-97;
                if (possible[x][y]==0 && possible[y][x]==0) ret=false;
            }
        }
        if (ret) cout << "Y";
        else cout << "N";
    }
}
