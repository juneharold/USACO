#include <iostream>
#include <set>
using namespace std;

int N, A[15][15], Visit[15];
string path;
set<string> cycleList;

string f(string s) {
    int minPos = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] < s[minPos]) {
            minPos = i;
        }
    }

    string ret = "";
    for (int i=0; i<s.size(); i++)
        ret += s[(minPos+i)%s.size()];

    return ret;
}

void dfs(int cur) {
    Visit[cur] = 1;
    path.push_back('A' + cur);

    for (int nxt=0; nxt<N; nxt++) {
        if (A[cur][nxt] == 1) {
            if (Visit[nxt] == 0) {
                dfs(nxt);
            } else if (path[0] == ('A' + nxt)) {
                // found cycle;
                cycleList.insert(f(path));
            }
        }
    }

    Visit[cur] = 0;
    path.pop_back();
}

int main() {
    cin >> N;

    for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
        cin >> A[i][j];
    }

    for (int i=0; i<N; i++) {
        dfs(i);
    }

    cout << "Number of cycles: " << cycleList.size() << "\n";
    for (string cycle : cycleList) {
        cout << cycle << "\n";
    }
}

/*
4
0 1 1 1
1 0 1 1
0 1 0 1
1 0 0 0

6
0 1 1 1 0 0
1 0 1 1 0 1
0 1 0 1 1 1
1 0 0 0 0 0
0 1 1 0 0 0
0 0 0 0 1 0
*/
