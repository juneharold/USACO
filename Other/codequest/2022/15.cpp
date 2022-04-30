#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long
#define db double

string s[1000];

int main()
{
    int T; cin >> T;
    while (T--) {
        map<string, db> d, t;
        int N; cin >> N;
        string temp; getline(cin, temp);
        for (int i=0; i<N; i++) getline(cin, s[i]);

        //double
        for (int i=0; i<N; i++) {
            for (int j=0; j<s[i].size()-1; j++) {
                string id="";
                if (65<=s[i][j] && s[i][j]<=90) {
                    id+=s[i][j];
                    if (65<=s[i][j+1] && s[i][j+1]<=90) id+=s[i][j+1];
                    else if (97<=s[i][j+1] && s[i][j+1]<=122) id+=s[i][j+1]-32;

                    if (id.size()==2) d[id]++;
                }
                else if (97<=s[i][j] && s[i][j]<=122) {
                    id+=s[i][j]-32;
                    if (65<=s[i][j+1] && s[i][j+1]<=90) id+=s[i][j+1];
                    else if (97<=s[i][j+1] && s[i][j+1]<=122) id+=s[i][j+1]-32;

                    if (id.size()==2) d[id]++;
                }
            }
        }

        db sum=0;
        for (auto x: d) sum+=x.s;
        for (auto x: d) {
            cout << x.f << ": ";
            printf("%.3lf", x.s/sum*100.000);
            cout << "%\n";
        }

        // tri
        for (int i=0; i<N; i++) {
            for (int j=0; j<s[i].size()-1; j++) {
                string id="";
                if (65<=s[i][j] && s[i][j]<=90) {
                    id+=s[i][j];
                    if (65<=s[i][j+1] && s[i][j+1]<=90) id+=s[i][j+1];
                    else if (97<=s[i][j+1] && s[i][j+1]<=122) id+=s[i][j+1]-32;

                    if (id.size()==2) d[id]++;
                }
                else if (97<=s[i][j] && s[i][j]<=122) {
                    id+=s[i][j]-32;
                    if (65<=s[i][j+1] && s[i][j+1]<=90) id+=s[i][j+1];
                    else if (97<=s[i][j+1] && s[i][j+1]<=122) id+=s[i][j+1]-32;

                    if (id.size()==2) d[id]++;
                }
            }
        }
    }
}

/*
1
3
The quick red fox jumps over the lazy brown dog.
The above sentence contains every letter in the English language.
Don’t forget to ignore punctuation and numbers; they’re not relevant!
*/
