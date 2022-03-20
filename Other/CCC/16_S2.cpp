#include <iostream>
#include <algorithm>
using namespace std;

int Q, N, A[105], B[105];

void find_max() {
    int ret=0;
    for (int i=0; i<N; i++) {
        int speed=max(A[i], B[N-1-i]);
        ret+=speed;
    }
    cout << ret;
}

void find_min() {
    int ret=0;
    for (int i=0; i<N; i++) {
        int speed=max(A[i], B[i]);
        ret+=speed;
    }
    cout << ret;
}

int main()
{
    cin >> Q >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=0; i<N; i++) cin >> B[i];
    sort(A, A+N);
    sort(B, B+N);

    if (Q==1) find_min();
    else find_max();
}
