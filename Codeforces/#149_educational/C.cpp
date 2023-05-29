#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define f first
#define s second
#define ll long long
#define MOD 1000000007

int main()
{
    int T; cin >> T;
    while (T--) {
        string seq; cin >> seq;
        int last_pos=-1;
        char last_char='c';
        vector<pair<pair<int, int>, char>> change;
        for (int i=0; i<seq.size(); i++) {
            if (seq[i]!='?' && i>0 && seq[i-1]=='?') {
                if (last_pos==-1) {
                    change.push_back(make_pair(make_pair(last_pos+1, i-1), seq[i]));
                }
                else {
                    if (last_char==seq[i]) change.push_back(make_pair(make_pair(last_pos+1, i-1), seq[i]));
                    else change.push_back(make_pair(make_pair(last_pos+1, i-1), '0'));
                }
            }
            if (seq[i]!='?') {
                last_char=seq[i];
                last_pos=i;
            }
        }

        if (seq[seq.size()-1]=='?') {
            if (last_pos==-1) change.push_back(make_pair(make_pair(last_pos+1, seq.size()-1), '0'));
            else change.push_back(make_pair(make_pair(last_pos+1, seq.size()-1), last_char));
        }

        for (auto chng: change) {
            for (int i=chng.f.f; i<=chng.f.s; i++) {
                seq[i]=chng.s;
            }
        }
        cout << seq << "\n";
    }
}

/*
1
????
*/