#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int c[1000005]={}; //소가 만드는 우유
pair <int, int> qp[1000005]; // 우유 구매 양, 구매 가격
int r[1000005]={}; //소 판매 가격.

bool cmp1 (pair<int, int> a, pair<int, int> b) {
    return a.second>b.second;
}

bool cmp2 (int a, int b) {
    return a>b;
}

int main()
{
    //freopen("rental.in", "r", stdin);
    //freopen("rental.out", "w", stdout);
    int N, M, R; cin >> N >> M >> R;
    for (int i=0; i<N; i++) cin >> c[i];
    for (int i=0; i<M; i++) cin >> qp[i].first >> qp[i].second; //willing to buy up to q gallons of milk for p cents per gallon
    for (int i=0; i<R; i++) cin >> r[i];

    sort(c, c+N);
    long long pfs=0;
    for (int i=0; i<N; i++) {
        pfs+=c[i];
        c[i]=pfs;
    }

    sort(qp, qp+M, cmp1);

    sort(r, r+R, cmp2);
    pfs=0;
    for (int i=0; i<R; i++) {
        pfs+=r[i];
        r[i]=pfs;
    }

    long long ans=0;
    long long extract=0;
    long long ri=0;


    for (int i=0; i<N; i++) {
        // i까지 소를 팔고, i부터 소를 짜기. 범위 조심.
        long long sell=r[min(R-1, i)];

        long long gallon=c[N-1]-c[i];

        

        /*
        while (true) {
            if (gallon-qp[ri].first<0 or ri==M) break;
            gallon-=qp[ri].first;
            extract+=qp[ri].first*qp[ri].second;
            ri++;
        }*/

        if (ri!=M) {
            extract+=gallon*qp[ri].second;
        }

        if (sell+extract>ans) ans=sell+extract;
    }
    cout << ans;
}

/*
5 3 4
6
2
4
7
1
10 25
2 10
15 15
250
80
100
40

1 0 1
2
19
*/
