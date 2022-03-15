#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

int s[1000005]={};
vector<int> loc[30];
string S, T;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> S >> T;
    for (int i=0; i<S.size(); i++) s[i]=S[i]-96;
    for (int i=0; i<T.size(); i++) {
        int a=T[i]-96;
        loc[a].push_back(i);
    }

    int minimum=0, cnt=1;
    for (int i=0; i<S.size(); i++) {
        //loc[s[i]] 에서 minimum보다 같거나 큰 애 찾기, minimum 업데이트
        if (loc[s[i]].empty()) {
            cout << -1;
            exit(0);
        }
        auto it=lower_bound(loc[s[i]].begin(), loc[s[i]].end(), minimum);
        if (it==loc[s[i]].end()) {
            cnt++;
            minimum=*loc[s[i]].begin()+1;
        }
        else minimum=*it+1;
    }
    cout << cnt;
}
