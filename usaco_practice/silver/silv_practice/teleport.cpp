#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, ans=1e18, sum=0;
struct event {
    long long pos, type;
};
vector<event> lis;
bool cmp(event A, event B) {
    return A.pos<B.pos;
}

int main()
{
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    cin >> N;
    for (long long i=0; i<N; i++) {
        long long a, b; cin >> a >> b;
        long long range=abs(b-a)-abs(a);
        if (range>0) {
            lis.push_back({b-range, 1});
            lis.push_back({b, 2});
            lis.push_back({b+range, 3});
        }
        sum+=abs(b-a);
    }

    sort(lis.begin(), lis.end(), cmp);

    long long change=0;
    for (long long i=0; i<lis.size(); i++) {
        if (change!=0) sum+=change*(lis[i].pos-lis[i-1].pos);
        ans=min(ans, sum);

        if (lis[i].type==1) change-=1;
        if (lis[i].type==2) change+=2;
        if (lis[i].type==3) change-=1;
    }

    cout << ans;
}
