#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define f first
#define s second

int main()
{
    long long N, ans=0; cin >> N;
    stack <pair<int, int>> s;
    for (int i=0; i<N; i++) {
        int x; cin >> x;
        if (s.empty()) s.push({x, 1});
        else {
            while (true) {
                if (s.empty()) {
                    s.push({x, 1});
                    break;
                }
                if (s.top().f<x) {
                    ans+=s.top().s;
                    s.pop();
                }
                else if (s.top().f==x){
                    ans+=s.top().s;
                    int temp=s.top().s+1;
                    s.pop();
                    if (!s.empty()) ans++;
                    s.push({x, temp});
                    break;
                }
                else {
                    ans++;
                    s.push({x, 1});
                    break;
                }
            }
        }
    }
    cout << ans;
}

/*
5
1
2
2
2
1
*/
