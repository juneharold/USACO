#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;
#define f first
#define s second

int dish[100005]={}, base[100005]={};
vector<int> stk[100005];
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> dish[i];

    int placed=0, ans=N;
    for (int i=1; i<=N; i++) {
        int x=dish[i];
        if (x<placed) {
            ans=i-1;
            break;
        }
        
        for (int j=x; j>=1; j--) {
            if (base[j]!=0) break;
            base[j]=x;
        }
        
        while (!stk[base[x]].empty()) {
            int end=stk[base[x]].back();
            if (dish[i]<end) break;
            else {
                placed=end;
                stk[base[x]].pop_back();
            }
        }
        stk[base[x]].push_back(x);
    }
    cout << ans;
}
