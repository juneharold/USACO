#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int A[200005]={};

int main()
{
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    int N; cin >> N;
    for (int i=1; i<=2*N; i++) cin >> A[i];
    ll d=0, cnt=0, change=0;
    for (int i=1; i<=N; i++) {
        if (A[i]==1) cnt++;
        else d+=cnt;
    }
    change-=cnt;
    cnt=0;
    for (int i=N+1; i<=2*N; i++) {
        if (A[i]==1) cnt++;
        else d-=cnt;
    }
    change+=N-cnt;
    
    ll ans=abs(d);
    // swap 0 1 --> 1 0 
    ll dd=d;
    vector<int> pos0, pos1;
    for (int i=1; i<=N; i++) if (A[i]==0) pos0.push_back(i);
    for (int i=2*N; i>=N+1; i--) if (A[i]==1) pos1.push_back(i);
    ll swaps=0;
    while (!(pos0.empty() || pos1.empty())) {
        dd+=N-pos0.back();
        swaps+=N-pos0.back();
        
        dd-=pos1.back()-(N+1);
        swaps+=pos1.back()-(N+1);

        dd+=change;
        pos0.pop_back();
        pos1.pop_back();
        swaps++;

        ans=min(ans, abs(dd)+swaps);
    }

    // swap 1 0 --> 0 1
    dd=d;
    pos0.clear(); pos1.clear();
    for (int i=1; i<=N; i++) if (A[i]==1) pos1.push_back(i);
    for (int i=2*N; i>=N+1; i--) if (A[i]==0) pos0.push_back(i);
    swaps=0; 
    while (!(pos0.empty() || pos1.empty())) {
        dd-=N-pos1.back();
        swaps+=N-pos1.back();
        
        dd+=pos0.back()-(N+1);
        swaps+=pos0.back()-(N+1);

        dd-=change;
        pos0.pop_back();
        pos1.pop_back();
        swaps++;

        ans=min(ans, abs(dd)+swaps);
    }
    cout << ans;
}