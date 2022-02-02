#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX=3e5+5;
int D, N, sz[MAX]={}, pizza[MAX]={}, d[MAX]={};

int main()
{
    cin >> D >> N;
    for (int i=1; i<=D; i++) cin >> sz[i];
    for (int i=1; i<=N; i++) cin >> pizza[i];

    int mn=1e9;
    for (int i=1; i<=D; i++) {
        mn=min(mn, sz[i]);
        d[i]=mn;
    }

    int ind=D;
    for (int i=1; i<=N; i++) {
        while (ind>=1) {
            if (pizza[i]<=d[ind]) {
                if (i==N) {
                    cout << ind;
                    exit(0);
                }
                ind--;
                break;
            }
            else ind--;
        }
    }

    cout << "0";
}
