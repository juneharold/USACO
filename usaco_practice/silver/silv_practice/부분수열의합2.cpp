#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define ll long long

int N, S, num[41]={}, half;
ll ans=0;
map<int, int> m;

void make_num1 (int cur, int ind) {
    if (ind==half) {
        m[cur]++;
        return;
    }
    make_num1(cur+num[ind], ind+1);
    make_num1(cur, ind+1);
}

void make_num2 (int cur, int ind) {
    if (ind==N) {
        ans+=m[S-cur];
        return;
    }
    make_num2(cur+num[ind], ind+1);
    make_num2(cur, ind+1);
}

int main()
{
    cin >> N >> S;
    for (int i=0; i<N; i++) cin >> num[i];

    half=N/2;

    make_num1(0, 0);
    make_num2(0, half);

    if (S==0) ans--;
    cout << ans;
}
