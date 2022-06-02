#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define f first
#define s second
#define ll long long

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

struct Result {
    string word, match;
    int green=0, yellow=0, gv=0, flet=0, llet=0, order;
};

Result res[1005];
int idx=1;

bool cmp(Result a, Result b) {
    if (a.green==b.green && a.yellow==b.yellow && a.flet==b.flet && a.llet==b.llet && a.gv==b.gv) return a.order<b.order;
    else if (a.green==b.green && a.yellow==b.yellow && a.flet==b.flet && a.llet==b.llet) return a.gv>b.gv;
    else if (a.green==b.green && a.yellow==b.yellow && a.flet==b.flet) return a.llet>b.llet;
    else if (a.green==b.green && a.yellow==b.yellow) return a.flet>b.flet;
    else if (a.green==b.green) return a.yellow>b.yellow;
    return a.green>b.green;
}

string words[1005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string S; getline(cin, S);
    vector<string> v=tokenize(S);
    string target=v[0];

    for (int i=1; i<v.size(); i++) words[i]=v[i];
    sort(&words[1], &words[v.size()]);

    for (int i=1; i<v.size(); i++) {
        map<char, int> m;
        for (int i=0; i<5; i++) m[target[i]]++;

        string x=words[i], score="-----";
        for (int j=0; j<5; j++) {
            if (x[j]==target[j]) {
                score[j]='G';
                m[x[j]]--;
            }
        }
        for (int j=0; j<5; j++) {
            if (m[x[j]]>=1 && score[j]=='-') score[j]='Y';
        }

        if (score!="-----") {
            res[idx].word=x;
            res[idx].match=score;
            for (int j=0; j<5; j++) if (score[j]=='G') res[idx].green++;
            for (int j=0; j<5; j++) if (score[j]=='Y') res[idx].yellow++;
            if (score[0]=='G') res[idx].flet=1;
            if (score[4]=='G') res[idx].llet=1;
            for (int j=0; j<5; j++) {
                if (x[j]=='a' || x[j]=='e' || x[j]=='i' || x[j]=='o' || x[j]=='u') {
                    if (score[j]=='G') res[idx].gv++;
                }
            }
            res[idx].order=i;
            idx++;
        }
    }

    sort(&res[1], &res[idx], cmp);

    if (res[6].green==0 && res[6].yellow==0) {
        map<char, int> used;
        for (int i=1; i<v.size(); i++) {
            for (int j=0; j<5; j++) used[v[i][j]]++;
        }
        for (int i=97; i<=122; i++) if (used[i]==0) cout << (char)i;
    }
    else for (int i=1; i<=6; i++) cout << res[i].word << " ";
}

/*
bread reads breed dread reeds braid plead creed darts seeds leads arbor heads drape capes
*/
