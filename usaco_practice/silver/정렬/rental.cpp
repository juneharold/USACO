#include <iostream>
#include <algorithm>
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
    int N, M, R; cin >> N >> M >> R;
    for (int i=0; i<N; i++) cin >> c[i];
    for (int i=0; i<M; i++) cin >> qp[i].first >> qp[i].second;
    for (int i=0; i<R; i++) cin >> r[0];
    sort(c, c+N);
    sort(qp, qp+M, cmp1);
    sort(r, r+R, cmp2);
    long long money=0;
    int r_ind=0, qp_ind=0;
    for (int i=0; i<N; i++) {
        /*
            판매가와 추출 우유 비교하기.
            1) 우유 만들었을때 가격 찾기
        */
    }
}
