#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long

int pfs[3][200005]={};
char word[200005]={};
map<char, int> mp;
string s;

int main()
{
    cin >> s;
    mp['C']=0;
    mp['O']=1;
    mp['W']=2;
    for (int i=0; i<s.size(); i++) {
        word[i+1]=mp[s[i]];
    }

    for (int i=0; i<3; i++) {
        for (int j=1; j<=s.size(); j++) {
            if (word[j]==i) pfs[i][j]=pfs[i][j-1]+1;
            else pfs[i][j]=pfs[i][j-1];
        }
    }

    int Q; cin >> Q;
    for (int i=0; i<Q; i++) {
        int a, b; cin >> a >> b;
        int c=(pfs[0][b]-pfs[0][a-1])%2;
        int o=(pfs[1][b]-pfs[1][a-1])%2;
        int w=(pfs[2][b]-pfs[2][a-1])%2;

        if (c==1 && o==0 && w==0) {
            cout << "Y";
        }
        else if (c==0 && o==1 && w==1) {
            cout << "Y";
        }
        else cout << "N";
    }
}
