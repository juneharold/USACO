/* c의 크기에 따라 정렬,
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

pair <long long, long long> rest[100005]; //first=c, second=x;
pair <long long, long long> stop[100005];

int main()
{
    //freopen("reststops.in", "r", stdin);
    //freopen("reststops.out", "w", stdout);
    long long L, N, rf, rb;
    cin >> L >> N >> rf >> rb;
    for (long long i=0; i<N; i++) {
        long long x, c; cin >> x >> c;
        rest[i]={c, x};
    }
    sort(rest, rest+N);
    long long prev=rest[N-1].second;
    stop[0].first=rest[N-1].first;
    stop[0].second=rest[N-1].second;
    long long ind=1;
    for (long long i=N-2; i>=0; i--) {
        if (rest[i].second>prev) {
            stop[ind].first=rest[i].first;
            stop[ind].second=rest[i].second;
            prev=rest[i].second;
            ind++;
        }
    }
    //stop에서는 무조건 멈춤.
    long long counter=0;
    long long bef=0;
    for (long long i=0; i<ind; i++) {
        /*
        전 스탑에서 현재 스탑까지의 거리-->bessie랑 john이 각각 걸리는 시간의 차 곱하기 c.
        */
        long long distance=stop[i].second-bef;
        long long time_diff=distance*(rf-rb);
        counter+=time_diff*stop[i].first;
        bef=stop[i].second;
    }
    cout << counter;
    return 0;
}

/*
10 2 4 3
7 2
8 1

10 4 2 1
1 10
2 9
3 8
4 6

10 4 2 1
1 9
2 10
3 8
4 6

10 4 2 1
1 1
2 2
3 2
4 1

10 4 10 1
1 1
2 1
3 2
4 1
*/
