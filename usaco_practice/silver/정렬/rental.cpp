#include <iostream>
#include <algorithm>
using namespace std;

int c[100005]={}; //소가 만드는 우유
pair <long long, int> qp[100005]; // 우유 구매 양, 구매 가격
int r[100005]={}; //소 판매 가격.

bool cmp (pair <long long, int> a, pair <long long, int> b){
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
    qp[M+1]={(long long)1e15, 0};
    for (int i=0; i<R; i++) cin >> r[i];

    sort(c, c+N);
    sort(qp, qp+M, cmp);

    R = max(R, N);
    sort(r, r+R, cmp2);

    long long sum = 0, ans = 0;
    for (int i=0; i<N; ++i)
        sum += r[i];
    ans = sum;

    int bIdx = 0;
    for (int i=N-1; i>=0; --i) {
        sum -= r[i];
        long long left = c[i];
        while (left) {
            int use = min(left, qp[bIdx].first);
            sum += qp[bIdx].second * use;
            left -= use;
            qp[bIdx].first -= use;
            if (qp[bIdx].first == 0)
                bIdx++;
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
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
