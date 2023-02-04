#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define f first
#define s second
#define ll long long

string colarr[9][3];
string rowarr[3][12];

vector<string> tokenize (string s) {
    s+=" ";
    vector<string> ret;
    string temp="";
    for (char x: s) {
        if (x==32) {
            ret.push_back(temp);
            temp="";
        }
        else temp+=x;
    }
    return ret;
}

string focus;
pair<int, pair<int, int>> loc;

void initialize() {
    //orange
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) {
        int x=i*3+j;
        colarr[i][j]="O"+to_string(x);
        if (colarr[i][j]==focus) loc={5, {i, j}};
    }
    // red
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) {
        int x=i*3+j;
        colarr[i+3][j]="R"+to_string(x);
        if (colarr[i+3][j]==focus) loc={2, {i, j}};
    }
    // purple
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) {
        int x=i*3+j;
        colarr[i+6][j]="P"+to_string(x);
        if (colarr[i+6][j]==focus) loc={6, {i, j}};
    }
    // blue
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) {
        int x=i*3+j;
        rowarr[i][j]="B"+to_string(x);
        if (rowarr[i][j]==focus) loc={1, {i, j}};
    }
    // red
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) {
        int x=i*3+j;
        rowarr[i][j+3]="R"+to_string(x);
        if (rowarr[i][j+3]==focus) loc={2, {i, j}};
    }
    // green
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) {
        int x=i*3+j;
        rowarr[i][j+6]="G"+to_string(x);
        if (rowarr[i][j+6]==focus) loc={3, {i, j}};
    }
    // yellow
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) {
        int x=i*3+j;
        rowarr[i][j+9]="Y"+to_string(x);
        if (rowarr[i][j+9]==focus) loc={4, {i, j}};
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string S; getline(cin, S);
    vector<string> v=tokenize(S);
    focus=v[0];
    initialize();

    for (int i=1; i<v.size(); i++) {
        char type=v[i][0], dir=v[i][1];
        int dis=v[i][2]-'0';

        if (type=='C') {
            if (dir=='C') {
                if (loc.f==6 || loc.f==2 || loc.f==5 || loc.f==4) {
                    string next[9];
                    for (int j=0; j<9; j++) next[j]=colarr[(j+dis)%9][loc.s.s];
                    for (int j=0; j<9; j++) colarr[j][loc.s.s]=next[j];
                    loc.s.f=(loc.s.f+dis)%9;
                    //loc.f=
                }
            }
            else {

            }
        }
    }

    for (int i=0; i<9; i++) {
        for (int j=0; j<3; j++) cout << colarr[i][j] << " ";
        cout << endl;
    }
    cout << loc.f << " " << loc.s.f << " " << loc.s.s << endl;
}



//P2 CC5
